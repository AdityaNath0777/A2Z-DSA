def move_zeros_brute(arr: list) -> None:

  temp = []

  # store the non-zero elements in an array/list
  for i in range(len(arr)):
    if arr[i] != 0:
      temp.append(arr[i])

  # store that elements in OG array
  for i in range(len(temp)):
    arr[i] = temp[i]


  # rest of the elements in the array will be zero 
  for i in range(len(temp), len(arr)):
    arr[i] = 0

  return


def move_zeros_optimal(arr: list) -> None:

  # j will always point on the zero
  j = None

  # finding index of 1st zero:
  for i in range(len(arr)):
    if arr[i] == 0:
      j = i
      break

  # if no zero elements are found:
  if j == None:
    return
  
  # if zero elements are found:
  for i in range(j+1, len(arr)):

    # if the element is non-zero
    # swap it with j
    if arr[i] != 0:
      arr[i], arr[j] = arr[j], arr[i]
      j += 1
  
  return

def move_zeros_optimal_2(arr: list) -> None:
    # Initialize j to 0 to track the next zero position
    j = 0

    # Iterate through the array
    for i in range(len(arr)):
        # If the element is non-zero,
          # swap it with the element at index j
        if arr[i] != 0:
            arr[i], arr[j] = arr[j], arr[i]
            j += 1

    return


size = int(input("Enter size: "))
arr = list(map(int, input("Enter elements in array: ").strip().split()))

# move_zeros_brute(arr)
# move_zeros_optimal(arr)
move_zeros_optimal_2(arr)

print(arr)