/**
 * Problem Statement: Find All Numbers Disappeared in an Array
 *
 * Given an array nums of n integers
 * where nums[i] is in the range [1, n],
 *
 * return an array of all the integers
 * in the range [1, n]
 * that do not appear in nums.
 *
 * Note: do not take account of duplicate elements
 *
 * Example 1:
 * Input: nums = [4,3,2,7,8,2,3,1]
 * Output: [5,6]
 *
 * Example 2:
 * Input: nums = [1,1]
 * Output: [2]
 */

// using set
const findDisappearedNumbers_Brute = function (nums) {
  // I also have to deal with duplicates
  // so we can simply use Sets for that

  const numSet = new Set(nums);

  // array to store the missing numbers
  const ans = [];

  // now let's check which number is not in the list

  // as the values inside the array should be [1, N]
  // it means if we have 5 elements the array
  // should be [1, 2, 3, 4, 5] (order may change but not values)
  for (let i = 1; i <= nums.length; ++i) {
    // if the number is not in the set,
    // append it into the answer
    if (!numSet.has(i)) ans.push(i);
  }

  return ans;
};

// using in-place negation
const findDisappearedNumbers_Optimal = function (nums) {
  /**
   * we know the range of the values should be [1, N]
   *
   * the index is [0, N-1]
   *
   * if we subtract 1 from the values' -> we get index's range
   *
   * // get the supposed index of the current value
   * temp = abs(nums[i]) - 1
   *
   * // if value is positive that means it still hasn't been visited
   * if nums[temp] > 0
   *    negate the value as a flag
   *    nums[temp] *= -1
   *
   * // else the duplicate element has already made it negative
   *
   *
   * we are marking (flagging) the values at those indices
   * whose corresponding value is present in the array
   *
   * if the corresponding value is still gt 0 means
   *    that index's corresponding actual value is absent
   *
   * then after negation
   *
   * we will normally iterate through the array
   *  if the nums[i] still > 0
   *      append (i + 1) into the answer
   *
   * return the ans[]
   */
  //

  if (!nums || nums.length === 0) return [];

  for (let i = 0; i < nums.length; ++i) {
    let temp = Math.abs(nums[i]) - 1;

    if (nums[temp] > 0) nums[temp] *= -1;
  }

  const ans = [];

  for (let i = 0; i < nums.length; ++i) {
    if (nums[i] > 0) ans.push(i + 1);
    // re-negate to get back original value
    else nums[i] *= -1;
  }

  return ans;

  /**
   * Complexity Analysis
   *
   * TC: O(N) + O(N)
   *  ~ O(N)
   *
   * SC: O(k), k-> no. of missing numbers
   */
};

let arr;
arr = [4, 3, 2, 7, 8, 2, 3, 1];

console.log("arr: ", arr);

console.log("\ndisappeared elements: ", findDisappearedNumbers_Brute(arr));
console.log("\ndisappeared elements: ", findDisappearedNumbers_Optimal(arr));
