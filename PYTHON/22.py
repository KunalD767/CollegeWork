def longest_increasing_subsequence(nums):
    if not nums:
        return []

    n = len(nums)
    lengths = [1] * n
    previous = [-1] * n

    max_length = 1
    max_index = 0

    for i in range(1, n):
        for j in range(i):
            if nums[i] > nums[j] and lengths[i] < lengths[j] + 1:
                lengths[i] = lengths[j] + 1
                previous[i] = j
                if lengths[i] > max_length:
                    max_length = lengths[i]
                    max_index = i

    # Reconstruct the longest increasing subsequence
    lis = []
    while max_index != -1:
        lis.append(nums[max_index])
        max_index = previous[max_index]

    lis.reverse()
    return lis

# Example usage
numbers = [10, 22, 9, 33, 21, 50, 41, 60, 80]
lis = longest_increasing_subsequence(numbers)
print("Longest Increasing Subsequence:", lis)