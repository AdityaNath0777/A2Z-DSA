/*
  Variety-1

  Problem Statement:

  There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

  Note: Start the array with positive elements.
*/

#include <bits/stdc++.h>
using namespace std;

void RearrangeBySign_my_brute(vector<int>& A, int N){
  vector<int> pos;
  vector<int> neg;

  for(int i=0; i<N; ++i){
    if(A[i] < 0)
      neg.push_back(A[i]);
    else pos.push_back(A[i]);
  }

  // we know that A contains equal no. of +ve & -ve elements, 
  // thus pos.size() == neg.size()

  // int j=0;
  // for(int i=0; i<N; ++i){
  //   A[i] = pos[i-j];
  //   ++i;
  //   A[i] = neg[j];
  //   ++j;
  // }

  // more better way of same thing
  for(int i=0; i<N/2; ++i){
    A[2*i] = pos[i];
    A[2*i + 1] = neg[i];
  }

  // total TC -> O(2N)
  // total SC -> O(N)
}


/*
  can we remove extra space?
  no, somehwere we need to store them to preserve the order
*/
/*
  so we'll try to make it from 2 pass to one pass
*/
vector<int> RearrangeBySign_optimal(vector<int>& A, int N){
  vector<int> ans(N, 0); // TC -> O(N)

  int posIndex = 0;
  int negIndex = 1;

  for(int i=0; i<N; ++i){
    if(A[i] >= 0){
      ans[posIndex] = A[i];
      posIndex += 2;
    }
    else {
      ans[negIndex] = A[i];
      negIndex += 2;
    }
  }
  // total TC -> O(2N)
    // if we ignore vector initialisation
    // ~ O(N)
    // else it will also be going to round off to O(N)
  // total SC -> O(N)
  return ans;
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

  // RearrangeBySign_my_brute(v, size);
  vector<int> solution = RearrangeBySign_optimal(v, size);

  for(int i=0; i<v.size(); ++i){
    // cout << v[i] << " ";
    cout << solution[i] << " ";
  }
return 0;
}