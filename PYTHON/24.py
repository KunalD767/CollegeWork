def merge_and_sort(list1, list2):
    merged_list = list1 + list2

    # Simple bubble sort for ascending order
    for i in range(len(merged_list)):
        for j in range(0, len(merged_list) - i - 1):
            if merged_list[j] > merged_list[j + 1]:
                merged_list[j], merged_list[j + 1] = merged_list[j + 1], merged_list[j]

    return merged_list

# Example usage
list1 = [5, 1, 9, 3]
list2 = [8, 2, 6, 4]
result = merge_and_sort(list1, list2)

print("Merged and sorted list:", result)
