def rotate_list_right(input_list, positions):
    if not input_list:
        return []

    positions = positions % len(input_list)

    return input_list[-positions:] + input_list[:-positions]

example_list = [1, 2, 3, 4, 5]
positions = 2
rotated_list = rotate_list_right(example_list, positions)

print(f"Original list: {example_list}")
print(f"List after rotating {positions} positions to the right: {rotated_list}")