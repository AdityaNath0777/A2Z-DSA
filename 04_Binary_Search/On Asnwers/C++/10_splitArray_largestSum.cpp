/**
 * 
 * Problem Statement: 
 * 
 * Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. 
 * Split the array ‘A’ into ‘K’ non-empty subarrays 
 * such that the largest sum of any subarray is minimized. 
 * 
 * Your task is to return the minimized largest sum of the split.
 * 
 * A subarray is a contiguous part of the array.
*/

#include <bits/stdc++.h>
using namespace std;

/* exactly same approach as Book Allocation */

int countPartitions(vector<int>& nums, int LargestSum){
  int n = nums.size();
  int subarrayCount = 1;
  
  long long mySum = nums[0];

  for(int i=1; i<n; ++i){
    if(mySum + nums[i] <= LargestSum){
      mySum += nums[i];
    }
    else {
      subarrayCount++;
      mySum = nums[i];
    }
  }

  // total TC -> O(N)
  // total SC -> O(1)
  return subarrayCount;
}

int largestSubArraySumMinimized_brute(vector<int>& nums, int k){
  // k => no. of partitions

  int n = nums.size();

  // as we are req. split the array into k 'NON-EMPTY' subarrays
  // so if n > k, we cannot do that 
  if(n < k) return -1;

  int low = *max_element(nums.begin(), nums.end());
  int limit = accumulate(nums.begin(), nums.end(), 0);

  for(int vsum = low; vsum <= limit; ++vsum){
    int noOfpartitions = countPartitions(nums, vsum);

    if(noOfpartitions <= k)
      return vsum;
  }

  // total TC -> O(N * (sum - max of boards[]))
  // total SC -> O(1)
  return -1;
}

int largestSubArraySumMinimized_optimal(vector<int>& nums, int k){
  int n = nums.size();

  if(k > n) return -1;

  int limit = accumulate(nums.begin(), nums.end(), 0);

  int low = *max_element(nums.begin(), nums.end());
  int high = limit;

  while(low <= high){
    int mid = low + (high -  low)/2;

    int partitionCnt = countPartitions(nums, mid);

    if(partitionCnt > k)
      low = mid + 1; 
    else high = mid - 1;
  }

  // cout << low << ", " << high << "\n";

  // total TC -> O(N * log2((sum - max of nums[])))
  // total SC -> O(1)
  return low;
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  int noOfSubArraysToSplit;
  cin >> noOfSubArraysToSplit;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }


  int minLargestSum;
  
  minLargestSum = largestSubArraySumMinimized_brute(v, noOfSubArraysToSplit);
  // minLargestSum = largestSubArraySumMinimized_optimal(v, noOfSubArraysToSplit);

  cout << minLargestSum;

return 0;
}