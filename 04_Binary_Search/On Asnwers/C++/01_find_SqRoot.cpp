/*
 * Problem Statement: 
 * 
 * You are given a positive integer n. 
 * Your task is to find and return its square root. 
 * 
 * If ‘n’ is not a perfect square, 
 * then return the floor value of 'sqrt(n)'.
 */

#include <bits/stdc++.h>
using namespace std;

// brute force -> using Linear Search
int floorSqRoot_brute(const int& num){
  int sqroot = -1;

  // if num is perfect square
  /*  int i = 1;
      while(i*i <= num){
        ++i;
      }
      return i;
   */

  // initial approach for handling non-perfect square cases
  for(int i=1; i<= num; ++i){
    if(i*i <= num)
      sqroot = i;
    else break;
  }

  // total TC -> O(N)
  // total SC -> O(1)
  return sqroot;
}

// optimal -> using in-built sqrt function
int floorSqRoot_optimal(const int& num){
  return int(sqrt(num));
}

// optimal -> using BinarySearch
int floorSqRoot_optimal_bs(const int& num){
  int low = 1;
  int high = num;

  while(low <= high){
    int mid = low + (high - low)/2;

    int sq = mid*mid;

    if(sq <= num){      
      // eliminate left
      // move right
      low = mid + 1;
    }
    else {
      // eliminate right
      // move left  
      high = mid  -1;
    }
  }

  // in Dry run, we find that high will always be either at the sq root 
          // or 
          // floor value of sq root 
  return high;

  // total TC -> O(log2(N))
  // total SC -> O(1)
}

int main(int argc, char* argv[]){

  int sq;
  cin >> sq;

  int sqRoot;
  // sqRoot = floorSqRoot_brute(sq);
  // sqRoot = floorSqRoot_optimal(sq);
  sqRoot = floorSqRoot_optimal_bs(sq);
  
  cout << sqRoot;

return 0;
}