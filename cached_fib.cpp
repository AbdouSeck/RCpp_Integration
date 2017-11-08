#include <Rcpp.h>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <iostream>
using namespace Rcpp;


class Fib {
  public:
    Fib(unsigned int n = 1000) {
      cache.resize(n);
      std::fill(cache.begin(), cache.end(), NAN);
      cache[0] = 0.0;
      cache[1] = 1.0;
    }
    double cached_fibCpp(int x) {
      if (x < 0) {
        return (double) NAN;
      }
      if (x >= (int) cache.size()) {
        throw std::range_error("x too large for implementation");
      }
      if (x < 2) {
        return x;
      }
      if (! ::isnan(cache[x])) return cache[x];
      cache[x] = cached_fibCpp(x - 1) + cached_fibCpp(x - 2);
      return cache[x];
      
    }
  private:
    std::vector<double> cache;
};

Fib f = Fib(2000);

// [[Rcpp::export]]
double cached_fibCpp(const int a) {
  return f.cached_fibCpp(a);
}