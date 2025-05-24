/**
 * Problem Statement: Two Sum
 *
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers
 * such that they add up to target.
 *
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 *
 * You can return the answer in any order.
 */

function twoSumBrute(arr, target) {
  // arr loop

  // first loop -> pick each element
  // second loop -> adds picked element with each elem one by one
  // -> compares with the target
  // -> if matched -> return indices

  for (let i = 0; i < arr.length; ++i) {
    for (let j = 0; j < arr.length; ++j) {
      if (i !== j && arr[i] + arr[j] === target) return [i, j];
    }
  }

  /**
   * Complexity Analysis
   * 
   * TC: O(N^2)
   * SC: O(1)
   */

  return [-1, -1];
}

function twoSumBetter(arr, target) {

  // in previous version we were add and comparing the numbers more than once
  // so what we can do is to cache the result by storing it in a map like data structure

  const numMap = new Map();

  for (let i = 0; i < arr.length; ++i) {
    // here we also need to store the index
    // one index would be of the current element
    // one index will be from the map

    // Map<num , index>

    // num ?

    // num1 + num2 = target

    // num1 = target - num2
    // num2 = target - num1

    // if we have index of num1, we need to find index of num2
    // similarly, if we have index of num2, we need to find index of num1

    // if we have index of num1, we cannot calculate num2
    // but if we have index of num2 we can calculate the num1

    // missing index here is of the num1
    // so we can store and cache this num1 and it's index using Map

    // Now we know what kind of values we should have in the map
    // to get the index we will store the value as the key

    // next is the logic how we are going to check this sum

    // first thing is first calculate the number we need to find(num1)

    const num = target - arr[i];

    // we will check whether this number is available in the map to sum up with the current number to result the target

    if (numMap.has(num)) {
      return [i, numMap.get(num)];
    }

    // if not then in the next iteration we will use the current number as the num1
    // so we will store this number and index in the map
    numMap.set(arr[i], i);
  }


  return [-1, -1];

  /**
   * Complexity Analysis
   *
   * TC: O(N) -> arr | Map, O(1)
   *   total TC: O(N)*O(1) = O(N)
   * SC: O(N) -> aux. space
   *  
   */
}

let arr = [1, 2, 3, 4, 5, 9, 10, 12, 21, 12];
const target = 8;
console.log("target: ", target);
console.log("arr: ", arr);

res = twoSumBrute(arr, target);

console.log("\ntwo sum(brute): ", res);
if (res[0] != -1) {
  console.log("values are: ", arr[res[0]], ", ", arr[res[1]]);
}

return;
