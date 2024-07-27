# brite force approach
def second_largest_brute(arr: list):
  max = arr[0]
  sMax = None

  # insertion sort
  for i in range(1, len(arr)):
    for j in range(i, 0, -1):
      if arr[j] < arr[j-1]:
        arr[j], arr[j-1] = arr[j-1], arr[j] 


  max = arr[len(arr) - 1]

  for i in range(len(arr)-1, -1, -1):
    if arr[i] < max:
      sMax = arr[i]
      break

  # it will return None if all are duplicates
  return sMax


# better approach
def second_largest_better(arr: list):
  # find maximum
  max = arr[0]

  for i in range(1, len(arr)):
    if arr[i] > max:
      max = arr[i]
  
  sMax = float('-inf')

  for i in range(len(arr)):
    if (arr[i] > sMax) and (arr[i] < max):
      sMax = arr[i]
  
  if sMax == float('-inf'):
    return None # all elements are duplicates
  return sMax


# optimal approach
def second_largest_optimal(arr: list):
  max = arr[0]
  sMax = float('-inf')

  for i in range(len(arr)):
    if arr[i] > max:
      sMax = max
      max = arr[i]

    if (arr[i] > sMax) and (arr[i] != max):
      sMax = arr[i]
  
  if (sMax == max) or (sMax == float('-inf')):
    return None
  
  return sMax

size = int(input("Enter size: "));

arr = list(map(int, input("Enter elements in the array: ").strip().split()))

# print(second_largest_brute(arr))
# print(second_largest_better(arr))
print(second_largest_optimal(arr))