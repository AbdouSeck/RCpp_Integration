iter_fibR <- function(x) {
  if (x < 0) return(NA)
  if (x < 2) return(x)
  first <- 0
  second <- 1
  third <- 0
  for (i in seq_len(x)) {
    third <- first + second
    first <- second
    second <- third
  }
  first
}