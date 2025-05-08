def read_file(filename):
    try:
        with open(filename, "r") as file:
            content = file.read()
            print("File Contents:\n", content)
    except FileNotFoundError:
        print(f"Error: The file '{filename}' was not found.")

# Example usage
filename = input("Enter the filename: ")
read_file(filename)
