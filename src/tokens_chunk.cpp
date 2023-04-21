#include "lib.h"
//#include "dev.h"
using namespace quanteda;

Texts chunk(Text &tokens,
            UintParam &N,
            const int size,
            const int overlap){
    
    if (tokens.size() == 0) return {}; // return empty vector for empty text
    
    std::size_t step;
    Texts chunks;
    step = size - overlap;
    chunks.reserve(ceil((double)tokens.size() / step));
    for (size_t i = 0; i < tokens.size(); i += step) {
        Text chunk(tokens.begin() + i, tokens.begin() + std::min(i + size, tokens.size()));
        chunks.push_back(chunk);
        N++;
    }
    return chunks;
}

/* 
 * Function to split documents
 * The number of threads is set by RcppParallel::setThreadOptions()
 * @used tokens_segment()
 * @creator Kohei Watanabe
 * @param size size of chunks
 * @param overlap number of tokens overlapping
 */

// [[Rcpp::export]]
TokensPtr cpp_tokens_chunk(TokensPtr xptr,
                           const int size,
                           const int overlap,
                           const int thread = -1) {
    
    Texts texts = xptr->texts;
    Types types = xptr->types;
    UintParam N = 0;
    // dev::Timer timer;
    std::size_t H = texts.size();
    std::vector<Texts> temp(texts.size());
#if QUANTEDA_USE_TBB
    tbb::task_arena arena(thread);
    arena.execute([&]{
        tbb::parallel_for(tbb::blocked_range<int>(0, H), [&](tbb::blocked_range<int> r) {
         for (int h = r.begin(); h < r.end(); ++h) {
             temp[h] = chunk(texts[h], N, size, overlap);
         }    
        });
    });
#else
    for (std::size_t h = 0; h < H; h++) {
        temp[h] = chunk(texts[h], N, size, overlap);
    }
#endif
    
    Texts chunks(N);
    std::vector<int> documents(N);
    
    std::size_t j = 0;
    for (std::size_t h = 0; h < temp.size(); h++) {
        for (size_t i = 0; i < temp[h].size(); i++) {
            chunks[j] = temp[h][i];
            documents[j] = (int)h + 1;
            j++;
        }
    }
    
    IntegerVector documents_ = Rcpp::wrap(documents);
    xptr.attr("documents") = documents_;
    xptr->texts = chunks;
    return xptr;
}

/***R

toks <- list(text1=1:10, text2=5:15)
#toks <- rep(list(rep(1:10, 1), rep(5:15, 1)), 100)
#dict <- list(c(1, 2), c(5, 6), 10, 15, 20)
out1 <- cpp_tokens_chunk(toks, letters, 2, 0)
out2 <- cpp_tokens_chunk(toks, letters, 2, 1)

out3 <- cpp_tokens_chunk(toks, letters, 2, 0)
out4 <- cpp_tokens_chunk(toks, letters, 2, 1)


*/
