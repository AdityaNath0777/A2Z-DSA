/*
  Problem Statement: Given an integer array arr, 
      find the contiguous subarray (containing at least one number) 
      which has the largest sum 
      and returns its sum and prints the subarray.
*/

#include <bits/stdc++.h>
using namespace std;

// brute -> TC -> O(N^3)
long long maxSubArraySum_brute(vector<int>& nums){
  long long maxi = LONG_LONG_MIN; 

  for(int i=0; i<nums.size(); ++i){
    for(int j=i; j<nums.size(); ++j){
      long long sum = 0;
      
      for(int k=i; k<=j; ++k){
        sum += nums[k];
      }

      maxi = max(maxi, sum);
    }
  }

  return maxi;
}

// better -> TC -> O(N^2)
long long maxSubArraySum_better(vector<int>& nums){
  long long maxi = LONG_LONG_MIN; 

  for(int i=0; i<nums.size(); ++i){
    long long sum = 0;
    for(int j=i; j<nums.size(); ++j){
      sum += nums[j];

      maxi = max(maxi, sum);
    }
  }

  return maxi;
}

// optimal -> TC -> O(N)
//        -> SC -> O(1)
long long maxSubArraySum_optimal(vector<int>& nums){
  long long maxi = LONG_LONG_MIN;
  long long sum = 0;

  for(int i=0; i<nums.size(); ++i){
    // sum
    sum += nums[i];

    // store the maximum value
    maxi = max(maxi, sum);    

    // if sum is already -ve
    // and we encounter another -ve, it will only decrease the sum
    // hence, reset the sum
    if(sum < 0)
      sum = 0;

  }

  return maxi;
}

// follow up: print the subarray with maxSum
long long maxSubArraySum_optimal_Print(vector<int>& nums){
  long long maxi = LONG_LONG_MIN;
  long long sum = 0;

  int start = 0;
  int ansStart = -1;
  int ansEnd = -1;
  for(int i=0; i<nums.size(); ++i){
    if(sum == 0){
      start = i;
    }
    
    sum += nums[i];

    if(sum > maxi){
      maxi = sum;

      ansStart = start;
      ansEnd = i;
    }

    if(sum < 0){
      sum = 0;
    }

  }

  cout << "The subarray with maximum sum is: [";
  for(int i=ansStart; i<=ansEnd; ++i){
    cout << nums[i] << " ";
  }
  cout << "]" << endl;

  return maxi;
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin>>size;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }

  // long long maxSum = maxSubArraySum_brute(v);
  // int maxSum = maxSubArraySum_better(v);
  // int maxSum = maxSubArraySum_optimal(v);
  int maxSum = maxSubArraySum_optimal_Print(v);

  cout << maxSum;
return 0;
}