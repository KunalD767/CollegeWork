data <- c(2.3, 1.5, 3.8, 4.1, 5.0, 2.1, 3.4, 1.8)
breaks <- seq(0, max(data), by=1)
observed_freq <- table(cut(data, breaks))
lambda <- 1 / mean(data)
expected_freq <- diff(pexp(breaks, rate=lambda)) * length(data)
chisq_test <- chisq.test(observed_freq, p=expected_freq/sum(expected_freq),
rescale.p=TRUE)
print(chisq_test)