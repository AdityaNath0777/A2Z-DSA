# brute
def two_sum_brute(arr: list, target: int):
  n = len(arr)

  # TC -> O(N^2)
  # SC -> O(1)(extra space) + O(N)(space used to solve the problem)
  for i in range(n):
    for j in range(i+1, n):
      if target == arr[i] + arr[j]:
        return [i, j]
  return [-1, -1]

# better -> using hash-map
def two_sum_better(arr: list, target: int):
  n = len(arr)

  # dictionary to implement hash map
  hashMap = {}

  for i in range(n): # TC -> O(N)
    rem = target - arr[i]

    # checking if the remainder is already in the hashmap
    if rem in hashMap: 
      # in Python, hashMap insertion & lookup on avg -> TC -> O(1)
      return [hashMap[rem], i]

    # if rem, not in the hashmap
    # store the arr[i] in the hashmap
    hashMap[arr[i]] = i
  # total TC -> O(N)
  # total SC -> O(N) (for hashmap)
  return [-1, -1]

# only slightly optimal than hashmap
# it distortes the array by sorting
def two_sum_optimal(arr: list, target: int):
  arr.sort() # TC -> O(NlogN)

  # two - ptr approach
  left = 0
  right = len(arr) - 1

  """
    iterate:
      from -> left to right
                    &
              right to left

      calc: sum of element at left & right index 
      
      if sum == target -> return 

      if sum < target:
        we need to increase value of sum
        by increamenting left index, we might value > than arr[left]
        so -> left = left + 1
      
      else:
        means -> sum > target:
          to decrease the value of sum
          right = right - 1
  """
  # TC -> O(N)
  while(left < right):
    sum = arr[left] + arr[right]

    if sum == target:
      return [arr[left], arr[right]]
    
    if sum < target:
      left += 1
    else:
      right -= 1  

  # total TC -> O(NlogN) + O(N) (not efficient than hashMap)
  # total SC -> O(1) (SC is efficient than hashMap)
  return [None, None]

size = int(input("Enter size: "))
arr = list(map(int, input("Enter elements in the array: ").strip().split()[:size]))

target = int(input("Enter target: "))

# target_index = two_sum_brute(arr, target)
target_index = two_sum_better(arr, target)
# target_index = two_sum_optimal(arr, target)

if target_index[0] != -1 or target_index[0] != None:
  print(target_index)
else:
  print("target not found")