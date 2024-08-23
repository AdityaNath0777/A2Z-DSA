/*
 *  Problem Statement: 
 *  
 * Given a sorted array of N integers and an integer x, 
 * write a program to find the upper bound of x.
 * 
 * upper bound in a sorted array -> index of the first value that is greater than a given value. 
*/

#include <bits/stdc++.h>
using namespace std;

int upperBound_brute(vector<int>& nums, int k){
  // brute force -> linear search

  int up = nums.size();

  // searching from start to end
  for(int i=0; i<nums.size(); ++i){
    if(nums[i] > k)
      return i;
  }

  return up;
}

int upperBound_optimal(vector<int>& nums, int k){
  // optimal -> binary search

  int up = nums.size();

  int low = 0;
  int high = nums.size()-1;

  while(low <= high){
    /*
      take a random element -> num

      if num > k
        it means the upper bound might exist before num
          or 
        this num is the required upper bound

        move towards low -> high = mid-1

      if num == k
        it means the upper bound might exist after num

      if num < k
        it means the upper bound might exist after num
    */

    int mid = low + (high-low)/2;

    if(nums[mid] > k){
      up = mid;
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }

  return up;
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

  int ub;

  // ub = upperBound_brute(v, target);
  ub = upperBound_optimal(v, target);


  cout << ub;
return 0;
}