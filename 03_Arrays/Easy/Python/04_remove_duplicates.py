# remove duplicates from the Sorted Array
# and return the number of unique elements

# make changes in the array itself

def remove_duplicates_brute(arr: list) -> int:
  st = set()

  # TC -> O(N)
  for i in range(len(arr)):
    st.add(arr[i])
  
  # as IN PYTHON: sets do not support indexing
  # so we'll convert the set into a list
  unique_list = sorted(st) # unorderd set -> sorted list
  # TC -> O(NlogN)

  # TC -> O(N)
  for j in range(len(unique_list)):
    arr[j] = unique_list[j]
  

  # Total TC -> O(NlogN + 2N)
  # Total SC -> O(N)
  return len(unique_list)


# optimal approach
    # using -> 2 ptr
def remove_duplicates_optimal(arr: list) -> int:

  i = 0
  for j in range(1, len(arr)):
    if (arr[j] != arr[i]):
      i += 1
      arr[i] = arr[j]
  
  # TC -> O(N)
  # SC -> O(1)
  return i+1


size = int(input("Enter size: "))
arr = list(map(int, input("Enter elements in array: ").strip().split()))

# newSize = remove_duplicates_brute(arr)
newSize = remove_duplicates_optimal(arr)

print(arr)
print(arr[:newSize])