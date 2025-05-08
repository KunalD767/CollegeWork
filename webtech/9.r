# Project A
pA <- c(0.3, 0.4, 0.3)
rA <- c(2000, 3000, 1000)

evA <- sum(pA * rA)

varA <- sum(pA * (rA - evA)^2)
sdA <- sqrt(varA)

# Project B
pB <- c(0.5, 0.3, 0.2)
rB <- c(500, 4000, 2000)

evB <- sum(pB * rB)

varB <- sum(pB * (rB - evB)^2)
sdB <- sqrt(varB)

# Output
cat("Project A:\n")
cat("Expected Value:", evA, "\n")
cat("Standard Deviation:", sdA, "\n\n")

cat("Project B:\n")
cat("Expected Value:", evB, "\n")
cat("Standard Deviation:", sdB, "\n\n")

# Risk Comparison
if (sdA > sdB) {
  cat("Project A is riskier\n")
} else if (sdB > sdA) {
  cat("Project B is riskier\n")
} else {
  cat("Both projects have equal risk\n")
}