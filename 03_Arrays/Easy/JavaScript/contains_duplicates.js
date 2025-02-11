const containsDuplicateBrute = function (nums) {
  const n = nums.length;

  for (let i = 0; i < n; ++i) {
    // to pick every one by one
    for (let j = i + 1; j < n; ++j) {
      // to pick every other element to compare
      // i+1 ensures the current picked element is at different index than the comparing one's
      if (nums[i] === nums[j]) return true;
    }
  }

  // even if after traversing the entire array,
  // we've not found any duplicate element
  return false;

  /**
   * TC -> O(N^2)
   * SC -> O(1)
   */
};

const containsDuplicateOptimal = function (nums) {
  const n = nums.length;

  let hashMap = {}; // to store visited elements

  for (let i = 0; i < n; ++i) {
    if (hashMap[nums[i]] ?? false) { // if value is not inside hashMap, it is unvisited, go to else 
      return true;
    } else hashMap[nums[i]] = true;
  }

  /**
   * TC -> O(N)
   * SC -> O(N)
   */
  return false;
};

let arr = [1, 2, 3, 2];

console.log("contains duplicate(brute): ", containsDuplicateBrute(arr));

console.log("contains duplicate(optimal): ", containsDuplicateOptimal(arr));
