/*
  Problem Statement: 
  
  You are given an array of ‘N’ integers. 
  You need to find the length of the longest sequence 
  which contains the consecutive elements.
*/

#include <bits/stdc++.h>
using namespace std;

// TC -> O(N)
bool linearSearch(vector<int>& v, int num){
  int n = v.size();

  for(int i=0; i<n; ++i){
    if(v[i] == num)
      return true;
  }

  return false;
}

int longestSuccessiveElements_brute(vector<int>& nums){
  int longest = 1;
  int n = nums.size();

  for(int i=0; i<n; ++i){ // TC -> O(N)
    int num = nums[i];
    int cnt = 1;

    // search using linear search
    // TC -> O(N)*O(N)
    //    ~ O(N^2)
    while(linearSearch(nums, num+1)){
      num += 1;
      cnt++;
    }

    longest = max(longest, cnt);
  }

  // total TC -> O(N^3)
  // total SC -> O(1)
  return longest;
}


int longestSuccessiveElements_better(vector<int>& nums){
  int n = nums.size();

  if(!n) return 0; // 0 length -> empty array/vector

  // sort the array/vector 
  sort(nums.begin(), nums.end());

  int prev = INT_MIN;
  int cnt = 0;
  int longest = 1;


  for(int i=0; i<n; ++i){
    if(nums[i] - 1 == prev){
      cnt++;
      prev = nums[i];
    }
    else if(nums[i] != prev){
      cnt = 0;
      prev = nums[i];
    }

    longest = max(longest, cnt);
  }

  return longest;
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

  int maxSeqLength;
  // maxSeqLength = longestSuccessiveElements_brute(v);
  maxSeqLength = longestSuccessiveElements_better(v);

  cout << maxSeqLength << endl;
return 0;
}