/**
 * Problem Statement:
 * Given an array of N integers, count the inversion of the array.
 *
 * An inversion is a pair of indices (i, j) such such that i < j and arr[i] > arr[j].
 *
 * Example 1:
 *  Input Format: N = 5, array[] = {1,2,3,4,5}
 *  Result: 0
 *  Explanation: we have a sorted array and the sorted array has 0 inversions
 *  as for i < j you will never find a pair such that A[j] < A[i].
 *
 *  More clear example:
 *  2 has index 1 and 5 has index 4
 *  now 1 < 5 but 2 < 5
 *  so this is not an inversion.
 *
 *  Input Format: N = 5, array[] = {5,4,3,2,1}
 *  Result: 10
 *  Explanation: we have a reverse sorted array and we will get the maximum inversions
 *  as for i < j we will always find a pair such that A[j] < A[i].
 *
 *  Example: 5 has index 0 and 3 has index 2 now (5,3) pair is inversion
 *  as 0 < 2 and 5 > 3 which will satisfy out conditions
 *  and for reverse sorted array we will get maximum inversions
 *  and that is (n)*(n-1) / 2.
 *
 *  For above given array there is 4 + 3 + 2 + 1 = 10 inversions.
 */

/**
 *
 * @param {number[]} nums
 * @returns count of inversions
 */
function countInversions_Brute(nums) {
  const n = nums.length;
  let count = 0;

  for (let i = 0; i < n; ++i) {
    for (let j = i + 1; j < n; ++j) {
      if (nums[i] > nums[j]) ++count;
    }
  }

  return count;

  /**
   * Complexity Analysis
   *
   * TC: O(N^2)
   * SC: O(1)
   */
}

/**
 *
 * @param {number[]} nums
 * @param {number} low
 * @param {number} mid
 * @param {number} high
 * @returns count of inversions after merging
 */
function mergeAndCount(nums, low, mid, high) {
  let count = 0;

  let temp = [];
  let left = low;
  let right = mid + 1;

  while (left <= mid && right <= high) {
    if (nums[left] <= nums[right]) {
      temp.push(nums[left++]);
    } else {
      count += mid - left + 1;
      temp.push(nums[right++]);
    }
  }

  while (left <= mid) {
    temp.push(nums[left++]);
  }

  while (right <= high) {
    temp.push(nums[right++]);
  }

  // copying the sorted array into original array
  for (let i = low; i <= high; ++i) {
    nums[i] = temp[i - low];
  }

  return count;
}

/**
 *
 * @param {number[]} nums
 * @param {number} low
 * @param {number} high
 * @returns total count of inversions
 */
function mergeSortCountInversions(nums, low, high) {
  let count = 0;
  if (low >= high) return count;

  let mid = Math.floor(low + (high - low) / 2);

  // to divide and traversing left half
  count += mergeSortCountInversions(nums, low, mid);

  // to divide and traversing right half
  count += mergeSortCountInversions(nums, mid + 1, high);

  // combining the inversions among both halves
  count += mergeAndCount(nums, low, mid, high);
  return count;
}

/**
 *
 * @param {number[]} nums
 * @returns count of inversions
 */
function countInversions_Optimal(nums) {
  return mergeSortCountInversions(nums, 0, nums.length - 1);
}

const arr1 = [1, 2, 3, 4, 5];
const arr2 = [5, 4, 3, 2, 1];

let ans;

ans = countInversions_Brute(arr1);
console.log(`count of inversions (brute): `, ans);

ans = countInversions_Brute(arr2);
console.log(`count of inversions (brute): `, ans);

console.log("\n\n\n");

ans = countInversions_Optimal(arr1);
console.log(`count of inversions (optimal): `, ans);
ans = countInversions_Optimal(arr2);
console.log(`count of inversions (optimal): `, ans);
