def have_common_elements(list1, list2):
    return not set(list1).isdisjoint(set(list2))

# Example usage:
list1 = [1, 2, 3, 4]
list2 = [3, 5, 6, 7]
print(have_common_elements(list1, list2))  
