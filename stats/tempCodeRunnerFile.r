# Load the built-in dataset
data("AirPassengers")

# Open plot window (use only on macOS/VSCode if plots don't show)
if (Sys.info()["sysname"] == "Darwin") quartz()

# Plot the time series
plot(AirPassengers,
     main = "Airline Passenger Numbers (1949–1960)",
     xlab = "Year",
     ylab = "Number of Passengers",
     col = "blue",
     type = "o",       # 'o' = overplotted lines and points
     pch = 16,         # solid circle for points
     lwd = 2,          # line width
     cex = 0.7)        # point size

# Add a grid for better readability
grid()