from typing import List

class Solution:
  def check(self, arr: List[int]) -> bool:
    n = len(arr)
    count = 0

    for i in range(n):
      if arr[i] > arr[(i+1) % n]:
        count += 1
        if count > 1:
          return False
    
    return count <= 1
  
size = int(input("Enter size: "))
arr = list(map(int, input("Enter elements in array: ").strip().split()[ : size]))

ans = Solution()

print(ans.check(arr))