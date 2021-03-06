#include <Rcpp.h>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//

// [[Rcpp::export]]
int fibCpp(const int x) {
  if (x == 0) return 0;
  if (x == 1) return 1;
  return fibCpp(x - 1) + fibCpp(x - 2);
}

// extern "C" SEXP fib_wrapper(SEXP xs) {
//   int x = Rcpp::as<int>(xs);
//   int fib = fibCpp(x);
//   return (Rcpp::wrap(fib));
// }

