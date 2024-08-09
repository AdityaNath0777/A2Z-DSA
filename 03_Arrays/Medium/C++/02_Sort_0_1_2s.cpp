/*
    Problem Statement: 
        -> Given an array consisting of only 0s, 1s, and 2s. 
        WAP to in-place sort the array without using inbuilt sort functions. 
        ( Expected: Single pass-O(N) and constant space)
*/

#include <bits/stdc++.h>
using namespace std;

// using count
void sort012_brute(vector<int>& arr){
  int n = arr.size();
  int cnt0 = 0;
  int cnt1 = 0;
  int cnt2 = 0;

  for(int i=0; i<n; ++i){
    if (arr[i] == 0){
      cnt0++;
    }
    else if (arr[i] == 1){
      cnt1++;
    }
    else if (arr[i] == 2){
      cnt2++;
    }
  }

  int k = 0;
  while(cnt0){
    arr[k] = 0;
    ++k;
    --cnt0;
  }

  while(cnt1){
    arr[k] = 1;
    ++k;
    --cnt1;
  }

  while(cnt2){
    arr[k] = 2;
    ++k;
    --cnt2;
  }


}

// 3-ptr approach
// The Problem is actually -> a variation of Dutch National Flag Algorithm
void sort012_optimal(vector<int>& arr){
  int n = arr.size();

  int low = 0;
  int mid = 0;
  int high = n-1;

  while(mid <= high){
    if( arr[mid] == 0 ){
      swap(arr[low], arr[mid]);
      ++low;
      ++mid;
    }

    else if(arr[mid] == 1){
      ++mid;
    }

    else if( arr[mid] == 2 ){
      swap(arr[high], arr[mid]);
      --high;  
    }

  }

  /*
    total TC -> O(N)
    total SC -> O(1)
  
  */
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

  // sort012_brute(v);
  sort012_optimal(v);

  for(int i=0; i<size; ++i)
    cout << v[i] << " ";
return 0;
}