def my_partition(arr: list, low: int, high: int):
  pivot = arr[low]
  i = low
  j = high

  while i < j:
    while (arr[i] <= pivot and i <= high-1):
      i += 1

    while (arr[j] > pivot and j >= low+1):
      j -= 1

    if i < j:
      arr[i], arr[j] = arr[j], arr[i]
  
  arr[low], arr[j] = arr[j], arr[low]

  return j
  
def qS(arr: list, low: int, high: int):
  if low < high:
    partition_index = my_partition(arr, low, high)
    qS(arr, low, partition_index-1)
    qS(arr, partition_index+1, high)

def quick_sort(arr: list):
  low = 0
  high = len(arr)-1
  qS(arr, low, high)

size = int(input("Enter size: "))
arr = list(map(int, input("Enter elements in array: ").strip().split()[:size]))

quick_sort(arr)

print(arr)