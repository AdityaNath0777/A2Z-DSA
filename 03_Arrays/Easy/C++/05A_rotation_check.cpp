#include <bits/stdc++.h>
using namespace std;

bool checkSorted(vector<int> &nums){
  int n = nums.size();

  for(int i=1; i<n; ++i){
    if (nums[i] < nums[i-1]){
      return false;
    }
  }

  return true;
}

bool checkRotated(vector<int> &nums){
  int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; ++i) {
        // Check if current element is greater than the next (cyclically)
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
            // If more than one drop is found, it's not a rotated sorted array
            if (count > 1) {
                return false;
            }
        }
    }

    // If at most one drop, it can be considered rotated sorted
    return true;
}


bool check_Sort_and_Rotation(vector<int>& nums) {
  return checkSorted(nums);
}


bool check_optimal(vector<int>& nums) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; ++i) {
        // Check if the current element is greater than the next (cyclically)
        if (nums[i] > nums[(i + 1) % n]) {
          // as when i = n-1
                // (i+1) % n = n % n
                //           = 0
          // with % n we can check nums[n-1] with nums[0]
            count++;
        }
    }

    // The array is sorted or rotated if there is at most one drop
    return count <= 1;

    // total TC -> O(N)
    // total SC -> O(1)
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

  // cout << check_Sort_and_Rotation(v);
  cout << check_optimal(v);

return 0;
}