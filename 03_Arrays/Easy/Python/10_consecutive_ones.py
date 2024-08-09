from typing import List

class Solution:
  def consecutive_ones(self, arr: List[int]) -> int:
    cnt = 0
    maxi = 0
    n = len(arr)

    for i in range(n):
      if arr[i] == 1:
        cnt += 1
      else:
        cnt = 0
      maxi = max(maxi, cnt)
    return maxi
  
size = int(input("size: "))
arr = list(map(int, input("Enter sorted array: ").strip().split()[:size]))

sol = Solution()

print(sol.consecutive_ones(arr))