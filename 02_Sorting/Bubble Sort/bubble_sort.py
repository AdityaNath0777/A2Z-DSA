def bubble_sort(arr):
  for i in range(len(arr)-1):
    for j in range(len(arr)-i-1):
      if arr[j] > arr[j+1]:
        arr[j], arr[j+1] = arr[j+1], arr[j]
  return

size = int(input("size: "));

arr = list(map(int, input("Enter elements of array: ").strip().split()[:size]))

bubble_sort(arr)

print(arr)