from typing import List

class Solution:
  def find_missingNum_brute(self, arr: List[int], N: int) -> int:
    for i in range(1, N+1):
      isMissing = True
      for j in range(len(arr)):
        if arr[j] == i:
          isMissing = False
      
      if isMissing:
        return i
  
  def find_missingNum_my_brute(self, arr: List[int], N: int) -> int:
    arr.sort()
    n = len(arr)
    for i in range(1, n):
      diff = arr[i] - arr[i-1]
      if diff > 1:
        return arr[i-1] + 1
    return N
  
  def find_missingNum_better(self, arr: List[int], N: int) -> int:
    isVisited = [0] * (N+1)

    for i in range(len(arr)):
      isVisited[arr[i]] = 1
    
    for j in range(1, N+1):
      if isVisited[j] == 0:
        return j
    return N
  
  def find_missingNum_optimal_sum(self, arr: List[int], N: int) -> int:
    sum_N = int(( N*(N+1) ) / 2)
    sum = 0
    for i in range(len(arr)):
      sum += arr[i]

    # TC -> O(N)
    # SC -> O(1)    
    return sum_N - sum
  

  def find_missingNum_optimal_xor(self, arr: List[int], N: int) -> int:
    xor_N = 0
    xor_a = 0

    for i in range(len(arr)):
      xor_N = xor_N ^ (i+1)
      xor_a = xor_a ^ arr[i]
    
    xor_N = xor_N ^ N

    # TC -> O(N)
    # SC -> O(1)  # -> But xor will always occupy less space than sum
    return xor_N ^ xor_a


size = int(input("size of the Array: "))
arr = list(map(int, input("Elements of the Array: ").strip().split()[ : size]))

sol = Solution()

# print(sol.find_missingNum_brute(arr, size+1))
# print(sol.find_missingNum_my_brute(arr, size+1))
# print(sol.find_missingNum_better(arr, size+1))
# print(sol.find_missingNum_optimal_sum(arr, size+1))
print(sol.find_missingNum_optimal_xor(arr, size+1))

