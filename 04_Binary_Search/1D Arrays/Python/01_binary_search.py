def binary_search(arr: list, target: int):
  low = 0
  high = len(arr) - 1

  while low <= high:
    mid = int( low + (high-low)/2 )

    if arr[mid] == target:
      return mid
    elif arr[mid] > target:
      high = mid - 1
    else:
      low = mid + 1
  return -1


def bs_algo(arr: list, low: int, high: int, target: int):
  # base condition
  if low > high:
    return -1
  

  mid = int(low + (high-low)/2)

  if arr[mid] == target:
    return mid
  elif arr[mid] > target:
    return bs_algo(arr, low, mid - 1, target)
  else:
    return bs_algo(arr, mid + 1, high, target)


def binary_search_recursive(arr: list, target: int):
  low = 0
  high = len(arr) - 1
  return bs_algo(arr, low, high, target)

size = int(input("Enter size: "))
arr = list(map(int, input("Enter elements in array in sorted manner: ").strip().split()[:size]))

target = int(input("Enter the target: "))

# target_index = binary_search(arr, target)
target_index = binary_search_recursive(arr, target)

if target_index >= 0:
  print("Target found at index: ", target_index)
else:
  print("Target NOT found")