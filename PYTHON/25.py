def reverse_list(input_list):
    reversed_list = []
    for item in input_list:
        reversed_list.insert(0, item)
    return reversed_list

example_list = [1, 2, 3, 4, 5]
reversed_result = reverse_list(example_list)

print("Original list:", example_list)
print("Reversed list:", reversed_result)