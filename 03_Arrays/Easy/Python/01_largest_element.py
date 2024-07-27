# Brute force approach
def largest_element_brute(arr: list):
  
  # bubble sort
  for i in range(len(arr)-1):
    for j in range(len(arr)-i-1):
      # if prev ele > next ele:
        # swap
      if(arr[j] > arr[j+1]):
        arr[j], arr[j+1] = arr[j+1], arr[j]

  return arr[len(arr) - 1]

# optimal approach
def largest_element_optimal(arr):

  max = arr[0] # initializeation
  
  for i in range(1, len(arr)):
    if arr[i] > max:
      max = arr[i]
  return max

size = int(input("Enter size: "));

arr = list(map(int, input("Enter elements in the array: ").strip().split()))

print(largest_element_brute(arr))
print(largest_element_optimal(arr))