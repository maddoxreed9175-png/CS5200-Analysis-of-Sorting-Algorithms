import time

arr = list(map(int, input("Enter array: ").split(', ')))

def heapify(arr, n, i):
    largest = i    
    l = 2 * i + 1    
    r = 2 * i + 2  

    if l < n and arr[l] > arr[largest]:
        largest = l

    if r < n and arr[r] > arr[largest]:
        largest = r

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Swap max to end
        heapify(arr, i, 0)
    
    return arr

start_time = time.perf_counter()
sorted_array = heap_sort(arr)
end_time = time.perf_counter()
execution_time = end_time-start_time

print(f"Array: {sorted_array}\nTime ran: {execution_time:.6f}")

