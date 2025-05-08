from pprint import pprint

def char_frequency(s):
    if not isinstance(s, str):
        raise TypeError("Input must be a string.")
    
    frequency = {}
    for char in s:
        frequency[char] = frequency.get(char, 0) + 1
    
    pprint(frequency)

# Example usage
try:
    text = input("Enter a string: ")
    char_frequency(text)
except TypeError as e:
    print(f"Error: {e}")
