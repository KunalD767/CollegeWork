import re

def find_pattern_in_file(file_path, pattern):
    try:
        with open(file_path, 'r') as file:
            content = file.read()

        matches = re.findall(pattern, content)
        return matches

    except FileNotFoundError:
        print(f"The file '{file_path}' was not found.")
        return []
    except Exception as e:
        print(f"An error occurred: {e}")
        return []

# Example usage
file_path = 'example.txt'  
pattern = r'\b[A-Z][a-z]+\b'  #

matches = find_pattern_in_file(file_path, pattern)

if matches:
    print("Found matches:", matches)
else:
    print("No matches found.")
