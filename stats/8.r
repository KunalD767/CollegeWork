# Constructing box-shaped data
data <- c(1, 2, 3, 3, 3, 5, 5, 5, 5, 5, 7, 7, 7, 8, 9, 20, 25)

# Mean and standard deviation
mean_val <- mean(data)
std_dev <- sd(data)

# Show the boxplot
quartz()
boxplot(data,
        main = "Boxplot with Visually Balanced Distribution",
        ylab = "Value",
        col = "lightblue",
        border = "darkblue")

Sys.sleep(5)  # Pause to let the plot render

# Print Z-scores and outlier status
cat("Value  Z-Score    Outlier\n")
for (i in 1:length(data)) {
  z <- (data[i] - mean_val) / std_dev
  is_outlier <- abs(z) > 3
  cat(data[i], "   ", round(z, 3), "    ", is_outlier, "\n")
}