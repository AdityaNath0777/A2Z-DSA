def bubble_sort(arr):
  for i in range(len(arr)-1):
    for j in range(len(arr)-i-1):
      if arr[j] > arr[j+1]:
        arr[j], arr[j+1] = arr[j+1], arr[j]
  return

def bubble_swap(arr, start, stop):
  if start >= stop:
    return
  
  if arr[start] > arr[stop]:
    arr[start], arr[stop] = arr[stop], arr[start]
  
  bubble_swap(arr, start+1, stop)
  return

def bubble_sort_recursion(arr, start, stop):
  if start >= stop:
    return
  
  bubble_swap(arr, start, stop-start)

  bubble_sort_recursion(arr, start+1, stop)
  return

size = int(input("size: "));

arr = list(map(int, input("Enter elements of array: ").strip().split()[:size]))

# bubble_sort(arr)
bubble_sort_recursion(arr, 0, size-1)

print(arr)