// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "quanteda_types.h"
#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// cpp_fcm
S4 cpp_fcm(TokensPtr xptr, const int n_types, const NumericVector& weights_, const bool boolean, const bool ordered);
RcppExport SEXP _quanteda_cpp_fcm(SEXP xptrSEXP, SEXP n_typesSEXP, SEXP weights_SEXP, SEXP booleanSEXP, SEXP orderedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< const int >::type n_types(n_typesSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type weights_(weights_SEXP);
    Rcpp::traits::input_parameter< const bool >::type boolean(booleanSEXP);
    Rcpp::traits::input_parameter< const bool >::type ordered(orderedSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_fcm(xptr, n_types, weights_, boolean, ordered));
    return rcpp_result_gen;
END_RCPP
}
// cpp_index
DataFrame cpp_index(TokensPtr xptr, const List& words_);
RcppExport SEXP _quanteda_cpp_index(SEXP xptrSEXP, SEXP words_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< const List& >::type words_(words_SEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_index(xptr, words_));
    return rcpp_result_gen;
END_RCPP
}
// cpp_tokens_chunk
TokensPtr cpp_tokens_chunk(TokensPtr xptr, const int size, const int overlap);
RcppExport SEXP _quanteda_cpp_tokens_chunk(SEXP xptrSEXP, SEXP sizeSEXP, SEXP overlapSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< const int >::type size(sizeSEXP);
    Rcpp::traits::input_parameter< const int >::type overlap(overlapSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_tokens_chunk(xptr, size, overlap));
    return rcpp_result_gen;
END_RCPP
}
// cpp_tokens_combine
TokensPtr cpp_tokens_combine(TokensPtr xptr1, TokensPtr xptr2);
RcppExport SEXP _quanteda_cpp_tokens_combine(SEXP xptr1SEXP, SEXP xptr2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr1(xptr1SEXP);
    Rcpp::traits::input_parameter< TokensPtr >::type xptr2(xptr2SEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_tokens_combine(xptr1, xptr2));
    return rcpp_result_gen;
END_RCPP
}
// cpp_tokens_compound
TokensPtr cpp_tokens_compound(TokensPtr xptr, const List& compounds_, const String& delim_, const bool& join, int window_left, int window_right);
RcppExport SEXP _quanteda_cpp_tokens_compound(SEXP xptrSEXP, SEXP compounds_SEXP, SEXP delim_SEXP, SEXP joinSEXP, SEXP window_leftSEXP, SEXP window_rightSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< const List& >::type compounds_(compounds_SEXP);
    Rcpp::traits::input_parameter< const String& >::type delim_(delim_SEXP);
    Rcpp::traits::input_parameter< const bool& >::type join(joinSEXP);
    Rcpp::traits::input_parameter< int >::type window_left(window_leftSEXP);
    Rcpp::traits::input_parameter< int >::type window_right(window_rightSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_tokens_compound(xptr, compounds_, delim_, join, window_left, window_right));
    return rcpp_result_gen;
END_RCPP
}
// cpp_tokens_group
TokensPtr cpp_tokens_group(TokensPtr xptr, IntegerVector groups_);
RcppExport SEXP _quanteda_cpp_tokens_group(SEXP xptrSEXP, SEXP groups_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type groups_(groups_SEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_tokens_group(xptr, groups_));
    return rcpp_result_gen;
END_RCPP
}
// cpp_tokens_lookup
TokensPtr cpp_tokens_lookup(TokensPtr xptr, const List& words_, const IntegerVector& keys_, const CharacterVector& types_, const int overlap, const int nomatch);
RcppExport SEXP _quanteda_cpp_tokens_lookup(SEXP xptrSEXP, SEXP words_SEXP, SEXP keys_SEXP, SEXP types_SEXP, SEXP overlapSEXP, SEXP nomatchSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< const List& >::type words_(words_SEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type keys_(keys_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector& >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const int >::type overlap(overlapSEXP);
    Rcpp::traits::input_parameter< const int >::type nomatch(nomatchSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_tokens_lookup(xptr, words_, keys_, types_, overlap, nomatch));
    return rcpp_result_gen;
END_RCPP
}
// cpp_tokens_ngrams
TokensPtr cpp_tokens_ngrams(TokensPtr xptr, const String delim_, const IntegerVector ns_, const IntegerVector skips_);
RcppExport SEXP _quanteda_cpp_tokens_ngrams(SEXP xptrSEXP, SEXP delim_SEXP, SEXP ns_SEXP, SEXP skips_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< const String >::type delim_(delim_SEXP);
    Rcpp::traits::input_parameter< const IntegerVector >::type ns_(ns_SEXP);
    Rcpp::traits::input_parameter< const IntegerVector >::type skips_(skips_SEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_tokens_ngrams(xptr, delim_, ns_, skips_));
    return rcpp_result_gen;
END_RCPP
}
// cpp_tokens_recompile
List cpp_tokens_recompile(const List& texts_, const CharacterVector types_, const bool gap, const bool dup);
RcppExport SEXP _quanteda_cpp_tokens_recompile(SEXP texts_SEXP, SEXP types_SEXP, SEXP gapSEXP, SEXP dupSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List& >::type texts_(texts_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector >::type types_(types_SEXP);
    Rcpp::traits::input_parameter< const bool >::type gap(gapSEXP);
    Rcpp::traits::input_parameter< const bool >::type dup(dupSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_tokens_recompile(texts_, types_, gap, dup));
    return rcpp_result_gen;
END_RCPP
}
// cpp_tokens_replace
TokensPtr cpp_tokens_replace(TokensPtr xptr, const List& patterns_, const List& replacements_);
RcppExport SEXP _quanteda_cpp_tokens_replace(SEXP xptrSEXP, SEXP patterns_SEXP, SEXP replacements_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< const List& >::type patterns_(patterns_SEXP);
    Rcpp::traits::input_parameter< const List& >::type replacements_(replacements_SEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_tokens_replace(xptr, patterns_, replacements_));
    return rcpp_result_gen;
END_RCPP
}
// cpp_tokens_segment
TokensPtr cpp_tokens_segment(TokensPtr xptr, const List& patterns_, const bool& remove, const int& position);
RcppExport SEXP _quanteda_cpp_tokens_segment(SEXP xptrSEXP, SEXP patterns_SEXP, SEXP removeSEXP, SEXP positionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< const List& >::type patterns_(patterns_SEXP);
    Rcpp::traits::input_parameter< const bool& >::type remove(removeSEXP);
    Rcpp::traits::input_parameter< const int& >::type position(positionSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_tokens_segment(xptr, patterns_, remove, position));
    return rcpp_result_gen;
END_RCPP
}
// cpp_tokens_select
TokensPtr cpp_tokens_select(TokensPtr xptr, const List& words_, int mode, bool padding, int window_left, int window_right, const IntegerVector pos_from_, const IntegerVector pos_to_);
RcppExport SEXP _quanteda_cpp_tokens_select(SEXP xptrSEXP, SEXP words_SEXP, SEXP modeSEXP, SEXP paddingSEXP, SEXP window_leftSEXP, SEXP window_rightSEXP, SEXP pos_from_SEXP, SEXP pos_to_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< const List& >::type words_(words_SEXP);
    Rcpp::traits::input_parameter< int >::type mode(modeSEXP);
    Rcpp::traits::input_parameter< bool >::type padding(paddingSEXP);
    Rcpp::traits::input_parameter< int >::type window_left(window_leftSEXP);
    Rcpp::traits::input_parameter< int >::type window_right(window_rightSEXP);
    Rcpp::traits::input_parameter< const IntegerVector >::type pos_from_(pos_from_SEXP);
    Rcpp::traits::input_parameter< const IntegerVector >::type pos_to_(pos_to_SEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_tokens_select(xptr, words_, mode, padding, window_left, window_right, pos_from_, pos_to_));
    return rcpp_result_gen;
END_RCPP
}
// cpp_as_xptr
TokensPtr cpp_as_xptr(const List text_, const CharacterVector types_);
RcppExport SEXP _quanteda_cpp_as_xptr(SEXP text_SEXP, SEXP types_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const List >::type text_(text_SEXP);
    Rcpp::traits::input_parameter< const CharacterVector >::type types_(types_SEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_as_xptr(text_, types_));
    return rcpp_result_gen;
END_RCPP
}
// cpp_copy_xptr
TokensPtr cpp_copy_xptr(TokensPtr xptr);
RcppExport SEXP _quanteda_cpp_copy_xptr(SEXP xptrSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_copy_xptr(xptr));
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_attributes
List cpp_get_attributes(TokensPtr xptr);
RcppExport SEXP _quanteda_cpp_get_attributes(SEXP xptrSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_get_attributes(xptr));
    return rcpp_result_gen;
END_RCPP
}
// cpp_as_list
List cpp_as_list(TokensPtr xptr);
RcppExport SEXP _quanteda_cpp_as_list(SEXP xptrSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_as_list(xptr));
    return rcpp_result_gen;
END_RCPP
}
// cpp_subset
TokensPtr cpp_subset(TokensPtr xptr, IntegerVector index_);
RcppExport SEXP _quanteda_cpp_subset(SEXP xptrSEXP, SEXP index_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type index_(index_SEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_subset(xptr, index_));
    return rcpp_result_gen;
END_RCPP
}
// cpp_ndoc
int cpp_ndoc(TokensPtr xptr);
RcppExport SEXP _quanteda_cpp_ndoc(SEXP xptrSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_ndoc(xptr));
    return rcpp_result_gen;
END_RCPP
}
// cpp_ntoken
IntegerVector cpp_ntoken(TokensPtr xptr);
RcppExport SEXP _quanteda_cpp_ntoken(SEXP xptrSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_ntoken(xptr));
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_types
CharacterVector cpp_get_types(TokensPtr xptr, bool recompile);
RcppExport SEXP _quanteda_cpp_get_types(SEXP xptrSEXP, SEXP recompileSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< bool >::type recompile(recompileSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_get_types(xptr, recompile));
    return rcpp_result_gen;
END_RCPP
}
// cpp_set_types
TokensPtr cpp_set_types(TokensPtr xptr, const CharacterVector types_);
RcppExport SEXP _quanteda_cpp_set_types(SEXP xptrSEXP, SEXP types_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< const CharacterVector >::type types_(types_SEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_set_types(xptr, types_));
    return rcpp_result_gen;
END_RCPP
}
// cpp_recompile
void cpp_recompile(TokensPtr xptr);
RcppExport SEXP _quanteda_cpp_recompile(SEXP xptrSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    cpp_recompile(xptr);
    return R_NilValue;
END_RCPP
}
// cpp_dfm
S4 cpp_dfm(TokensPtr xptr);
RcppExport SEXP _quanteda_cpp_dfm(SEXP xptrSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< TokensPtr >::type xptr(xptrSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_dfm(xptr));
    return rcpp_result_gen;
END_RCPP
}
// cpp_is_grouped_numeric
bool cpp_is_grouped_numeric(NumericVector values_, IntegerVector groups_);
RcppExport SEXP _quanteda_cpp_is_grouped_numeric(SEXP values_SEXP, SEXP groups_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type values_(values_SEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type groups_(groups_SEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_is_grouped_numeric(values_, groups_));
    return rcpp_result_gen;
END_RCPP
}
// cpp_is_grouped_character
bool cpp_is_grouped_character(CharacterVector values_, IntegerVector groups_);
RcppExport SEXP _quanteda_cpp_is_grouped_character(SEXP values_SEXP, SEXP groups_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type values_(values_SEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type groups_(groups_SEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_is_grouped_character(values_, groups_));
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_load_factor
List cpp_get_load_factor();
RcppExport SEXP _quanteda_cpp_get_load_factor() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_get_load_factor());
    return rcpp_result_gen;
END_RCPP
}
// cpp_set_meta
void cpp_set_meta(RObject object_, RObject meta_);
RcppExport SEXP _quanteda_cpp_set_meta(SEXP object_SEXP, SEXP meta_SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< RObject >::type object_(object_SEXP);
    Rcpp::traits::input_parameter< RObject >::type meta_(meta_SEXP);
    cpp_set_meta(object_, meta_);
    return R_NilValue;
END_RCPP
}
// cpp_tbb_enabled
bool cpp_tbb_enabled();
RcppExport SEXP _quanteda_cpp_tbb_enabled() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_tbb_enabled());
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_quanteda_cpp_fcm", (DL_FUNC) &_quanteda_cpp_fcm, 5},
    {"_quanteda_cpp_index", (DL_FUNC) &_quanteda_cpp_index, 2},
    {"_quanteda_cpp_tokens_chunk", (DL_FUNC) &_quanteda_cpp_tokens_chunk, 3},
    {"_quanteda_cpp_tokens_combine", (DL_FUNC) &_quanteda_cpp_tokens_combine, 2},
    {"_quanteda_cpp_tokens_compound", (DL_FUNC) &_quanteda_cpp_tokens_compound, 6},
    {"_quanteda_cpp_tokens_group", (DL_FUNC) &_quanteda_cpp_tokens_group, 2},
    {"_quanteda_cpp_tokens_lookup", (DL_FUNC) &_quanteda_cpp_tokens_lookup, 6},
    {"_quanteda_cpp_tokens_ngrams", (DL_FUNC) &_quanteda_cpp_tokens_ngrams, 4},
    {"_quanteda_cpp_tokens_recompile", (DL_FUNC) &_quanteda_cpp_tokens_recompile, 4},
    {"_quanteda_cpp_tokens_replace", (DL_FUNC) &_quanteda_cpp_tokens_replace, 3},
    {"_quanteda_cpp_tokens_segment", (DL_FUNC) &_quanteda_cpp_tokens_segment, 4},
    {"_quanteda_cpp_tokens_select", (DL_FUNC) &_quanteda_cpp_tokens_select, 8},
    {"_quanteda_cpp_as_xptr", (DL_FUNC) &_quanteda_cpp_as_xptr, 2},
    {"_quanteda_cpp_copy_xptr", (DL_FUNC) &_quanteda_cpp_copy_xptr, 1},
    {"_quanteda_cpp_get_attributes", (DL_FUNC) &_quanteda_cpp_get_attributes, 1},
    {"_quanteda_cpp_as_list", (DL_FUNC) &_quanteda_cpp_as_list, 1},
    {"_quanteda_cpp_subset", (DL_FUNC) &_quanteda_cpp_subset, 2},
    {"_quanteda_cpp_ndoc", (DL_FUNC) &_quanteda_cpp_ndoc, 1},
    {"_quanteda_cpp_ntoken", (DL_FUNC) &_quanteda_cpp_ntoken, 1},
    {"_quanteda_cpp_get_types", (DL_FUNC) &_quanteda_cpp_get_types, 2},
    {"_quanteda_cpp_set_types", (DL_FUNC) &_quanteda_cpp_set_types, 2},
    {"_quanteda_cpp_recompile", (DL_FUNC) &_quanteda_cpp_recompile, 1},
    {"_quanteda_cpp_dfm", (DL_FUNC) &_quanteda_cpp_dfm, 1},
    {"_quanteda_cpp_is_grouped_numeric", (DL_FUNC) &_quanteda_cpp_is_grouped_numeric, 2},
    {"_quanteda_cpp_is_grouped_character", (DL_FUNC) &_quanteda_cpp_is_grouped_character, 2},
    {"_quanteda_cpp_get_load_factor", (DL_FUNC) &_quanteda_cpp_get_load_factor, 0},
    {"_quanteda_cpp_set_meta", (DL_FUNC) &_quanteda_cpp_set_meta, 2},
    {"_quanteda_cpp_tbb_enabled", (DL_FUNC) &_quanteda_cpp_tbb_enabled, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_quanteda(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
