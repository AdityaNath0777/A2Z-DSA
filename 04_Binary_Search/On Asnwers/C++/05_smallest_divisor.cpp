/**
 * Problem Statement: 
 * 
 * You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. 
 * Your task is to find the smallest positive integer divisor, 
 * such that upon dividing all the elements of the given array by it, 
 * the sum of the division's result is less than or equal to the given threshold value.
 */

#include <bits/stdc++.h>
using namespace std;

// brute force -> Linear Search
int findSmallestDivisor_my_brute(vector<int>& nums, const int& threshold){
  int ans = -1;
  
  int n = nums.size();

  int maxi = INT_MIN;
  for(int i=0; i<n; ++i){
    maxi = max(maxi, nums[i]);
  }

  for(int val = 1; val <= maxi; ++val){
    int sum = 0;
    cout << "val: " << val << "\n"
         << "result is: ";
    for(int i=0; i<n; ++i){
      int result = ceil((double)nums[i] / val);
      cout << result << ", ";
      sum += result;
    }

    cout << "\n sum: " << sum << "\n" << endl;
    if(sum <= threshold){
      ans = val;
      break;
    }
  }

  // total TC -> O(N*MaximumElement)
  // total SC -> O(1)
  return ans;
}

int findDivisonSum(vector<int>& nums, const int& divisor){
  int n = nums.size();

  int sum = 0;

  for(int i=0; i<n; ++i){
    int result = ceil((double)nums[i] / divisor);

    sum += result;
  }

  return sum;
}

// optimal -> Binary Search
int findSmallestDivisor_my_optimal(vector<int>& nums, const int& threshold){
  int n = nums.size();

  int ans = -1;

  int maxi = INT_MIN;
  for(int i=0; i<n; ++i){
    maxi = max(maxi, nums[i]);
  }

  int low = 1;
  int high = maxi;

  while(low <= high){
    int mid = low + (high - low)/2;


    int sum = findDivisonSum(nums, mid);

    cout << "mid : " << mid << "\t" << " sum : " << sum << "\n";

    if(sum <= threshold){
      ans = mid;
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }

  // total TC -> O(N*log2(maximumELement))
  // total SC -> O(1)
  return ans;
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  int threshold;
  cin >> threshold;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }


  int smallestDivisor;

  // smallestDivisor = findSmallestDivisor_my_brute(v, threshold);
  smallestDivisor = findSmallestDivisor_my_optimal(v, threshold);

  cout << "Smallest divisor for threshold " << threshold << " is: " << smallestDivisor;  

return 0;
}