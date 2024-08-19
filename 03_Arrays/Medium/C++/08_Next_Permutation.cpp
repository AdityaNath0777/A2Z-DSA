/*
  Problem Statement: 
  
  Given an array Arr[] of integers, 
  rearrange the numbers of the given array into the lexicographically 
  next greater permutation of numbers.

  If such an arrangement is not possible, 
  it must rearrange to the lowest possible order (i.e., sorted in ascending order).

*/

#include <bits/stdc++.h>
using namespace std;

/*

  Brute Force: Finding all possible permutations. 

  Approach :

  Step 1: Find all possible permutations of elements present and store them.

  Step 2: Search input from all possible permutations.

  Step 3: Print the next permutation present right after it.

  Complexity Analysis
      -> For finding, all possible permutations, it is taking N!xN. 
         Also for searching input arrays from all possible permutations will take N!. 
         Therefore, TC -> O(N!xN).

Space Complexity :
      -> Since we are not using any extra spaces except stack spaces for recursion calls. 
         So, it has a SC -> O(1).
*/


/*
  Better Approach for C++
    Using in-built function

    C++ provides an in-built function called next_permutation() 
    which directly returns the lexicographically next greater permutation of the input.

    e.g.

    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3); //using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
*/

/*********************************************************/
/*********************************************************/

/*
  # Optimal Approach

  1. Obvservations
    -> dictionary like method
    a) longer prefix match required
        a[i] > a[i+1] when i--
    b) find > A, but the smallest one (next greater) to stay close
    c) try to place remaining in sorted order
*/
void nextPermutation_optimal(vector<int>& nums) {
  int n = nums.size();
  int ind = -1;

  for(int i=n-2; i>=0; --i){
    if(nums[i] < nums[i+1]){
        ind = i;
        break;
    }
  }

  if(ind == -1){
    reverse(nums.begin(), nums.end());
    return;
  }

  for(int i=n-1; i>ind; --i){
    if(nums[i] > nums[ind]){
        swap(nums[i], nums[ind]);
        break;
    }
  }

  // reverse from just after the break point

  reverse(nums.begin() + ind + 1, nums.end());
  
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


return 0;
}