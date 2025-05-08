def safe_division():
    while True:
        try:
            numerator = float(input("Enter the numerator: "))
            denominator = float(input("Enter the denominator: "))
            result = numerator / denominator
            print(f"Result: {result}")
            break  # Exit loop if division is successful
        except ZeroDivisionError:
            print("Error: Division by zero is not allowed. Please enter a valid denominator.")
        except ValueError:
            print("Error: Please enter valid numbers.")

safe_division()
