# Project 1 — Temperature Converter
# Author: Your Name
# Formula: F = (C × 9/5) + 32

# Step 1 — Get input from the user and convert to float
celsius = float(input("Enter temperature in Celsius: "))

# Step 2 — Apply the formula
fahrenheit = (celsius * 9/5) + 32

# Step 3 — Print the result using an f-string
# Use :.1f to show one decimal place as required
print(f"{celsius:.1f}°C = {fahrenheit:.1f}°F")
