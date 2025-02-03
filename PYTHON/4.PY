def sort_numbers():
    try:
        numbers = list(map(int, input("Enter a list of numbers separated by spaces: ").split()))
        numbers.sort()
        print("Sorted numbers in ascending order:", numbers)
    except ValueError:
        print("Please enter valid numbers separated by spaces.")
sort_numbers()

print("Name: KUNAL DUA")
print("Roll Number: 35614802722")
