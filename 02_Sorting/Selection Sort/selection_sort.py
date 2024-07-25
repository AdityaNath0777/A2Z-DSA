def selection_sort(arr, size):

  for i in range (size):
    min_index = i
    for j in range(i+1, size):
      if arr[min_index] > arr[j]:
        min_index = j

    if min_index != i:
      arr[min_index], arr[i] = arr[i], arr[min_index]
  return

size = int(input("size: "));

arr = list(map(int, input("Enter elements of array: ").strip().split()[:size]))

selection_sort(arr, size)

print(arr)