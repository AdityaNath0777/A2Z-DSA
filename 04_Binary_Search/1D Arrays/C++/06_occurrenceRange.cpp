/*
 *  Problem Statement:
 *  
 *  Given an array of integers nums sorted in non-decreasing order, 
 *  find the starting and ending position of a given target value.
 * 
 *  If target is not found in the array, return [-1, -1].
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange_brute(vector<int>& nums, int k){
  int start = -1;

  // brute force -> using linear search

  // find first occcurence
  for(int i=0; i<nums.size(); ++i){
    if(nums[i] == k){
      start = i;
      break;
    }
  }

  // if element not found return {-1, -1}
  if (start == -1) return {-1, -1};

  // else find last occurence
  int end;
  for(int i=nums.size()-1; i>=0; --i){
    if(nums[i] == k){
      end = i;
      break;
    }
  }

  return {start, end};
}

// using the previous lower bound & upper Bound approach uisng binary search
int upperBound(vector<int>& nums, int k){
  int up = nums.size();

  int low = 0;
  int high = nums.size()-1;

  while(low <= high){
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

int lowerBound(vector<int>& nums, int k){
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
}

vector<int> searchRange_better(vector<int>& nums, int target) {
    int start;

    start = lowerBound(nums, target);
    if (start == nums.size() || nums[start] != target)
      return {-1, -1};
    
    int end = upperBound(nums, target) - 1;
    return {start, end};
}


// slightly better than prev better
// optimal -> using binary search form scratch
int firstOccurrence(vector<int>& nums, int k){
  int first = -1;
  int low = 0;
  int high = nums.size()-1;

  while(low <= high){
    int mid = low + (high-low)/2;

    if(nums[mid] == k){
      first = mid;
      high = mid - 1;
    }
    else if(nums[mid] < k){
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }

  return first;
}

int lastOccurrence(vector<int>& nums, int k){
  int last = -1;
  int low = 0;
  int high = nums.size() - 1;

  while(low <= high){
    int mid = low + (high - low)/2;

    if(nums[mid] == k){
      last = mid;
      low = mid + 1;
    }
    else if(nums[mid] < k){
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }

  return last;
}

vector<int> searchRange_optimal(vector<int>& nums, int target) {
  // using binary search from scrath
  int start = firstOccurrence(nums, target);

  if(start == -1)
    return {-1, -1};
  
  return {start, lastOccurrence(nums, target)};

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

  vector<int> targetRange;

  // targetRange = searchRange_brute(v, target);
  // targetRange = searchRange_better(v, target);
  targetRange = searchRange_optimal(v, target);

  for(auto it : targetRange){
    cout << it << " ";
  }
return 0;
}