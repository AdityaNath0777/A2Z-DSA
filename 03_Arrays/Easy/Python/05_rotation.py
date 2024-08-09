from typing import List

def rotate_right_better(nums: List[int], k: int) -> None:    
  n = len(nums)
  k = k % n

  temp = []
  for i in range(n-k, n):
    temp.append(nums[i]) 

  for i in range(n-k-1, -1, -1):
    nums[i+k] = nums[i]

  for i in range(k):
    nums[i] = temp[i]

def Reverse(arr: List[int], left: int, right: int) -> None:
  while left < right:
    temp = arr[left]
    arr[left] = arr[right]
    arr[right] = temp
    left += 1
    right -= 1

def rotate_right_optimal(arr: List[int], k: int) -> None:
  n = len(arr)
  k = k % n

  Reverse(arr, n-k, n-1)
  Reverse(arr, 0, n-k-1)
  Reverse(arr, 0, n-1)

  # TC -> O(N)
  # SC -> O(1) 
  
def rotate_left_optimal(arr: List[int], k: int) -> None:
  n = len(arr)
  k = k%n

  Reverse(arr, 0, k-1)
  Reverse(arr, n-k, n-1)
  Reverse(arr, 0, n-1)

  # TC -> O(N)
  # SC -> O(1) 

def rotate_left_brute(arr: List[int], k: int) -> None:
  n = len(arr)
  temp = []

  for i in range(n-k, n):
    temp.append(arr[i])

  for i in range(k):
    temp.append(arr[i])

  for i in range(n):
    arr[i] = temp[i]
  
  print(f"brute: {arr}")


def rotate_left_better(arr: List[int], k: int) -> None:
  n = len(arr)
  temp = []

  for i in range(k):
    temp[i] = arr[i]

  for i in range(n-k):
    arr[i] = arr[i+k]

  for i in range(n-k, n):
    arr[i] = temp[i-(n-k)]
  
  print(f"better: {arr}")

  


size = int(input("Enter size: "))
arr = list(map(int, input("Enter elements in array: ").strip().split()[:size]))

k = int(input("Enter degree of rotation: "))

# rotate_right_better(arr, k)
# rotate_right_optimal(arr, k)
# rotate_left_optimal(arr, k)
rotate_left_brute(arr[:], k)
rotate_left_better(arr[:], k)
print(arr)