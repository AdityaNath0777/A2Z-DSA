/*
 *  Problem Statement: 
 *  
 *  You're given an sorted array arr of n integers and an integer x. 
 *  Find the floor and ceiling of x in arr[0..n-1].
 * 
 *  The floor of x is the largest element in the array which is smaller than or equal to x.
 *  The ceiling of x is the smallest element in the array greater than or equal to x.
 */

#include <bits/stdc++.h>
using namespace std;

pair<int, int> findFloorCeil_01(vector<int>& nums, const int &target){
  int n = nums.size();

  int f = -1; 
  int c = -1;

  // find floor
  int low = 0;
  int high = n-1;

  while(low <= high){
    int mid = low + (high - low)/2;

    if(nums[mid] <= target){
      f = nums[mid];

      // move low towards right
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }

  // find ceil -> lower bound
  // so we can use STL
  auto pos = lower_bound(nums.begin(), nums.end(), target);
  c = nums[pos - nums.begin()];

  return pair<int, int> {f, c};
}

// using separate functions
int getFloor(vector<int>& nums, const int &target){
  int n = nums.size();

  int ans;

  int low = 0;
  int high = n-1;

  while(low <= high){
    int mid = low + (high - low)/2;

    if(nums[mid] <= target){
      ans = nums[mid];

      // move low towards right
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }

  return ans;
}

int getCeil(vector<int>& nums, const int &target){
  int n = nums.size();

  int ans;

  int low = 0;
  int high = n-1;

  while(low <= high){
    int mid = low + (high - low)/2;

    // either the required value is equal or greater than the target
    if(nums[mid] >= target){
      // high move towards left
      high = mid - 1;
      ans = nums[mid];
    }
    else {
      low = mid + 1;
    }

  }

  return ans;
}

pair<int, int> findFloorCeil(vector<int>& nums, const int &target){
  int f = getFloor(nums, target);
  int c = getCeil(nums, target);

  return pair<int, int> {f, c};
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

  pair<int, int> floorAndCeil = findFloorCeil(v, target);

  cout << floorAndCeil.first << " " << floorAndCeil.second;
return 0;
}