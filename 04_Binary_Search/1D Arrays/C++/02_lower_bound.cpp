/*
 *  Problem Statement: 
 *  
 *  Given a sorted array of N integers and an integer x, 
 *  write a program to find the lower bound of x.
 */

#include <bits/stdc++.h>
using namespace std;

// using linear search
int lowerBound_my_brute(vector<int>& nums, int k){
  int n = nums.size();
  int lb = nums.size();

  for(int i=0; i<n; ++i){
    if(nums[i] >= k){
      lb = i;
      break;
    }
  }

  // total TC -> O(N)
  // total SC -> O(1) 
  return lb;
}

// using binary search
int lowerBound_optimal(vector<int>& nums, int k){
  /*
   we know the array is sorted,
   it means if we randomly takes an element, say num,

   and num is < target
      -> it would mean, the lowerbound might exist after num

   if num > target
      -> it would mean, the lowerbound must exist before num
   
   even if num == target
      -> in case of repetitions, lowerbound might exist before num 
   

   so this was intuition


   now for binary search,

   we will take low & high pointer
   calc mid as midpt. of low & high

   check whether num >= target or < target

   update high -> if num <= target

   update low & lowerbound -> if num > target

   again clac mid in next iteration

   check and update till low & high crosses each other
  */

  int low = 0;
  int high = nums.size() - 1;
  int lowerBound = nums.size();

  while(low <= high){
    int mid = low + (high-low)/2;

    if(nums[mid] < k){
      low = mid + 1;
    }
    else {
      lowerBound = mid;
      high = mid - 1;
    }
  }
  return lowerBound;

  // total TC -> O(log2(N))
  // total SC -> O(1)
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size; 
  cin>>size;

  int target;
  cin >> target;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }

  int lb;

  // lb = lowerBound_my_brute(v, target);
  lb = lowerBound_optimal(v, target);


  cout << lb;
return 0;
}