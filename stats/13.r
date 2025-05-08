# Load dataset
data(mtcars)

# Fit linear model
lm_model <- lm(mpg ~ wt, data = mtcars)

# Print model summary
cat("----- Linear Model Summary -----\n")
print(summary(lm_model))

# Open plot window if on macOS (to ensure visibility)
if (Sys.info()["sysname"] == "Darwin") quartz()

plot(mtcars$wt, mtcars$mpg,
     main = "Simple Linear Regression: MPG vs Weight",
     xlab = "Weight (wt)",
     ylab = "Miles per Gallon (mpg)",
     pch = 19,
     col = "blue")
abline(lm_model, col = "red", lwd = 2)

Sys.sleep(10)