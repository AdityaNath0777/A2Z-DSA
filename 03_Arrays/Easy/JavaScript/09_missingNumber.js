/**
 * Problem Statement: Given an array nums containing n distinct numbers  in the range [0, n],
 *                    return the only number in the range
 *                    that is missing from the array.
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
const missingNumberBrute = function (nums) {
  const n = nums.length;

  for (let i = 0; i <= n; ++i) {
    // to pick the number in the range [0,1]
    let targetFound = false;
    // Linear Search
    for (let j = 0; j < n; ++j) {
      if (nums[j] === i) {
        targetFound = true;
        break;
      }
    }

    if (!targetFound) return i;
  }

  /**
   * TC -> O(N^2)
   * SC -> O(1)
   */
};

const missingNumberBetter = function (nums) {
  const n = nums.length;

  let hashMap = {}; // hashMap to store the elements

  for (let i = 0; i < n; ++i) {
    hashMap[nums[i]] = true;
  }

  for (let i = 0; i <= n; ++i) {
    // if i not found in the hashMap,
    // it is the missing number
    if (!hashMap[i] ?? true) {
      return i;
    }
  }

  /**
   * TC -> O(2N) ~ O(N)
   * Sc -> O(N)
   */
};

const missingNumberBetter_usingSort = function (nums) {
  const n = nums.length;
  let temp = [...nums];

  temp.sort((a, b) => a - b);
  let missingNum = -1;

  for (let i = 0; i < n; ++i) {
    if (temp[i] === i) continue;

    missingNum = i;
    break;
  }

  if (missingNum === -1) return n;
  return missingNum;
  /**
   * TC -> O(NlogN + N) ~ O(NlogN)
   * Sc -> O(N)
   */
};

const missingNumberOptimal_sum = function (nums) {
  let arraySum = 0;
  let actualSum = 0;
  for (let i = 0; i < nums.length; ++i) {
    arraySum += nums[i];
    actualSum += i;
  }
  
  actualSum += nums.length;

  return actualSum - arraySum;
};

const missingNumberOptimal_xor = function (nums) {
  let xor_arr = 0;
  let xor_num = 0;

  for(let i=0; i<nums.length; ++i) {
    xor_arr = xor_arr ^ nums[i];
    xor_num = xor_num ^ i;
  }

  xor_num = xor_num ^ nums.length;

  return xor_num ^ xor_arr;
}

let arr = [
  45, 35, 38, 13, 12, 23, 48, 15, 44, 21, 43, 26, 6, 37, 1, 19, 22, 3, 11, 32,
  4, 16, 28, 49, 29, 36, 33, 8, 9, 39, 46, 17, 41, 7, 2, 5, 27, 20, 40, 34, 30,
  25, 47, 0, 31, 42, 24, 10, 14,
];

console.log("Missing number(brute): ", missingNumberBrute(arr));
console.log("Missing number(better): ", missingNumberBetter(arr));
console.log(
  "Missing number(better using sort): ",
  missingNumberBetter_usingSort(arr)
);
console.log("Missing number(optimal sum): ", missingNumberOptimal_sum(arr));
console.log("Missing number(optimal xor): ", missingNumberOptimal_xor(arr));
