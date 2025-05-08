def is_list_empty(input_list):
    if not input_list:
        return True
    else:
        return False

# Example usage
example_list = []
if is_list_empty(example_list):
    print("The list is empty.")
else:
    print("The list is not empty.")
