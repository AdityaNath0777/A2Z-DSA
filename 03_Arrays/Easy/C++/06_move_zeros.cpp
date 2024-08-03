#include <bits/stdc++.h>
using namespace std;

void moveZeroes_brute(vector<int>& nums) {
    int n = nums.size();

    vector<int> temp;

    for (int i=0; i<n; ++i){
      if(nums[i] != 0)
        temp.push_back(nums[i]);
    }

    for (int i=0; i<temp.size(); ++i){
      nums[i] = temp[i];
    }

    for (int i=temp.size(); i<n; ++i){
      nums[i] = 0;
    }
}

void mySwap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}
void moveZeroes_Optimal(vector<int>& nums) {
    int j = -1;

    // finding index of 1st zero
    for (int i = 0; i<nums.size(); ++i){
      if(nums[i] == 0){
        j = i;
        break;
      }
    }

    // if no zeros are found:
    if (j == -1) return;

    //Move the pointers i and j
    //and swap accordingly:
        // j+1 -> bcz we don't want to swap any prev non-zero elements
    for (int i = j+1; i<nums.size(); ++i){
      if (nums[i] != 0){
        mySwap(nums[i], nums[j]);
        j++;
      }
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

  // moveZeroes_brute(v);
  moveZeroes_Optimal(v);

  for (int i=0; i<size; ++i){
    cout << v[i] << " ";
  }
return 0;
}