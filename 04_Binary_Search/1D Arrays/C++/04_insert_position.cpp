/*
 * Problem Statement: 
 * 
 * You are given a sorted array arr of distinct values and a target value x. 
 * You need to search for the index of the target value in the array.
 *
 * If the value is present in the array, then return its index. 
 * O/w -> determine the index where it would be inserted in the array 
 * while maintaining the sorted order.
 */

#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int k){
  /*
    indices -> 0 1 2 3 4
      arr[] = [1 2 4 6 7]

    if k = 2,
     then return position of 2 -> 1

    if k = 5
      it would be placed at the position of element 6
      thus return 3

    
    it means rather nums[i] == k and return -> i
        or    first nums[i] > k and return -> i
    
    which is kind of like lowerbound, so use the same logic
  */
  int n = nums.size();
  int pos = n;

  int low = 0;
  int high = n-1;

  while(low <= high){
    int mid = low + (high - low)/2;

    if(nums[mid] < k){
      // move right
      low = mid + 1;
    }
    else {
      // store position
      pos = mid;

      // move left
      high = mid - 1;
    }
  }

  return pos;
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

  int insert_pos = searchInsert(v, target);

  cout << insert_pos;
return 0;
}