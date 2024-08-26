/*
 *  Problem Statement: 
 *  
 *  Given an integer array arr of size N, sorted in ascending order (with distinct values). 
 *  Now the array is rotated between 1 to N times which is unknown. 
 * 
 *  Find the minimum element in the array. 
*/

#include <bits/stdc++.h>
using namespace std;

// brute force -> using Linear Search
int findMin_RotatedSortedArray_brute(vector<int>& nums){
  int n = nums.size();

  int mini = INT_MAX;

  for(int i=0; i<n; ++i){
    mini = min(mini, nums[i]);
  }

  // total TC -> O(N)
  // total SC -> O(1)
  return mini;
}

// better -> using Binary Search
int findMin_RotatedSortedArray_better(vector<int>& nums){
  int n = nums.size();

  int low = 0;
  int high = n - 1;
  int mini = INT_MAX;

  while(low <= high){
    int mid = low + (high - low)/2;

    // left sorted
    if(nums[low] <= nums[mid]){
      mini = min(nums[low], mini);

      // move right
      low = mid + 1;
    }

    // right sorted
    else {
      mini = min(nums[mid], mini);

      // move left
      high = mid - 1;
    }
  }

  // total TC -> O(log2(N))
  // total SC -> O(1)
  return mini;
}

// optimal -> same as better with lil' optimization
int findMin_RotatedSortedArray_optimal(vector<int>& nums){
  int n = nums.size();

  int low = 0;
  int high = n-1;
  int mini = INT_MAX;

  while(low <= high){
    int mid = low + (high - low)/2;

    // if entire array is sorted
    if(nums[low] <= nums[high]){
      mini = min(nums[low], mini);
      break;
    }

    // left sorted
    if(nums[low] <= nums[mid]){
      mini = min(nums[low], mini);

      // eliminate left
      // move right
      low = mid + 1;
    }

    // right sorted
    else {
      mini = min(nums[mid], mini);

      // eliminate right
      // move left
      high = mid - 1;
    }
  }

  // total TC -> O(log2(N))
  // total SC -> O(1)
  return mini;
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

  int minimum;
  // minimum = findMin_RotatedSortedArray_brute(v);
  // minimum = findMin_RotatedSortedArray_better(v);
  minimum = findMin_RotatedSortedArray_optimal(v);

  cout << "Minimum : " << minimum;
return 0;
}