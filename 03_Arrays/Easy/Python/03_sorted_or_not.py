def isArraySorted (arr):
  for i in range(1, len(arr)):
    if arr[i] < arr[i-1]:
      return False
  return True

size = int(input("Enter size: "));

arr = list(map(int, input("Enter elements in the array: ").strip().split()))

print(isArraySorted(arr))