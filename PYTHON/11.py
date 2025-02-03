number = int(input("Enter a number to check if it is prime: "))

if number > 1:
    for i in range(2, int(number ** 0.5) + 1):
        if number % i == 0:
            print(f"{number} is not a prime number.")
            break
    else:
        print(f"{number} is a prime number.")
else:
    print(f"{number} is not a prime number.")

print("Name: KUNAL DUA")
print("Roll Number: 35614802722")
