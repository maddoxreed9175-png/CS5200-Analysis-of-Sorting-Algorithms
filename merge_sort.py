import time

arr = list(map(int, input("Enter array: ").split(', ')))

def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left_half = merge_sort(arr[:mid])
    right_half = merge_sort(arr[mid:])

    return merge(left_half, right_half)

def merge(left, right):
    sorted_list = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            sorted_list.append(left[i])
            i += 1
        else:
            sorted_list.append(right[j])
            j += 1

    sorted_list.extend(left[i:])
    sorted_list.extend(right[j:])
    return sorted_list

start_time = time.perf_counter()
sorted_array = merge_sort(arr)
end_time = time.perf_counter()
execution_time = end_time-start_time

print(f"Array: {sorted_array}\nTime ran: {execution_time:.6f}")

