import re

def is_valid_password(password):
    if (len(password) >= 8 and
        re.search(r"[A-Z]", password) and
        re.search(r"[a-z]", password) and
        re.search(r"\d", password) and
        re.search(r"[!@#$%^&*(),.?\":{}|<>]", password)):
        return True
    return False

# Sample usage
test_passwords = ["Hello@123", "weakpass", "StrongPass1!", "NoSpecial1"]
for pwd in test_passwords:
    print(f"{pwd}: {'Valid' if is_valid_password(pwd) else 'Invalid'}")
