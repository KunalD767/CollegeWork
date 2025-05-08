def find_min_max(numbers):
    if not numbers:
        return None, None

    min_num = min(numbers)
    max_num = max(numbers)

    return min_num, max_num

# Example usage
try:
    user_input = input("Enter a list of numbers separated by spaces: ")
    number_list = list(map(float, user_input.split()))

    if not number_list:
        print("The list is empty. Please enter some numbers.")
    else:
        minimum, maximum = find_min_max(number_list)
        print(f"Minimum element: {minimum}")
        print(f"Maximum element: {maximum}")
except ValueError:
    print("Invalid input. Please enter only numbers separated by spaces.")
