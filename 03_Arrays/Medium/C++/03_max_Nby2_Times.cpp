/*
Problem Statement: Given an array of N integers, 
  write a program to return an element that occurs more than N/2 times in the given array. 
  You may consider that such an element always exists in the array.
*/

#include <bits/stdc++.h>
using namespace std;

// using set -> then counting freq
int majorityElement_brute(vector<int>& nums){
  set<int> st;
  int n = nums.size();

  // TC  -> O(N)
  for(int i=0; i<n; ++i){
    // set -> unique elemenrs
    // after that 
    // loop -> cnt unique elements
    // return majority 
    st.insert(nums[i]);
  }

  int mjCnt = 0;

  // in worst case -> TC -> O(N^2) (if all the elements are unique)
  // also at that time -> SC -> O(N)
  for(auto it:st){
    int cnt = 0;
    for(int i=0; i<n; ++i){
      if(nums[i] == it){
        cnt++;
      }
    }
    mjCnt = max(mjCnt, cnt);
    if (mjCnt > n/2) {
      return it;
    }
  }

  // total TC -> O(N^2 + N) 
      //      ~ O(N^2)
  // total SC -> O(N)

  // majority element not found having occurence more than N/2 times
  return -1;
}

// using 2 loops to count each freq
int majorityElement_brute2(vector<int>& nums){
  int n = nums.size();

  // TC -> O(N^2)
  // SC -> O(1)
  for(int i=0; i<n; ++i){
    int cnt = 0;
    for(int j=0; j<n; ++j){
      if(nums[i] == nums[j])
        cnt++;
    }

    if(cnt > n/2)
      return nums[i];
  }

  return -1;
}

// hash map
int majorityElement_better(vector<int>& nums){
  int n = nums.size();

  //  val, freq
  map<int, int> visited;
  // SC -> O(N)

  // TC -> O(NlogN)
  for (int i = 0; i < n; i++){

    // TC -> O(logN) -> for map.find()
    // for unordered -> O(1)
    if(visited.find(nums[i]) == visited.end()){
      // new value found
      // store it
      visited[nums[i]] = 1;
    }
    else visited[nums[i]]++;

    if(visited[nums[i]] > n/2){
      return nums[i];
    }
  }

  // total TC -> O(NlogN)
  // total SC -> O(N)
  return -1;
}

// Moore’s Voting Algorithm
int majorityElement_optimal(vector<int>& nums){
  int n = nums.size();
  int count = 0;
  int element = NULL;

    /*
    nums[] = [1 2 3 4 5 4 3 4 4 5]
    
    cnt = 0
    element = nums[0]
    i = 0
      element == nums[i] => 1
        ? cnt++
        : cnt--
      cnt = 1

    i = 1
      element == nums[i]
        ? cnt++
        : cnt--

      nums[i] => nums[1] = 2
      => cnt-- 

      cnt = 0

      if cnt==0
        element = nums[i]
        cnt = 1

      => element = 2
    i = 2
      elem -> 2
      nums[i] -> 3

      cnt -> --
      cnt = 0

      as cnt == 0
        ele = 3
        cnt = 1

    i = 3
      elem -> 3
      nums[i] -> 4

      cnt -> --
      cnt = 0

      as cnt = 0
        elem = 4
        cnt = 1

    i = 4
      elem -> 4
      nums[i] -> 5

      //lly ele, -> 5
        cnt -> 1

    i = 6
      elem -> 5
      nums[i] -> 4

      elem -> 4
      cnt = 1

    i = 7
      elem -> 3
      cnt -> 1

    i = 8
      elem -> 3
      nums[i] = 4

      elem -> 4
      cnt = 1


    i = 9
      elem -> 4
      nums[i] -> 4
      cnt++;

      cnt -> 2

    i = 10
      elem -> 4
      nums[i] -> 5
      cnt--;

      elem -> 4
      cnt -> 1
    */

  /* 
    here cnt is 1
    means elem = 4
    has might occured 1 time more than the second most occured element or just 1 time

    but for majority element the condition is to occur > N/2 times

    so count the occurence of that element
    for i = [0 -> n-1]{
      if nums[i] == element
        cnt1++
    }

    if cnt1 > n/2
      return element
    
    // else part
    return -1
  */


  // TC -> O(N)
  for(int i=0; i<n; ++i){
    if (count == 0){
      element = nums[i];
      count = 1;
    }

    else if( element == nums[i] ) count++;
    else count--;
    
  }

  // TC -> O(N)
  // checking if the stored element is majority or not?
  int cnt1 = 0;
  for(int i=0; i<n; ++i){
    if(nums[i] == element)
      cnt1++;
  }

  if( cnt1 > n/2 ) return element;
  // if majority element NOT found
  return -1;


  // total TC -> O(2N)
  //          ~ O(N)
  // toal SC -> O(1)
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

  // int maxNby2 = majorityElement_brute(v);
  // int maxNby2 = majorityElement_brute2(v);
  // int maxNby2 = majorityElement_better(v);
  int maxNby2 = majorityElement_optimal(v);

  cout << maxNby2;
return 0;
} 