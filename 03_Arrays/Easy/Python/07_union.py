# given -> 2 sorted arrays containing integers
# return -> union with distinct elements in sorted order

from typing import List

# class Solution(object): # -> Python 2 style
class Solution:
  # brute force -> using sets
  def union_of_Array_brute(self, arr_1: List[int], arr_2: List[int]) -> List[int]:
    # set insertion
    # set.add()
    st = set()

    for i in range(len(arr_1)):
      st.add(arr_1[i])
    
    for i in range(len(arr_2)):
      st.add(arr_2[i])

    ans = list(st)
    # ans = List(st)
    return ans

  # optimal -> 2-ptr approach
  def union_of_Array_optimal(self, arr_1: List[int], arr_2: List[int]) -> List[int]:
    n1 = len(arr_1)
    n2 = len(arr_2)

    ans = []

    i = 0
    j = 0

    while i < n1 and j < n2:
      if arr_1[i] <= arr_2[j]:
        if len(ans) == 0 or ans[-1] != arr_1[i]:
          ans.append(arr_1[i])
        i += 1
      
      else:
        if len(ans) == 0 or ans[-1] != arr_2[j]:
          ans.append(arr_2[j])
        j += 1

    
    while i < n1:
      if len(ans) == 0 or ans[-1] != arr_1[i]:
        ans.append(arr_1[i])
      i += 1 

    while j < n2:
      if len(ans) == 0 or ans[-1] != arr_2[j]:
        ans.append(arr_2[j])
      j += 1     
      

    return ans


size_1 = int(input("size 1: "))
size_2 = int(input("size 2: "))

arr_1 = list(map(int, input("Enter elements in array 1: ").strip().split()[ : size_1]))
arr_2 = list(map(int, input("Enter elements in array 2: ").strip().split()[ : size_2]))

my_union = Solution()

# print(my_union.union_of_Array_brute(arr_1, arr_2))
print(my_union.union_of_Array_optimal(arr_1, arr_2))