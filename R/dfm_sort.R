#' Sort a dfm by frequency of one or more margins
#'
#' Sorts a [dfm] by descending frequency of total features, total features
#' in documents, or both.
#' @param x Document-feature matrix created by [dfm()]
#' @param margin which margin to sort on `features` to sort by frequency of
#'   features, `documents` to sort by total feature counts in documents,
#'   and `both` to sort by both
#' @param decreasing logical; if `TRUE`, the sort will be in descending
#'   order, otherwise sort in increasing order
#' @return A sorted [dfm] matrix object
#' @export
#' @author Ken Benoit
#' @examples
#' dfmat <- dfm(tokens(data_corpus_inaugural))
#' head(dfmat)
#' head(dfm_sort(dfmat))
#' head(dfm_sort(dfmat, decreasing = FALSE, "both"))
dfm_sort <- function(x, decreasing = TRUE,
                     margin = c("features", "documents", "both")) {
  UseMethod("dfm_sort")
}

#' @export
dfm_sort.default <- function(x, decreasing = TRUE,
                             margin = c(
