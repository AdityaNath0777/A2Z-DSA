def rotate_right(nums: list, k: int) -> None:    
  n = len(nums)
  k = k % n

  temp = []
  for i in range(n-k, n):
    temp.append(nums[i]) 

  for i in range(n-k-1, -1, -1):
    nums[i+k] = nums[i]

  for i in range(k):
    nums[i] = temp[i]


size = int(input("Enter size: "))
arr = list(map(int, input("Enter elements in array: ").strip().split()[:size]))

k = int(input("Enter degree of rotation: "))

rotate_right(arr, k)
print(arr)