def find_second_largest(numbers):
    if len(numbers) < 2:
        return None

    first, second = float('-inf'), float('-inf')

    for num in numbers:
        if num > first:
            second = first
            first = num
        elif first > num > second:
            second = num

    return second if second != float('-inf') else None

# Example usage
numbers = [10, 20, 4, 45, 99, 99, 23]
result = find_second_largest(numbers)

if result is not None:
    print("The second largest number is:", result)
else:
    print("The list does not have a second largest number.")