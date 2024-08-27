/*
 * Problem Statement: 
 * 
 * Given an array of N integers. 
 * Every number in the array except one appears twice. 
 * 
 * Find the single number in the array.
 */

#include <bits/stdc++.h>
using namespace std;

// brute force -> Linear Search
int findNonDuplicateElement_brute_1(vector<int>& nums){
  int n = nums.size();

  // if empty array
  if(n == 0) return -1;

  // if array with single Element
  if(n == 1) return nums[0];

  // if array with 2 non-duplicate elements
  if(nums[0] != nums[1]) return nums[0];

  // find non-duplicate in rest of the elements
  for(int i=1; i<n; ++i){

    // if left & right adjacent element of the current element are different
    // then current one is non-duplicate element
    if(nums[i] != nums[i-1] && nums[i] != nums[i+1])
      return nums[i];
  }

  // total TC -> O(N)
  // total SC -> O(1)
  return -1;
}

// brute force -> using XOR
int findNonDuplicateElement_brute_2(vector<int>& nums){
  // xor of same elements is -> ZERO
  // xor of any element with ZERO is -> that element itself

  int xor1 = 0;

  for(int i=0; i<nums.size(); ++i){
    xor1 = xor1 ^ nums[i];
  }

  // total TC -> O(N)
  // total SC -> O(1)
  return xor1;
}

// optimal -> using Binary Search
int findNonDuplicateElement_optimal(vector<int>& nums){
  int n = nums.size();
  
  if(n == 0) return -1;

  if(n == 1) return nums[0];

  if(nums[0] != nums[1]) return nums[0];

  if(nums[n-1] != nums[n-2]) return nums[n-1];

  int low = 1;
  int high = n - 2;

  while(low <= high){
    int mid = low + (high - low)/2;

    // if mid is duplicate
    if(nums[mid] == nums[mid + 1]){
      // let's eliminate
      // first we need to know where our non-duplicate element might exist

      // for that

      if(mid % 2 == 0){
        // non-duplicate might exist right side
        // we will eliminate left side
        low = mid + 1;
      }
      // eliminate right side
      else {
        high = mid - 1;
      }
    }

    else if(nums[mid] == nums[mid - 1]){

      if(mid % 2 == 0){
        // non duplicate might exist left side
        // eliminate right side
        high = mid - 1;
      }
      else {
        low = mid + 1;
      }
    }

    else return nums[mid];
  }

  // total TC -> O(log2(N))
  // total SC -> O(1)
  return -1;
}

// compact version of above optimal code with compact if statements
int findNonDuplicateElement_optimal_compactCode(vector<int>& nums){
  int n = nums.size();
  
  if(n == 0) return -1;

  if(n == 1) return nums[0];
  if(nums[0] != nums[1]) return nums[0];
  if(nums[n-1] != nums[n-2]) return nums[n-1];

  int low = 1;
  int high = n - 2;

  while(low <= high){
    int mid = low + (high - low)/2;

    // if left & right of mid are not same
    if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid + 1]){
      return nums[mid];
    }

    
    else if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || 
            (mid%2 != 0 && nums[mid] == nums[mid - 1])) {

          // eliminate left
          low = mid + 1;
    }

    else {
      // eliminate right
      high = mid - 1;
    }
  }

  // total TC -> O(log2(N))
  // total SC -> O(1)
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


  int singleElement;

  // singleElement = findNonDuplicateElement_brute_1(v);
  // singleElement = findNonDuplicateElement_brute_2(v);
  // singleElement = findNonDuplicateElement_optimal(v);
  singleElement = findNonDuplicateElement_optimal_compactCode(v);

  cout << singleElement;

return 0;
}