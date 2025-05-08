# Load the dataset
data("AirPassengers")

# Open quartz plot window (macOS only)
if (Sys.info()["sysname"] == "Darwin") {
  quartz()
}

# Plot the data
plot(AirPassengers,
     main = "Airline Passenger Numbers (1949–1960)",
     xlab = "Year",
     ylab = "Number of Passengers",
     col = "blue",
     type = "o",
     pch = 16,
     lwd = 2)

# Force R to wait to let the plot render (macOS+VS Code workaround)
Sys.sleep(20)