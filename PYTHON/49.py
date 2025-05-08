import os

def recursive_search(directory, target_file):
    for root, dirs, files in os.walk(directory):
        if target_file in files:
            print(f"Found: {os.path.join(root, target_file)}")
            return os.path.join(root, target_file)
    print("File not found.")
    return None

# Example usage
recursive_search('.', 'sample2.txt')
