#include <bits/stdc++.h>
using namespace std;

int consecutiveOnes(vector<int>& arr){
    int maxi = 0;
    int n = arr.size();
    int cnt = 0;
    for(int i=0; i<n; ++i){
        if(arr[i] == 1){
            ++cnt;
        }
        else {
            cnt = 0;
        }
        maxi = max(maxi, cnt);
    }

    return maxi;
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

  int maxOnes = consecutiveOnes(v);

  cout << "Maximium no. of consecutive ones: " << maxOnes;
return 0;
}