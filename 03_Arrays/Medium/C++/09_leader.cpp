/*
  Problem Statement: 
  
  Given an array, print all the elements which are leaders. 
  
  A Leader is an element that is greater than all of the elements on its right side in the array.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders_brute(vector<int>& nums){
  vector<int> leaders;

  // TC -> O(N^2)
  for(int i=0; i<nums.size(); ++i){
    bool isLeader = true;

    for(int j=i+1; j<nums.size(); ++j){
      if(nums[j] > nums[i]){
        isLeader = false;
        break;
      }
    }

    if(isLeader)
      leaders.push_back(nums[i]);
  }

  // if we are required to return sorted list
  // sort(leaders) -> TC -> O(NlogN)

  // total TC -> O(N^2) & if (sorted) -> + O(NlogN)
  // total SC -> O(N)
  return leaders;
}

vector<int> findLeaders_optimal(vector<int>& nums){
  vector<int> leaders;

  int maxi = INT_MIN;

  for(int i=nums.size()-1; i>=0; --i){

    if(nums[i] > maxi){
      leaders.push_back(nums[i]);
    }

    // keep track of max element when going from right to left
    // keep track of right maximum
    maxi = max(maxi, nums[i]);
  }

  sort(leaders.begin(), leaders.end()); // TC -> O(NlogN)

  // total TC -> O(N) + O(NlogN)
  // total SC -> O(N)
  return leaders;
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin>>size;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }

  vector<int> leadersList = findLeaders_brute(v);

  for(int i=0; i<leadersList.size(); ++i){
    cout << leadersList[i] << " ";
  }
return 0;
}