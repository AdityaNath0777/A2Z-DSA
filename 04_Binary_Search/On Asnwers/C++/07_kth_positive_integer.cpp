/**
 * Problem Statement: 
 * 
 * You are given a strictly increasing array ‘vec’ and a positive integer 'k'. 
 * Find the 'kth' positive integer missing from 'vec'.
*/

#include <bits/stdc++.h>
using namespace std;

// linear search to find
bool isNumberFound_brute(vector<int>& nums, const int& target){
  int n = nums.size();

  int i=0;
  while(nums[i] <= target && i<n){
    if(nums[i] == target)
      return true;
    ++i;
  }

  return false;
}

// binary search to find
bool isNumberFound_optimal(vector<int>& nums, const int& target){
  int n = nums.size();
  int low = 0;
  int high = n - 1;

  while(low <= high){
    int mid = low + (high - low)/2;

    if(nums[mid] == target)
      return true;

    if(nums[mid] > target){
      high = mid - 1;
    }

    else low = mid + 1;
  }

  return false;
}

// brute force
int find_kth_missing_integer_my_brute(vector<int>& nums, const int& k){

  int n = nums.size();

  int maxi = *max_element(nums.begin(), nums.end());

  int cnt = 0;
  for(int i = 1; i<= maxi; ++i){ // TC -> O(MaxiElement)

    // TC -> O(logN)
    if(! isNumberFound_optimal(nums, i)){
      cnt++;
    }

    if(cnt == k)
      return i;
  }

  // if 1 to maxi all are present
  // return maxi + k;

  // if less than k are missing
  return maxi + k - cnt;

  // total TC -> O(MaxiElement * logN)
  // total SC -> O(1)
}

// brute force -> Linear Search
int find_kth_missing_integer_better(vector<int>& nums, int k) {

  int n = nums.size();

  for (int i = 0; i < n; i++) {
    if (nums[i] <= k) k++; //shifting k
    else break;
  }

    // total TC -> O(N)
    // total SC -> O(1)
    return k;
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  int k;
  cin >> k;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }


  int kthMissingNum;

  // kthMissingNum = find_kth_missing_integer_my_brute(v, k);
  kthMissingNum = find_kth_missing_integer_better(v, k);

  cout << "kth missing positive integer is: " << kthMissingNum;

return 0;
}