# Generate 1000 samples from a normal distribution N(0, 1)
normal_samples <- rnorm(1000, mean = 0, sd = 1)

# Calculate PDF at x = 1
pdf_1 <- dnorm(1, mean = 0, sd = 1)
cat("PDF at x = 1:", round(pdf_1, 4), "\n")

# Calculate CDF at x = 1
cdf_1 <- pnorm(1, mean = 0, sd = 1)
cat("CDF at x = 1:", round(cdf_1, 4), "\n")

# Calculate 25th, 50th, and 75th quantiles
quantiles <- qnorm(c(0.25, 0.50, 0.75), mean = 0, sd = 1)
cat("Quantiles (25%, 50%, 75%):", round(quantiles, 4), "\n")

# Open a quartz window if on macOS to ensure plot appears
if (Sys.info()["sysname"] == "Darwin") quartz()

# Plot histogram of the generated samples
hist(normal_samples,
     main = "Histogram of Normal Distribution (N(0,1))",
     xlab = "Values",
     col = "lightgreen",
     breaks = 20,
     border = "white")

# Add vertical lines for mean and quantiles
abline(v = 0, col = "red", lwd = 2, lty = 2)  # Mean
abline(v = quantiles, col = "blue", lty = 3)

legend("topright",
       legend = c("Mean", "25%, 50%, 75% Quantiles"),
       col = c("red", "blue"),
       lty = c(2, 3),
       box.lty = 0)

# Pause for plot to render
Sys.sleep(10)