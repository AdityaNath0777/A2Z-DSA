/*
 * Problem Statement: 
 * 
 * Given two numbers N and M, find the Nth root of M. 
 * The nth root of a number M is defined as a number X when raised to the power N equals M. 
 * 
 * If the 'nth root is not an integer, return -1.
 */

#include <bits/stdc++.h>
using namespace std;

int comparePower(int mid, int n, int m){
  long long pow = 1;

  for(int i=0; i<n; ++i){
    pow = pow*mid;

    if( pow > m) return 2;
  }

  if(pow == m) return 1;
  
  return 0;
}

// brute force -> using Linear Search
int findNthRoot_brute(const int& num, const int& n){

  for(int i=1; i<= num; ++i){ // TC -> O(M)
    long long val = 1l;

    
    for(int k=0; k<n; ++k){   // TC -> O(N)
      val *= i;
    }

    // val = int(pow(i, n));       // TC -> O(log2(N))
    // cout << val << " ";
    if(val == num)
      return i;
  }

  // integer nth root not found
  return -1;

  // total TC -> O(M*N) // if for loop used
  //          -> O(M*log2(N)) if pow func used
  // total SC -> O(1) 
}


// optimal -> using Binary Search
int findNthRoot_optimal(const int& num, const int& n){
  int low = 1;
  int high = num;

  while(low <= high){
    int mid = low + (high - low)/2;

    int compMid = comparePower(mid, n, num);

    // mid^n == num
    if(compMid == 1) return mid;

    // mid^n < num
    // eliminate left
    // move right
    if(compMid == 0){
      low = mid + 1;
    }

    // mid^n > num
    // eliminate right
    // move left
    else {
      high = mid - 1;
    }
  }

  // integer root not found
  return -1;

  // total TC -> O(N*log2(M))
  // total SC -> O(1)
}

int main(int argc, char* argv[]){
  int num;
  cin >> num;

  int nth;
  cin >> nth;

  int nthRoot;

  nthRoot = findNthRoot_brute(num, nth);
  // nthRoot = findNthRoot_optimal(num, nth);

  cout << nthRoot;

return 0;
}