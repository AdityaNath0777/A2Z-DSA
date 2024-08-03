#include <bits/stdc++.h>
using namespace std;

void rotateRight(vector<int>& nums, int k) {
        int n = nums.size();
        k = k  % n;

        vector<int> temp;
        for (int i = n-k; i<n; ++i){
          temp.push_back(nums[i]);
        }

        for (int i = n-k-1; i>=0; --i){
          nums[i+k] = nums[i];
        }

        for (int j = 0; j < k; ++j){
          nums[j] = temp[j];
        }
    }

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  for (int i=0; i<size; ++i) {
    int a;
    cin >> a;
    v.push_back(a); 
  }

  int k = 0;

  cin >> k;


  rotateRight(v, k);

  for (int i=0; i<size; ++i){
    cout << v[i] << " ";
  }
return 0;
}