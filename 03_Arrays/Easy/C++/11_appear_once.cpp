// given -> array having elements appearing exactly two time
//      -> except the one that is appearing only once
// find that element (it could be -ve or +ve)

#include <bits/stdc++.h>
using namespace std;

int appearOnce_brute(vector<int>& a){
  int n = a.size();

  for(int i=0; i<n; ++i){
    int num = a[i];
    int cnt = 0;
    for(int j=0; j<n; ++j){
      if(a[j] == num)
        ++cnt;
    }

    if(cnt == 1)
      return num;
  }

  // TC -> O(N*N)
  // SC -> O(1)

  // if all are appearing more than once
  return -1;
}

int appearOnce_better(vector<int>& a){
  // the number could be -ve,
  // this way it would be difficult to use vector for hashing
  map<long long, int> mpp;
    // key, value
    // element, index

  int n = a.size();
  for(int i=0; i<n; ++i){
    if(mpp.find(a[i]) != mpp.end())
      mpp[a[i]] += 1;

    else mpp[a[i]] = 1;
  }

  for(auto it : mpp){
    if(it.second == 1)
      return it.first;
  }

  // if no element is appearing once
  return -1;
}

int appearOnce_optimal(vector<int>& a){
  int n = a.size();
  int xorA = 0;

  for(int i=0; i<n; ++i){
    xorA = xorA ^ a[i];
  }

  // TC -> O(N)
  // SC -> O(1)
  return xorA;
}

// assumes, arr is sorted
// and applies Binary Search
int appearOnce_super_optimal(vector<int>& a){
  int left = 0;
  int right = a.size() - 1;

  while(left < right){
    int mid = left + (right-left)/2;

    // making sure mid is even
    if(mid%2 == 1)
      --mid;

    if( a[mid] == a[mid + 1])
      // Single element is on the right
      left = mid + 2;
    else {
      // Single element is on the left or at mid
      right = mid;
    }
  }
  // left should point to the single element
  return a[left];

  // TC -> O(logN)
  // SC -> O(1)
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  // enter sorted array
  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }

  // int once = appearOnce_brute(v);
  // int once = appearOnce_better(v);
  // int once = appearOnce_optimal(v);
  int once = appearOnce_super_optimal(v);

  cout << "The element which only appears once: " << once;
return 0;
}