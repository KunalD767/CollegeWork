def divide_numbers():
    try:
        # Prompt user for two numbers
        num1 = float(input("Enter the first number: "))
        num2 = float(input("Enter the second number: "))
        
        # Perform division
        result = num1 / num2
        print(f"Result: {num1} / {num2} = {result}")

    except ValueError:
        print("Error: Please enter valid numeric values.")

    except ZeroDivisionError:
        print("Error: Division by zero is not allowed.")

    except Exception as e:
        print(f"An unexpected error occurred: {e}")

    finally:
        print("Thank you for using the division program.")

# Run the program
divide_numbers()
