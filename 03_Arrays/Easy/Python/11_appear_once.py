# given -> array having elements appearing exactly two time
#      -> except the one that is appearing only once
# find that element (it could be -ve or +ve)


from typing import List

class Solution:
  def appear_once_brute(self, arr: List[int]) -> int:
    n = len(arr)

    for num in arr:
      count = 0
      for i in range(n):
        if num == arr[i]:
          count += 1
        elif count > 1:
          break
      
      if count == 1:
        return num
      
  def appear_once_better(self, arr: List[int]) -> int:
    n = len(arr)
    visited = [0] * n
    # TC -> O(N)
    for i in range(n):
      visited[arr[i]] += 1

    # TC -> O(N)
    for i in range(n):
      if visited[arr[i]] == 1:
        return arr[i]
      
    # total TC -> O(N + N/2)
    # total SC -> O(N)
    return -1
  
  def appear_once_optimal(self, arr: List[int]) -> int:
    n = len(arr)
    xorA = 0

    for i in range(n):
      xorA = xorA ^ arr[i]
    
    return xorA
  
  # assumes array is sorted (well already given)
  # then we applies binary search
  # TC -> O(logN)
  def appear_once_super_optimal(self, arr: List[int]) -> int:

    low = 0
    high = len(arr) - 1

    while low < high:
      mid = int(low + (high-low)/2)

      if mid % 2 == 1:
        mid -= 1
      
      if arr[mid] == arr[mid + 1]:
        low = mid + 2
      elif arr[mid] != arr[mid+1]:
        high = mid

    return arr[low]

size = int(input("size: "))
arr = list(map(int, input("element in the array: ").strip().split()[ : size]))

ans = Solution()

# print(ans.appear_once_brute(arr))
# print(ans.appear_once_better(arr))
# print(ans.appear_once_optimal(arr))
print(ans.appear_once_super_optimal(arr))