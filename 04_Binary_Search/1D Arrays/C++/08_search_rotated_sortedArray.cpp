/*
 * Problem Statement: 
 * Given an integer array arr of size N, sorted in ascending order (with distinct values) 
 * and a target value k. 
 * 
 * Now the array is rotated at some pivot point unknown to you. 
 * Find the index at which k is present and if k is not present return -1.
 */

#include <bits/stdc++.h>
using namespace std;

// brute force -> Linear Search
int searchRotatedArray_brute(vector<int>& nums, const int &target){

  for(int i=0; i<nums.size(); ++i)
    if(nums[i] == target)
      return i;

  // target NOT Found
  return -1;
}

// optimal -> using Binary Search
int searchRotatedArray_optimal(vector<int>& nums, const int &target){
  int low = 0;
  int high = nums.size() - 1;

  while(low <= high){
    // find mid-pt.
    int mid = low + (high - low)/2;

    // if target Found -> return position
    if(nums[mid] == target) return mid;

    // if left sorted
    if(nums[low] <= nums[mid]){

      // now check the target might lie b/w which half
      // sorted left?
      //    or
      // unsorted right?
      
      // if lie b/w sorted left
      if(nums[low] <= target && target <= nums[mid]){
        // move towards left
        high = mid - 1;
      }

      // else move right
      else low = mid + 1;
    }

    // else if right sorted
    else {

      // if target lie b/w sorted Right
      if(nums[mid + 1] <= target && target <= nums[high]){
        // move right
        low = mid + 1;
      }

      // else move left
      else {
        high = mid - 1;
      }
    }
  }

  // total TC -> O(log2(N))
  // total SC -> O(1)

  // target NOT Found
  return -1;
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  int target;
  cin >> target;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }

  int ans;

  // using Linear Search
  ans = searchRotatedArray_brute(v, target);

  // using Binary Search
  // ans = searchRotatedArray_optimal(v, target);

  if(ans == -1){
    cout << "Target NOT Found";
  }
  else {
    cout << "Target \"" << target << "\" found at: " 
        << ans;
  }

return 0;
}