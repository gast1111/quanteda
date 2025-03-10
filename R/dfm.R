#' Create a document-feature matrix
#'
#' Construct a sparse document-feature matrix from a [tokens] or [dfm] object.
#' @param x a [tokens] or [dfm] object.
#' @param tolower convert all features to lowercase.
#' @param remove_padding logical; if `TRUE`, remove the "pads" left as empty tokens after
#' calling [tokens()] or [tokens_remove()] with `padding = TRUE`.
#' @param verbose display messages if `TRUE`.
#' @param ... not used.
#' @section Changes in version 3:
#' In \pkg{quanteda} v4, many convenience functions formerly available in
#' `dfm()` were removed.
#' @return a [dfm-class] object
#' @import Matrix
#' @export
#' @rdname dfm
#' @keywords dfm
#' @seealso  [dfm_select()], [dfm-class]
#' @examples
#' ## for a corpus
#' toks <- data_corpus_inaugural %>%
#'   corpus_subset(Year > 1980) %>%
#'   tokens()
#' dfm(toks)
#'
#' # removal options
#' toks <- tokens(c("a b c", "A B C D")) %>%
#'     tokens_remove("b", padding = TRUE)
#' toks
#' dfm(toks)
#' dfm(toks) %>%
#'  dfm_remove(pattern = "") # remove "pads"
#'
#' # preserving case
#' dfm(toks, tolower = FALSE)
dfm <- function(x,
                tolower = TRUE,
                remove_padding = FALSE,
                verbose = quanteda_options("verbose"),
                ...) {

    global$proc_time <- proc.time()
    if (is.null(global$object_class))
        global$object_class <- class(x)[1]
    UseMethod("dfm")
}

#' @export
dfm.default <- function(x, ...) {
    check_class(class(x), "dfm", defunct_methods = c("corpus", "character"))
}

#' @export
dfm.tokens <- function(x,
                       tolower = TRUE,
                       remove_padding = FALSE,
                       verbose = quanteda_options("verbose"),
                       ...) {

    dfm(as.tokens_xptr(x), tolower = tolower,
        remove_padding = remove_padding, verbose = verbose, ...)

}

#' @method dfm tokens_xptr
#' @export
dfm.tokens_xptr <- function(x,
                            tolower = TRUE,
                            remove_padding = FALSE,
                            verbose = quanteda_options("verbose"),
                            ...) {

    check_dots(...)
    if (verbose)
        catm("Creating a dfm from a", global$object_class, "object...\n")

    x <- as.tokens_xptr(x) # avoid modifying the original tokens
    if (tolower)
        x <- tokens_tolower(x)
    if (remove_padding)
        x <- tokens_remove(x, "", valuetype = "fixed")
    attrs <- attributes(x)
    temp <- t(cpp_dfm(x, attrs$meta$object$what == "dictionary"))
    result <- build_dfm(temp, colnames(temp),
                        docvars = get_docvars(x, user = TRUE, system = TRUE),
                        meta = attrs[["meta"]])

    if (verbose) {
        catm(" ...complete, elapsed time:",
             format((proc.time() - global$proc_time)[3], digits = 3), "seconds.\n")
        catm("Finished constructing a", paste(format(dim(result), big.mark = ",", trim = TRUE), collapse = " x "),
             "sparse dfm.\n")
    }
    global$object_class <- NULL
    return(result)
}



#' @importFrom stringi stri_trans_totitle
#' @export
dfm.dfm <- function(x,
                    tolower = TRUE,
                    remove_padding = FALSE,
                    verbose = quanteda_options("verbose"),
                    ...) {

    check_dots(...)
    x <- as.dfm(x)

    if (verbose)
        catm("Creating a dfm from a dfm object...\n")

    if (tolower) {
        if (verbose) catm(" ...lowercasing\n", sep = "")
        x <- dfm_tolower(x)
    }

    remove_padding <- check_logical(remove_padding)
    if (remove_padding)
        x <- dfm_remove(x, "", valuetype = "fixed")

    # remove any NA named columns
    is_na <- is.na(featnames(x))
    if (any(is_na))
        x <- x[, !is_na, drop = FALSE]

    if (verbose) {
        catm(" ...complete, elapsed time:",
             format((proc.time() - global$proc_time)[3], digits = 3), "seconds.\n")
        catm("Finished constructing a", paste(format(dim(x), big.mark = ",", trim = TRUE), collapse = " x "),
             "sparse dfm.\n")
    }

    return(x)
}

# utility functions -----------

# create an empty dfm for given features and documents
make_null_dfm <- function(feature = NULL, document = NULL) {
    if (is.null(feature)) feature <- character()
    if (is.null(document)) document <- character()
    temp <- as(as(as(sparseMatrix(
        i = NULL,
        j = NULL,
        dims = c(length(document), length(feature))
    ), "CsparseMatrix"), "generalMatrix"), "dMatrix")

    build_dfm(temp, feature,
              docvars = make_docvars(length(document), document))
}

# pad dfm with zero-count features
pad_dfm <- function(x, feature) {
    feat_pad <- setdiff(feature, featnames(x))
    if (length(feat_pad)) {
        suppressWarnings(
            x <- cbind(x, make_null_dfm(feat_pad, docnames(x)))
        )
    }
    x <- x[, match(feature, featnames(x))]
    return(x)
}

# defunct methods -------------

#' @export
dfm.character <- function(x, ...) {
    .Defunct(msg = "'dfm.character()' was removed in v4. Use 'tokens()' first.")
}

#' @export
dfm.corpus <- function(x, ...) {
    .Defunct(msg = "'dfm.corpus()' was removed in v4. Use 'tokens()' first.")
}
