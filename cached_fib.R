cached_fibR <- local({
  cache <- c(1, 1, rep(NA, 1000))
  f <- function(n) {
    if (n < 0) return(NA)
    if (n > length(cache)) stop("Cannot process for n greater than 1000.")
    if (n == 0) return(0)
    if (n == 1) return(1)
    if (!is.na(cache[n])) return(cache[n])
    ans <- f(n - 1) + f(n - 2)
    cache[n] <<- ans
    ans
  }
})