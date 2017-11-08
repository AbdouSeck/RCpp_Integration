lapply(c("Rcpp", "microbenchmark"), function(pkg) {
  if (!require(pkg, character.only = T)) {
    install.packages(pkg)
  } else {
    sprintf("Package %s is already installed and loaded.", pkg)
  }
})

setwd('~/Documents/Personal/Data_Analysis/R/RCpp_Integration/')

# Get the R functions
source('recursive_fib.R')
source('cached_fib.R')
source('iterative_fib.R')

# Get the cpp functions
sourceCpp('recursive_fib.cpp')
sourceCpp('cached_fib.cpp')
sourceCpp('iterative_fib.cpp')