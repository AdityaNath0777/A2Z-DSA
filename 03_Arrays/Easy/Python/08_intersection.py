# given -> 2 sorted arrays
# return -> intersection w/o duplicates

from typing import List

class Solution:
  def intersection_brute(self, a: List[int], b: List[int]) -> List[int]:
    ans = []

    for i in range(len(a)):
      for j in range(len(b)):
        if a[i] == b[j]:
          ans.append(a[i])
    
    return ans
  
  # optimal -> 2-ptr approach
  def intersection_optimal(self, a: List[int], b: List[int]) -> List[int]:
    ans = []

    n1 = len(a)
    n2 = len(b)

    i = 0
    j = 0

    while i < n1 and j < n2:
      if a[i] == b[j]:
        # a little change to check whether they're already in the ans or not
        if (not ans) or ans[-1] != a[i]:
          ans.append(a[i])
        i += 1
        j += 1

      elif a[i] < b[j]:
        i += 1
      else:
        j += 1
    return ans
  
  # if given array is unsorted
  def intersection_unsorted(self, a: List[int], b: List[int]) -> List[int]:
    ans = []
    st = set(a)

    # Method: #1

    # for num in b:
    #   if num in st:
    #     ans.append(num)
    
# ************************************************************************* #

    # Method: #2
    # more concise using Python syntax

    # Find intersection using set operations
    ans = list(set(num for num in b if num in st))
    # total TC: O(N + M), similar to the o.g. ver., 
                # but with potentially slightly improved performance 
                # due to the efficient set operations.
    # total SC: O(2N) ~ O(N)
    return ans


size_1 = int(input("size 1: "))
size_2 = int(input("size 2: "))

arr_1 = list(map(int, input("Enter elements in array 1: ").strip().split()[ : size_1]))
arr_2 = list(map(int, input("Enter elements in array 2: ").strip().split()[ : size_2]))

my_intersection = Solution()

# print(my_intersection.intersection_brute(arr_1, arr_2))
# print(my_intersection.intersection_optimal(arr_1, arr_2))
print(my_intersection.intersection_unsorted(arr_1, arr_2))
