/*
  Variety-2
  Problem Statement:
  There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.

  Note: Start the array with positive elements.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> RearrangeBySign(vector<int>& A){
    int n = A.size();
    vector<int> pos;
    vector<int> neg;

    for(int i=0; i<n; ++i){
        if(A[i] < 0)
            neg.push_back(A[i]);
        else pos.push_back(A[i]);
    }

    int index = 0;
    int i = 0, j = 0;

    while(i<pos.size() && j<neg.size()){
        A[index] = pos[i];
        index++; i++;

        A[index] = neg[j];
        index++; j++;
    }

    while(j < neg.size()){
        A[index] = neg[j];
        index++;
        j++;
    }

    while(i < pos.size()){
        A[index] = pos[i];
        index++;
        i++;
    }

    return A;
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

  vector<int> solution = RearrangeBySign(v);

  for(int i=0; i<v.size(); ++i){
    // cout << v[i] << " ";
    cout << solution[i] << " ";
  }
return 0;
}