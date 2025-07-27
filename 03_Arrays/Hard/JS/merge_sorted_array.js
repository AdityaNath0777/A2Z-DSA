/**
 * Problem statement:
 *
 * Type 1
 *
 * Given two sorted arrays arr1[] and arr2[]
 * of sizes m and n in non-decreasing order.
 * Merge them in sorted order.
 * Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
 *
 * Input:
 * m = 4, arr1[] = [1 4 8 10]
 * n = 3, arr2[] = [2 3 9]
 *
 * Output:
 * arr1[] = [1 2 3 4]
 * arr2[] = [8 9 10]
 *
 * Explanation:
 * After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.
 *
 *
 * Type 2
 *
 * Given two sorted arrays arr1[] and arr2[] of sizes m+n and m in non-decreasing order.
 * Merge them in sorted order.
 * Modify arr1 so that it contains the merged sorted elements from both array
 *
 *
 * Input:
 * m = 4, arr1[] = [1 4 8 10 0 0 0]
 * n = 3, arr2[] = [2 3 9]
 *
 * Output:
 * arr1[] = [1 2 3 4 8 9 10]
 *
 * Explanation:
 * After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.
 *
 */

function merge_type1_brute(nums1, m, nums2, n) {
  let temp = new Array(m + n).fill(0);
  let left = 0;
  let right = 0;
  let i = 0;

  while (left < m && right < n) {
    if (nums1[left] <= nums2[right]) {
      temp[i++] = nums1[left++];
    } else {
      temp[i++] = nums2[right++];
    }
  }

  while (right < n) {
    temp[i++] = nums2[right++];
  }

  while (left < m) {
    temp[i++] = nums1[left++];
  }

  for (let k = 0; k < n + m; ++k) {
    if (k < m) nums1[k] = temp[k];
    else nums2[k - m] = temp[k];
  }

  return;

  /**
   * Complexity Analysis
   *
   * TC: O(m + n)
   * SC: O(m + n)
   */
}

function merge_type1_optimal(nums1, m, nums2, n) {
  let left = m - 1;
  let right = 0;

  while (left >= 0 && right < n) {
    if (nums1[left] > nums2[right]) {
      let temp = nums2[right];
      nums2[right] = nums1[left];
      nums1[left] = temp;

      --left;
      ++right;
    } else {
      break;
    }
  }

  nums1.sort((a, b) => a - b);
  nums2.sort((a, b) => a - b);

  return;

  /**
   * Complexity Analysis
   *
   * TC: O(m + n)
   * SC: O(m + n)
   */
}

function merge_type2_brute(nums1, m, nums2, n) {
  let temp = new Array(m + n).fill(0);
  let left = 0;
  let right = 0;
  let i = 0;

  while (left < m && right < n) {
    if (nums1[left] <= nums2[right]) {
      temp[i++] = nums1[left++];
    } else {
      temp[i++] = nums2[right++];
    }
  }

  while (right < n) {
    temp[i++] = nums2[right++];
  }

  while (left < m) {
    temp[i++] = nums1[left++];
  }

  for (let k = 0; k < n + m; ++k) {
    nums1[k] = temp[k];
  }

  return;

  /**
   * Complexity Analysis
   *
   * TC: O(m + n)
   * SC: O(m + n)
   */
}

function merge_type2_optimal(nums1, m, nums2, n) {
  for (let i = m; i < m + n; ++i) {
    nums1[i] = nums2[i - m];
  }

  nums1.sort((a, b) => a - b);

  return;

  /**
   * let p = m + n
   *
   * TC: O(pLogp)
   * SC: O(1)
   */
}

// --- for type 1 ----
// let arr1 = [20, 23, 28, 30];
// let m = 4;
// let arr2 = [2, 3, 9];
// let n = 3;

let arr1 = [2, 3, 25];
let arr2 = [20, 23, 28, 30];
let m = 3;
let n = 4;

console.log("Type 1");

merge_type1_optimal(arr1, m, arr2, n);
console.log("Merge sorted array optimal: ", arr1, arr2);

console.log("\n\n");

// --- for type 2 ---
arr1 = [1, 4, 8, 10, 0, 0, 0];
m = 4;
arr2 = [2, 3, 9];
n = 3;
console.log("Type 2");

merge_type2_optimal(arr1, m, arr2, n);
console.log("Merge sorted array optimal: ", arr1, arr2);
