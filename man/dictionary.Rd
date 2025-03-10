% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/dictionaries.R
\name{dictionary}
\alias{dictionary}
\title{Create a dictionary}
\usage{
dictionary(
  x,
  file = NULL,
  format = NULL,
  separator = " ",
  tolower = TRUE,
  encoding = "utf-8"
)
}
\arguments{
\item{x}{a named list of character vector dictionary entries, including
\link{valuetype} pattern matches, and including multi-word expressions
separated by \code{concatenator}.  See examples. This argument may be
omitted if the dictionary is read from \code{file}.}

\item{file}{file identifier for a foreign dictionary}

\item{format}{character identifier for the format of the foreign dictionary.
If not supplied, the format is guessed from the dictionary file's
extension. Available options are: \describe{
\item{\code{"wordstat"}}{format used by Provalis Research's WordStat
software} \item{\code{"LIWC"}}{format used by the Linguistic Inquiry and
Word Count software} \item{\code{"yoshikoder"}}{ format used by Yoshikoder
software} \item{\code{"lexicoder"}}{format used by Lexicoder}
\item{\code{"YAML"}}{the standard YAML format}}}

\item{separator}{the character in between multi-word dictionary values. This
defaults to \code{" "}.}

\item{tolower}{if \code{TRUE}, convert all dictionary values to lowercase}

\item{encoding}{additional optional encoding value for reading in imported
dictionaries. This uses the \link{iconv} labels for encoding.  See the
"Encoding" section of the help for \link{file}.}
}
\value{
A dictionary class object, essentially a specially classed named list
of characters.
}
\description{
Create a \pkg{quanteda} dictionary class object, either from a list or by
importing from a foreign format.  Currently supported input file formats are
the WordStat, LIWC, Lexicoder v2 and v3, and Yoshikoder formats.  The import
using the LIWC format works with all currently available dictionary files
supplied as part of the LIWC 2001, 2007, and 2015 software (see References).
}
\details{
Dictionaries can be subsetted using
\code{\link[=dictionary2-class]{[}} and
\code{\link[=dictionary2-class]{[[}}, operating the same as the equivalent
\link[=dictionary2-class]{list} operators.

Dictionaries can be coerced from lists using \code{\link[=as.dictionary]{as.dictionary()}},
coerced to named lists of characters using
\code{\link[=dictionary2-class]{as.list()}}, and checked using
\code{\link[=is.dictionary]{is.dictionary()}}.
}
\examples{
corp <- corpus_subset(data_corpus_inaugural, Year>1900)
dict <- dictionary(list(christmas = c("Christmas", "Santa", "holiday"),
                          opposition = c("Opposition", "reject", "notincorpus"),
                          taxing = "taxing",
                          taxation = "taxation",
                          taxregex = "tax*",
                          country = "america"))
head(dfm(tokens(corp), dictionary = dict))

# subset a dictionary
dict[1:2]
dict[c("christmas", "opposition")]
dict[["opposition"]]

# combine dictionaries
c(dict["christmas"], dict["country"])

\dontrun{
dfmat <- dfm(tokens(data_corpus_inaugural))

# import the Laver-Garry dictionary from Provalis Research
dictfile <- tempfile()
download.file("https://provalisresearch.com/Download/LaverGarry.zip",
              dictfile, mode = "wb")
unzip(dictfile, exdir = (td <- tempdir()))
dictlg <- dictionary(file = paste(td, "LaverGarry.cat", sep = "/"))
head(dfm_lookup(dfmat), dictlg)

# import a LIWC formatted dictionary from http://www.moralfoundations.org
download.file("http://bit.ly/37cV95h", tf <- tempfile())
dictliwc <- dictionary(file = tf, format = "LIWC")
head(dfm_lookup(dfmat), dictliwc)
}
}
\references{
WordStat dictionaries page, from Provalis Research
\url{https://provalisresearch.com/products/content-analysis-software/wordstat-dictionary/}.

Pennebaker, J.W., Chung, C.K., Ireland, M., Gonzales, A., & Booth, R.J.
(2007). The development and psychometric properties of LIWC2007. [Software
manual]. Austin, TX (\url{https://www.liwc.app/}).

Yoshikoder page, from Will Lowe
\url{https://conjugateprior.org/software/yoshikoder/}.

Lexicoder format, \url{https://www.snsoroka.com/data-lexicoder/}
}
\seealso{
\code{\link[=as.dictionary]{as.dictionary()}},
\code{\link[=dictionary2-class]{as.list()}}, \code{\link[=is.dictionary]{is.dictionary()}}
}
