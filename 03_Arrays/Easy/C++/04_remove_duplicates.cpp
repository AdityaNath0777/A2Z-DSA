// remove duplicates from the Sorted Array
// and return the number of unique elements

// make changes in the array itself

#include <bits/stdc++.h>
using namespace std;

int removeDuplcates_Brute(vector<int> &nums){
// brute force
  set<int> st;

  // store the unique elements in set
  for(int i=0; i<nums.size(); ++i){ // -> O(N) 
    st.insert(nums[i]); // -> O(LogN)
  }

  // till here TC -> O(NlogN)

  int index = 0;
  // O(N)
  for(auto it : st){
    nums[index] = it;
    ++index;
  }

  // total TC -> O(NlogN + N)
  // total SC -> O(N)
  return index;
}

int removeDuplcates_Optimal(vector<int> &nums){
  // optimal
  // -> 2 ptr approach
    // total TC -> O(N)
    // total SC -> O(1)

  
  int i = 0;
  for (int j = 1; j < nums.size(); ++j){
    // if j ptr encounters another unique element
    // store it
    // and increment i
    if (nums[j] != nums[i]){
      nums[i+1] = nums[j];
      ++i;
    }
  }

  // size of unique array would be 
  // index of last unique element + 1
  return i+1;

        
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

  cout << removeDuplcates_Brute(v) << "\n";
  cout << removeDuplcates_Optimal(v) << endl ;

return 0;
}