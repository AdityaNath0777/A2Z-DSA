/**
 * Problem Statement: Given an array containing both positive and negative integers,
 *         we have to find the length of the longest subarray
 *         with the sum of all elements equal to zero.
 *
 *
 * Example 1:
 *    Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
 *    Result: 5
 *
 *    Explanation: The following subarrays sum to zero:
 *    {-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
 *    Since we require the length of the longest subarray, our answer is 5!
 */

function longestSubarraySum_Brute(nums = [], target = 0) {
  let n = nums.length;

  let maxLen = -1;

  for (let i = 0; i < n; ++i) {
    for (let j = i; j < n; ++j) {
      let sum = 0;

      for (let k = i; k <= j; ++k) {
        sum += nums[k];
      }

      if (sum === target) {
        let len = j - i + 1;
        maxLen = Math.max(maxLen, len);
      }
    }
  }

  return maxLen;

  /**
   * Complexity Analysis
   *
   * TC: O(N^3)
   * SC: O(1)
   */
}

function longestSubarraySum_Better(nums = [], target = 0) {
  let n = nums.length;

  let maxLen = -1;

  for (let i = 0; i < n; ++i) {
    let currentSum = 0; // reset for each new starting point
    for (let j = i; j < n; ++j) {
      currentSum += nums[j]; // accumulating the sum

      if (currentSum == 0) {
        let len = j - i + 1;
        maxLen = Math.max(maxLen, len);
      }
    }
  }

  return maxLen;

  /**
   * Complexity Analysis
   *
   * TC: O(N^2)
   * SC: O(1)
   */
}

const arr = [9, -3, 3, -1, 6, -5];

let ans;

ans = longestSubarraySum_Brute(arr);
console.log("brute ans: %d", ans);

ans = longestSubarraySum_Better(arr);
console.log("better ans: %d", ans);
