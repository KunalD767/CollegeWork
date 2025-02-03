rows = 5
for i in range(1, rows + 1):
    print(" " * (rows - i), end="")

    for j in range(1, i + 1):
        print(j, end="")

    for j in range(i - 1, 0, -1):
        print(j, end="")
    print()

print("Name: KUNAL DUA")
print("Roll Number: 35614802722")
