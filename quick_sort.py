import time

arr = list(map(int, input("Enter array: ").split(', ')))

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

start_time = time.perf_counter()
sorted_array = quick_sort(arr)
end_time = time.perf_counter()
execution_time = end_time-start_time

print(f"Array: {sorted_array}\nTime ran: {execution_time:.6f}")

