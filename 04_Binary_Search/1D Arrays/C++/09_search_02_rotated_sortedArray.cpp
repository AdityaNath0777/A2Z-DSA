/*
 * Problem Statement: 
 * Given an integer array arr of size N, sorted in ascending order 
 * (may contain duplicate values) 
 * and a target value k. 
 * 
 * Now the array is rotated at some pivot point unknown to you. 
 * Return True if k is present and otherwise, return False. 
*/

#include <bits/stdc++.h>
using namespace std;

// brute force -> using Linear Search
bool searchRotatedDuplcates_brute(vector<int>& nums, const int &target){
  int n = nums.size();

  for(int i=0; i<n; ++i){
    if(nums[i] == target)
      return true;
  }

  // total TC -> O(N)
  // total SC -> O(1)

  return false;
}

// optimal -> using binary search with edge cases
bool searchRotatedDuplcates_optimal(vector<int>& nums, const int &target){
  int n = nums.size();
  int low = 0;
  int high = n-1;

  while(low <= high){
    int mid = low + (high - low)/2;

    if(nums[mid] == target) return true;

    // if low, mid & high, they all point at duplicates of same value
    // while(nums[low] == nums[mid] && nums[mid] == nums[high]){
    //   low += 1;
    //   high -= 1;
    // }

    // OR
    if(nums[low] == nums[mid] && nums[mid] == nums[high]){
      low += 1;
      high -= 1;
      continue;
    }

    // if left sorted
    if(nums[low] <= nums[mid]){
      // if might lie in left sorted range
      if(nums[low] <= target && target <= nums[high]){
        // move left
        high = mid - 1;
      }
      else low = mid + 1;

    }

    // if right sorted
    else {
      // if might lie b/w right sorted
      if(nums[mid + 1] <= target && target <= nums[high]){
        // move right
        low = mid + 1;
      }
      else high = mid - 1;
    }
  }

  // total TC -> avg case -> O(log2(N))
  //          -> worst case -> O(N/2) 
                  // -> if low, mid & high almost always point at duplicates of same val
  
  // total SC -> O(1)
  return false;
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

  int isFound;

  // isFound = searchRotatedDuplcates_brute(v, target);
  isFound = searchRotatedDuplcates_optimal(v, target);

  if(isFound)
    cout << "Target found";
  else cout << "Target NOT found";

return 0;
}