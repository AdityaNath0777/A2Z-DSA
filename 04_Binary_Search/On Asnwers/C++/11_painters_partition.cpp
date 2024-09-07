/**
 * 
 * Problem Statement: 
 * 
 * Given an array/list of length ‘N’, where the array/list represents the boards 
 * and each element of the given array/list represents the length of each board. 
 * 
 * Some ‘K’ numbers of painters are available to paint these boards. 
 * Consider that each unit of a board takes 1 unit of time to paint. 
 * 
 * You are supposed to return the area of the minimum time to get this job done 
 * of painting all the ‘N’ boards under the constraint that any painter 
 * will only paint the continuous sections of boards.
*/

#include <bits/stdc++.h>
using namespace std;

/* same approach as of Book ALlocation */

int countPaintersRequired(vector<int>& boards, int maxTime){
  int n = boards.size();

  int painterCount = 1;
  int timeTaken = boards[0];

  for(int i=1; i<n; ++i){
    if(timeTaken + boards[i] <= maxTime){
      timeTaken += boards[i];
    }
    else {
      timeTaken = boards[i];
      painterCount++;
    }
  }

  // total TC -> O(N)
  // total SC -> O(1)

  return painterCount;
}

int findMinimumPossibleMaxTime_brute(vector<int>& boards, int k){
  int n = boards.size();

  if (k > n) return -1;
  
  int low = *max_element(boards.begin(), boards.end());
  int limit = accumulate(boards.begin(), boards.end(), 0);

  for(int timeTaken = low; timeTaken <= limit; ++timeTaken){
    int paintersReqrd = countPaintersRequired(boards, timeTaken);

    if(paintersReqrd <= k){
      return timeTaken;
    }
  }

  // total TC -> O(N * (sum - max of boards[]))
  // total SC -> O(1)
  return -1;
}

int findMinimumPossibleMaxTime_optimal(vector<int>& boards, int k){
  int n = boards.size();

  if (k > n) return -1;
  
  int low = *max_element(boards.begin(), boards.end());
  int limit = accumulate(boards.begin(), boards.end(), 0);

  int high = limit;

  while(low <= high){
    int mid = low + (high - low)/2;

    int paintersCnt = countPaintersRequired(boards, mid);

    if(paintersCnt > k){
      low = mid + 1;
    }
    else high = mid - 1;
  }

  // total TC -> O(N * log2((sum - max of boards[])))
  // total SC -> O(1)
  return low;
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  int noOfpainters;
  cin >> noOfpainters;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }

  int minMaxTime;

  minMaxTime = findMinimumPossibleMaxTime_brute(v, noOfpainters);

  cout << minMaxTime;

return 0;
}