def check_voting_eligibility():
    try:
        age = int(input("Enter your age: "))
        if age >= 18:
            print("You are eligible to vote in the next elections.")
        else:
            print("You are NOT eligible to vote in the next elections.")
    except ValueError:
        print("Please enter a valid number for age.")

check_voting_eligibility()
print("Name: KUNAL DUA")
print("Roll Number: 35614802722")
