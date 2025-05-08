def remove_duplicates(input_list):
    unique_list = []
    for item in input_list:
        is_duplicate = False
        # Check if item already exists in the unique_list
        for unique_item in unique_list:
            if item == unique_item:
                is_duplicate = True
                break
        # If not duplicate, add to unique_list
        if not is_duplicate:
            unique_list.append(item)
    return unique_list

# Example usage
input_list = [1, 2, 3, 2, 4, 1, 5, 3, 6]
print("Original list:", input_list)
output_list = remove_duplicates(input_list)
print("List after removing duplicates:", output_list)
