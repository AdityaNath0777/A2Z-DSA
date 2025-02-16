/**
 * Problem Statement: Given the array nums, for each nums[i]
 *      find out how many numbers in the array are smaller than it.
 *
 *      Return the answer in an array.
 */

const smallerNumbersThanCurrentBrute = function (nums = []) {
  const n = nums.length;

  let count = new Array(n);
  for (let i = 0; i < n; ++i) count[i] = 0; // O(N)

  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < n; ++j) {
      if (i != j && nums[i] > nums[j]) {
        count[i]++;
      }
    }
  }

  /**
   * TC -> O(N^2)
   * SC -> O(N)
   */
  return count;
};

const smallerNumbersThanCurrentBetter = function (nums = []) {
  if (nums.length === 0) throw new Error("Array is empty");

  const n = nums.length;

  // O(NlogN)
  const sortedNums = [...nums].sort((a, b) => a - b); // create a copy and sort in ascending order

  let counts = new Array(n);
  let hashMap = new Map();

  for (let i = 0; i < n; ++i) {
    // O(N)
    if (!hashMap.has(sortedNums[i])) {
      hashMap.set(sortedNums[i], i);
    }
  }

  for (let i = 0; i < n; ++i) {
    // O(N)
    counts[i] = hashMap.get(nums[i]);
  }

  /**
   * TC -> O(NlogN + N + N)
   *   ~ O(NlogN)
   * SC -> O(3N) ~ O(N)
   */
  return counts;
};

/**
 * We've given the value range between: 0 to 100
 *
 * thus we can create a hash map using Array for faster iteration & frequency count
 */
const smallerNumbersThanCurrentOptimal = function (nums = []) {
  if (nums.length === 0) throw new Error("Array is empty!");

  const n = nums.length;

  const maxVal = Math.max(...nums);

  let freqCounts = new Array(maxVal + 1);
  for (let i = 0; i < maxVal; ++i) freqCounts[i] = 0;
  // let freqCounts = new Array(maxVal+1).fill(0);

  for (let i = 0; i < n; ++i) {
    // freq count
    ++freqCounts[nums[i]];
  }

  for (let i = 1; i <= maxVal; ++i) {
    // add the counts
    freqCounts[i] += freqCounts[i - 1];
  }

  // now we've a sorted hashMap in the form of array
  // where index (which is obv sorted) maps to the nums' values
  // and count[index] maps to their freq
  let ans = new Array(n);
  for (let i = 0; i < n; ++i) {
    ans[i] = nums[i] === 0 ? 0 : freqCounts[nums[i] - 1];
  }

  return ans;
};

let arr = [8, 1, 2, 2, 3];

var ans = smallerNumbersThanCurrentBrute(arr);
console.log("count []: ", ans);

var ans = smallerNumbersThanCurrentBetter(arr);
console.log("count []: ", ans);

var ans = smallerNumbersThanCurrentOptimal(arr);
console.log("count []: ", ans);
