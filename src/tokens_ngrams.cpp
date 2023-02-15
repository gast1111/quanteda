#include "tokens.h"
#include "skipgram.h"
//#include "dev.h"
using namespace quanteda;

Text skipgram(const Text &tokens,
              const std::vector<unsigned int> &ns, 
              const std::vector<unsigned int> &skips,
              MapNgrams &map_ngram,
              IdNgram &id_ngram) {
    
    if (tokens.size() == 0) return {}; // return empty vector for empty text
    
    // Pre-allocate memory
    int size_reserve = 0;
    for (std::size_t k = 0; k < ns.size(); k++) {
        size_reserve += std::pow(skips.size(), ns[k]) * tokens.size();
    }
    Text tokens_ng;
    tokens_ng.reserve(size_reserve);
    SetNgrams set_words; // keep empty
    
    // Generate skipgrams recursively
    for (std::size_t k = 0; k < ns.size(); k++) {
        unsigned int n = ns[k];
        if (tokens.size() < n) continue;
        Ngram ngram;
        ngram.reserve(n);
        for (std::size_t start = 0; start < tokens.size() - (n - 1); start++) {
            if(tokens[start] == 0) continue; // skip padding
            skip(tokens, tokens_ng, set_words, start, n, skips, ngram, map_ngram, id_ngram); // Get ngrams as reference
        }
    }
    return tokens_ng;
}

struct skipgram_mt : public Worker{
    
    Texts &texts;
    const std::vector<unsigned int> &ns;
    const std::vector<unsigned int> &skips;
    MapNgrams &map_ngram;
    IdNgram &id_ngram;
    
    skipgram_mt(Texts &texts_, const std::vector<unsigned int> &ns_, const std::vector<unsigned int> &skips_, 
                MapNgrams &map_ngram_, IdNgram &id_ngram_):
                texts(texts_), ns(ns_), skips(skips_), map_ngram(map_ngram_), id_ngram(id_ngram_){}
    
    void operator()(std::size_t begin, std::size_t end){
        //Rcout << "Range " << begin << " " << end << "\n";
        for (std::size_t h = begin; h < end; h++) {
            texts[h] = skipgram(texts[h], ns, skips, map_ngram, id_ngram);
        }
    }
};


void type(std::size_t i,
          const VecNgrams &keys_ngram,
          Types &types_ngram,
          const MapNgrams &map_ngram,
          const std::string &delim,
          const Types &types){
    
    Ngram key = keys_ngram[i];
    if (key.size() == 0) {
        types_ngram[i] = "";
    } else {
        std::string type_ngram = types[key[0] - 1];
        for (std::size_t j = 1; j < key.size(); j++) {
            type_ngram += delim + types[key[j] - 1];
        }
        types_ngram[i] = type_ngram;
    }
}

struct type_mt : public Worker{
    
    const VecNgrams &keys_ngram;
    Types &types_ngram;
    const MapNgrams &map_ngram;
    const std::string &delim;
    const Types &types;
    
    type_mt(VecNgrams &keys_ngram_, Types &types_ngram_, MapNgrams &map_ngram_, 
            std::string &delim_, Types &types_):
            keys_ngram(keys_ngram_), types_ngram(types_ngram_), map_ngram(map_ngram_), 
            delim(delim_), types(types_) {}
    
    void operator()(std::size_t begin, std::size_t end){
        //Rcout << "Range " << begin << " " << end << "\n";
        for (std::size_t i = begin; i < end; i++) {
            type(i, keys_ngram, types_ngram, map_ngram, delim, types);
        }
    }
};


/* 
* Function to generates ngrams/skipgrams
* The number of threads is set by RcppParallel::setThreadOptions()
* @used tokens_ngrams()
* @creator Kohei Watanabe
* @param delim_ string to join words
* @param ns_ size of ngramss
* @param skips_ size of skip (this has to be 1 for ngrams)
* 
*/

// [[Rcpp::export]]
TokensPtr cpp_tokens_ngrams(TokensPtr xptr,
                            const String delim_,
                            const IntegerVector ns_,
                            const IntegerVector skips_) {
    
    Texts texts = xptr->texts;
    Types types = xptr->types;
    std::string delim = delim_;
    std::vector<unsigned int> ns = Rcpp::as< std::vector<unsigned int> >(ns_);
    std::vector<unsigned int> skips = Rcpp::as< std::vector<unsigned int> >(skips_);
    
    // Register both ngram (key) and unigram (value) IDs in a hash table
    MapNgrams map_ngram;
    map_ngram.max_load_factor(GLOBAL_NGRAMS_MAX_LOAD_FACTOR);
    
    //dev::Timer timer;
    //dev::start_timer("Ngram generation", timer);
#if QUANTEDA_USE_TBB
    IdNgram id_ngram(1);
    skipgram_mt skipgram_mt(texts, ns, skips, map_ngram, id_ngram);
    parallelFor(0, texts.size(), skipgram_mt);
#else
    IdNgram id_ngram = 1;
    for (std::size_t h = 0; h < texts.size(); h++) {
        texts[h] = skipgram(texts[h], ns, skips, map_ngram, id_ngram);
    }
#endif
    //dev::stop_timer("Ngram generation", timer);
    
    // Extract only keys in order of the id
    VecNgrams keys_ngram(id_ngram - 1);
    for (std::pair<Ngram, unsigned int> it : map_ngram) {
        keys_ngram[it.second - 1] = it.first;
    }
    
    //dev::start_timer("Token generation", timer);
    // Create ngram types
    Types types_ngram(keys_ngram.size());
#if QUANTEDA_USE_TBB
        type_mt type_mt(keys_ngram, types_ngram, map_ngram, delim, types);
        parallelFor(0, types_ngram.size(), type_mt);
#else
    for (std::size_t i = 0; i < types_ngram.size(); i++) {
        type(i, keys_ngram, types_ngram, map_ngram, delim, types);
    }
#endif
    
    xptr->texts = texts;
    xptr->types = types_ngram;
    xptr->has_gap = true;
    xptr->has_dup = true;
    return xptr;

}




/*** R

library(quanteda)
#txt <- c('a b c d e')
txt <- c('a b c d e', 'c d e f g')
tok <- quanteda::tokens(txt)
out <- cpp_tokens_ngrams(tok, attr(tok, 'types'), "-", 2, 1)
str(out)

tok2 <- quanteda::tokens(data_corpus_inaugural)
microbenchmark::microbenchmark(
    cpp_tokens_ngrams(tok2, attr(tok2, 'types'), "-", 2, 1),
    tokenizers::tokenize_ngrams(texts(data_corpus_inaugural))
)




*/

