#include <bits/stdc++.h>
using namespace std;

bool isArraySorted(vector<int> &v) {
  for (int i=1; i<v.size(); ++i){
    if(v[i] < v[i-1])
      return false;
  }
  return true;
}

int main(int argc, char* argv[]){
  int size;
  cin >> size;

  vector<int> v;

  for(int i=0; i<size; ++i) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  int isSorted = isArraySorted(v);

  cout << isSorted;

return 0;
}