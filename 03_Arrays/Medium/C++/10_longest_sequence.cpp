/*
  Problem Statement: 
  
  You are given an array of ‘N’ integers. 
  You need to find the length of the longest sequence 
  which contains the consecutive elements.
*/

#include <bits/stdc++.h>
using namespace std;

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

  for(int i=0; i<n; ++i){
    int num = nums[i];
    int cnt = 1;

    // search using linear search
    while(linearSearch(nums, num+1)){
      num += 1;
      cnt++;
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

  int maxSeqLength = longestSuccessiveElements_brute(v);

  cout << maxSeqLength << endl;
return 0;
}