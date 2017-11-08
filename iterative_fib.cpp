#include <Rcpp.h>
#include <cmath>
using namespace Rcpp;

// [[Rcpp::export]]
double iter_fibCpp(const int x) {
  if (x < 0) return NAN;
  if (x < 2) return x;
  double first = 0.0;
  double second = 1.0;
  double third = 0.0;
  for (int i = 0; i < x; i++) {
    third = first + second;
    first = second;
    second = third;
  }
  return first;
}