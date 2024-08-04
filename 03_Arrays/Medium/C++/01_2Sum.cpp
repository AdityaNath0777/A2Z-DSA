#include <bits/stdc++.h>
using namespace std;

// brute force
vector<int> twoSum_brute(vector<int> &v, int target){
  // TC -> O(N*N)
  // SC -> O(1) // as constant space is being used

  vector<int> targetIndices;

  for (int i=0; i<v.size(); ++i){
    for (int j=i+1; j<v.size(); ++j){
      if ((v[i] + v[j]) == target){
        return { i, j };
      }
    }
  }

  return { -1, -1 };
} 


// better approach (using hash map)
vector<int> twoSum_better(vector<int> &v, int target){
  vector<int> ans;

  map<int, int> mpp;
  for (int i=0; i<v.size(); ++i){
    int a = v[i];
    int rem = target - a;

    // if mpp does not return the end
    // means the 'key' is within the map
    if (mpp.find(rem) != mpp.end()){
      // current location of a in v  -> i
      // index of rem stored in mpp  -> mpp[rem]
      return { i, mpp[rem]};
    }

    mpp[a] = i;
  }

  // Total TC -> O(NlogN)  ->    if unord map -> O(N) (best & avg. case)
                                        // O(N^2) (worst case)
  // Total SC -> O(N)
  return { -1, -1 };
}


// optimal appraoch (slightly optimal than hash map)
      // ( but need to modify to return indices)
// The catch is -> it distortes the array by sorting
vector<int> twoSum_optimal(vector<int>& v, int target){

  // 2-ptr approach
  int left = 0; 
  int right = v.size() - 1;

  sort(v.begin(), v.end()); // O(NlogN)

  // traverse from left to right & right to left
  while(left < right) { // TC -> O(N)

    // calc sum and compare with target
    int sum = v[left] + v[right];
    if (sum == target){
      return {v[left], v[right]};
    }

    // if sum is greater,
        // then to reduce it we'll decrement from right
    else if (sum > target) right--;
    // if sum is smaller,
        // then to increase it we'll increment from left
    else left++;
  }

  // Total TC -> O(NlogN + N)
  // Total SC -> O(1) + O(N) (for sorting)
  return {-1, -1};
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

  int target;
  cin >> target;

  // vector<int> indices = twoSum_brute(v, target);
  // vector<int> indices = twoSum_better(v, target);
  // if (indices[0] != -1){
  //   cout << v[indices[0]] << " " << v[indices[1]];
    
  // }


  vector<int> indices = twoSum_optimal(v, target);
  if (indices[0] != -1){
    cout << indices[0] << " " << indices[1];
    
  }
return 0;
}