/**
 * Problem Statement: Contains Duplicate
 *
 * Given an integer array nums,
 * return true
 *    if any value appears at least twice in the array,
 *    and
 * return false
 *    if every element is distinct.
 */

const containsDuplicateBrute = function (nums) {
  /**
   * we have an array nums = []
   *
   * if this array contains any duplicate number
   *  return true
   * else return false
   *
   * so I have traverse the entire array at least once
   *
   * -> first loop (outer)
   *    pick an element say 'num'
   * -> second loop (inner)
   *      pick element and compare with the 'num'
   *      if matched return true
   *
   * -> after all both loops are aover
   * it means,
   * we have traveres the entire array
   * and did not find any duplicate element
   * thus return false
   */

  for (let i = 0; i < nums.length; ++i) {
    for (let j = i + 1; j < nums.length; ++j) {
      if (nums[i] === nums[j]) return true;
    }
  }

  return false;

  /**
   * Time Complexity
   *
   * TC: O(N^2) in worst case
   *
   * SC -> O(1)
   */
};

const containsDuplicateBetter = function (nums) {
  /**
   * we were previously comparing the same elements again and again
   *
   * to prevent this we can use a hashmap
   *
   * Map<num, 1>
   *
   * if the num already exists in the hashMap,
   * it means duplicate number has been found
   * return true
   *
   * even after traversing the entire array
   * if we do not find the duplicate
   * return true
   *
   */

  const hashMap = new Map();

  for (let i = 0; i < nums.length; ++i) {
    if (hashMap.has(nums[i])) {
      return true;
    }

    hashMap.set(nums[i], 1);
  }

  return false;

  /**
   * Complexity Analysis
   *
   * TC: best case -> O(N)
   *    worst case -> O(N^2) (if heavy collisions occur, very very rare)
   *
   * SC: O(N)
   */
};

const containsDuplicateOptimal = function (nums = [], alreadySorted = false) {
  if (!alreadySorted) {
    // in-place sorting
    nums.sort((a, b) => a - b);

    // have to create new array if the order is need to be preserved
  }

  for (let i = 0; i < nums.length - 1; ++i) {
    if (nums[i] == nums[i + 1]) return true;
  }

  return false;

  /**
   * Complexity Analysis
   *
   * if array is already sorted
   *
   * TC: O(N)
   * SC: O(1)
   *
   *
   * if array is unsorted or not provided and detail regarding it
   *
   * TC: O(NlogN) + O(N)
   * SC: O(1)
   */
};

let arr;
// arr = [1,1,1,3,3,4,3,2,4,2]; // expected -> true
arr = [1, 2, 3, 4]; // expected -> false

// console.log("contains duplicate(brute): ", containsDuplicateBrute(arr));

console.log("contains duplicate(optimal): ", containsDuplicateBetter(arr));

// console.log("contains duplicate(optimal): ", containsDuplicateOptimal(arr));

return;
