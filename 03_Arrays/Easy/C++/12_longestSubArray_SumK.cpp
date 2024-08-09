// Problem Statement: Given an array and a sum k,
//        we need to print the length of the longest subarray that sums to k.

#include <bits/stdc++.h>
using namespace std;

int longestSubArray_SumK_brute(vector<int>& nums, long long k){
  /*
  
  // Note -> array might be unsorted, below is just an example
  nums[] = [ 1 2 3 4 5 6 7 8 ]

  k = 6

  brute force:

  k = 6
  n = 8 (len of nums[])

  subArray -> consecutive elements

  maxi = 0
  for i = [0, n-1] {

    sum = nums[i];

    for j = [i+1, n-1] {
      sum += nums[j]

      if ( sum == k ){
        maxi = max(maxi, j-i)
      }
      else ( sum < k ){
        // do nothing
      }
      else ( sum > k ){
        break
      }
    }

    return maxi
  }

  
  */


  int n = nums.size();
  int maxi = 0;
  
  for (int i=0; i<n; ++i){
    long long sum = 0;
    for (int j = i; j<n; ++j){
      sum += nums[j];

      if ( sum == k ){
        maxi = max(maxi, j-i+1);
      }
      else if ( sum > k ) break;
    }
  }

  return maxi;

  /*
      total TC -> O(N^2)
      total SC -> O(1)
  */
}

int longestSubArray_SumK_optimal(vector<int>& nums, long long k){
  int n = nums.size();

  // hashing using map -> <sum, index>
  int maxLen = 0;
  map<long long, int> preSumMap;
  long long sum = 0;

  for (int i=0; i<n; ++i){
    sum += nums[i];

    if (sum == k){
      maxLen = max(maxLen, i+1);
    }

    long long rem = sum - k;

    if (preSumMap.find(rem) != preSumMap.end()) {
      int len = i - preSumMap[rem];
      maxLen = max(maxLen, len);
    }
    
    if (preSumMap.find(sum) == preSumMap.end()){
      preSumMap[sum] = i;
    }

  }

  /*
      total TC -> O(N)
      total SC -> O(N)
  */

  return maxLen;
}

int longestSubArray_SumK_optimal_positive(vector<int>& nums, long long k){
  int maxLen = 0;
  int n = nums.size();

  int left = 0;
  int right = 0;
  long long sum = nums[0];
  
  while( right < n ){
    while( left <= right && sum > k ){
      sum -= nums[left];
      left++;
    }
  }
  return maxLen;
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

  long long k;
  cin >> k;

  // int len = longestSubArray_SumK_brute(v, k);
  // int len = longestSubArray_SumK_optimal(v, k);
  int len = longestSubArray_SumK_optimal_positive(v, k);
  cout << len;
return 0;
}