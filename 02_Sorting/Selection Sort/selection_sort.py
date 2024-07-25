def selection_sort(arr, size):

  for i in range (size):
    min_index = i
    for j in range(i+1, size):
      if arr[min_index] > arr[j]:
        min_index = j

    if min_index != i:
      arr[min_index], arr[i] = arr[i], arr[min_index]
  return

def select_min_index(arr, start, stop, min_index):
  # base condition
  if start > stop:
    return min_index
  
  if arr[min_index] > arr[start]:
    min_index = start

  min_index = select_min_index(arr, start+1, stop, min_index)
  return min_index

def selection_sort_recursion(arr, start, stop):
  # base condition
  if start == stop:
    return
  
  min_index = start
  min_index = select_min_index(arr, start+1, stop, min_index)
  if(min_index != start):
    arr[min_index], arr[start] = arr[start], arr[min_index]
    
  selection_sort_recursion(arr, start+1, stop)
  return


size = int(input("size: "));

arr = list(map(int, input("Enter elements of array: ").strip().split()[:size]))

# selection_sort(arr, size)
selection_sort_recursion(arr, 0, size-1)

print(arr)