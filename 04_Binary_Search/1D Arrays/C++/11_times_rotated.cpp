/*
 * Problem Statement: 
 * 
 * Given an integer array arr of size N, sorted in ascending order (with distinct values).
 * Now the array is rotated between 1 to N times which is unknown. 
 * 
 * Find how many times the array has been rotated. 
*/

#include <bits/stdc++.h>

// if we are required to use only necessary header files
// #include <iostream> // I/O
// #include <limits> // INT_MAX
// #include <vector> // vector

using namespace std;

/*
  ==> General Intuition
      * as the array was originally sorted
      * so there should be a minimum value at the front
      * and that minimum element would be at index 
      * which denotes no. of right rotation
      * 
      *   e.g. arr[] = [1 2 3 4 5 6 7]
      *       arr2[] = [5 6 7 1 2 3 4]
      *      indices -> 0 1 2 3 4 5 6
      * basically the differece b/w current index & o.g index
      * 
      * so if any lang has (^ ^)==>> 1 base indexing
      * then no. of rotation = curr_index - o.g. index
      *                      = 4 - 1
      *                      = 3
*/

int findNoOfRightRotation_brute(vector<int>& nums){
  int mini = INT_MAX;
  int mini_index = -1;

  for (int i = 0; i < nums.size(); i++){
    if(nums[i] < mini){
      mini = nums[i];
      mini_index = i;
    }
  }
  
  return mini_index;
}

int findNoOfRightRotation_optimal(vector<int>& nums){
  int mini = INT_MAX;
  int mini_index = -1;

  int low = 0;
  int high = nums.size() - 1;

  while(low <= high){

    /* 
     * Gental Reminder to myself
     *
     * To prevent integer overflow & 'wrap around' of values
          (low + high)/2
          (low + high + low - low)/2
          (2low + (high - low))/2
          low + (high - low)/2
    */
    int mid = low + (high - low)/2;

    // if left sorted
    if(nums[low] <= nums[mid]){
      if(nums[low] < mini){
        mini = nums[low];
        mini_index = low;
      }

      // eliminate left
      // move right
      low = mid + 1;
    }

    // else right sorted
    else {
      if(nums[mid] < mini){
        mini = nums[mid];
        mini_index = mid;
      }

      // eliminate right
      // move left
      high = mid - 1;
    }
  }

  return mini_index;
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }

  int timesRotated;

  // timesRotated = findNoOfRightRotation_brute(v);
  timesRotated = findNoOfRightRotation_optimal(v);

  cout << "No. of Times Right Rotated: " << timesRotated;
  

return 0;
}