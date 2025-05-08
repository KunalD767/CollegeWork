import pandas as pd
import matplotlib.pyplot as plt

# Read data from CSV file
data = pd.read_csv("data.csv")

# Create a bar chart
plt.figure(figsize=(8, 5))
plt.bar(data["Category"], data["Value"], color=["red", "yellow", "pink", "brown", "purple"])

# Add labels and title
plt.xlabel("Category")
plt.ylabel("Value")
plt.title("Fruit Sales Data")
plt.xticks(rotation=30)

# Show the visualization
plt.show()
