/*
 * Problem Statement: 
 * 
 * Given an array of length N. 
 * Peak element is defined as the element greater than both of its neighbors. 
 * Formally, if 'arr[i]' is the peak element, 
 *      'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. 
 * 
 * Find the index(0-based) of a peak element in the array. 
 * If there are multiple peak numbers, return the index of any peak number.
 */

#include <bits/stdc++.h>
using namespace std;

// brute force -> Linear Search
int findPeakElement_my_brute(vector<int>& nums){
  int n = nums.size();

  if(n==1) return 0;
  if(n==2){
    if(nums[0] > nums[1]) return 0;
    else return 1;
  }

  for(int i=1; i<n-1; ++i){
    if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
      return i;
  }

  // we've given to assume index -1 & n contains val -inf
  // so if we don't get any peak
  // then first & last element will automically be greater than their adjacent -inf 
  // compare them & return the index of greater one
  if(nums[0] > nums[n-1]) return 0;
  else return n-1;

  // total TC -> O(N)
  // total SC -> O(1)
}

int findPeakElement_brute(vector<int>& nums){
  int n = nums.size();

  for(int i=0; i<n; ++i){
    if((i==0 || nums[i] > nums[i-1]) &&
       (i==n-1 || nums[i] > nums[i+1]))
       return i;
  }

  return -1;
}

// optimal -> using Binary Search
int findPeakElement_optimal(vector<int>& nums){
  int n = nums.size();

  if(n==0) return -1;

  if(n == 1) return 0;
  if(n==2){
    if(nums[0] > nums[1]) return 0;
    else return 1;
  }

  int low = 1;
  int high= n-2;

  while (low <= high) {
    int mid = low + (high - low)/2;

    if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
      return mid;

    if(nums[mid] > nums[mid + 1] && nums[mid] < nums[mid - 1]){
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  return -1;
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }

  int peak_index;
  
  // peak_index = findPeakElement_my_brute(v);
  // peak_index = findPeakElement_brute(v);
  peak_index = findPeakElement_optimal(v);

  if(peak_index == -1) cout << "Not found";
  else cout << v[peak_index];

return 0;
}