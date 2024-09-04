/**
 * Problem Statement: 
 * 
 * You are given an array 'arr' of size 'n' which denotes the position of stalls.
 * You are also given an integer 'k' which denotes the number of aggressive cows.
 * 
 * You are given the task of assigning stalls to 'k' cows 
 * such that the minimum distance between any two of them is the maximum possible.
 * 
 * Find the maximum possible minimum distance.
*/

#include <bits/stdc++.h>
using namespace std;

bool canBePossible(vector<int>& stalls, int cows, int dist){
  int n = stalls.size();

  int cowCount = 1;
  int lastCowLoc = stalls[0];

  for(int i=1; i<n; ++i){
    if(stalls[i] - lastCowLoc >= dist){
      cowCount++;
      lastCowLoc = stalls[i];
    }

    if(cowCount >= cows) return true;
  }

  return false;
}

int maxMinimumDistance_brute(vector<int>& stalls, int k){

  int n = stalls.size();
  if(k > n || n <= 1) return -1;

  /**
   * 
   * The Maximum possible (minimum distance b/w cows)
   * 
   * the minimum distance will always occur b.w consecutive stalls
   * 
   * thus, to get minimum distance, first we will sort it
   * 
   * then minimum possible distance could be 1 b/w cows when atleast 2 are given
   * 
   * to get max of mini possible -> the first cow should be at the first position,
   * so we can pot other cows rest of the location of stalls and get distance b/w them
   * while accomodating maximum possible no. of cows
   * 
   * 
   * arr[] = [0 3 4 7 10 9]
   * 
   * we place the cows at location 0, 3, 4, 7
   * the minimum dist. would be b.w consecutive (assuming location are sorted)
   * then 3-0 = 3, 4-3 = 1, 7-4 = 3
   * 
   * here minimum is 1, now we have to maximize this 
   * 
   * for that the maximum possible would be
   *  -> at 0, 4, 7, 10
   * 
   * as now 4-0 = 3, 7-4= 3, 10-7= 3
   * 
   * in this combination, the minimum is 3
   * which is greater than 1 as in our previous combination we discussed
   *  
  */

  // sorting to get dist. b/w consecutive stalls
  sort(stalls.begin(), stalls.end());

  // max distance two stalls can have
  int limit = stalls[n-1] - stalls[0];

  // iterating from dist 1 to limit dist.
  // so, here i denotes the mini distance possible with the given set of cows
  // which we will check using canBePossible() func.
  for(int i=1; i<=limit; ++i){
    if(canBePossible(stalls, k, i)){
      continue;
    }
    // means prev one was the answer
    else return (i-1);
  }

  return limit;
}

int maxMinimumDistance_optimal(vector<int>& stalls, int k){
  int n = stalls.size();

  // sort to get mini. dist b/w consecutive stalls
  sort(stalls.begin(), stalls.end());

  int limit = stalls[n-1] - stalls[0];

  int low = 1;
  int high = limit;

  // just use binary search b/w mini dist. and max. dist. 
  //                        posisble b.w two consecutive stalls 
  while (low <= high)  {
    int mid = low + (high - low)/2;

    if(canBePossible(stalls, k, mid)){
      low = mid + 1;
    }
    else high = mid - 1;
  }
  
  // cout << high << "\t" << low << endl << endl;
  return high;

}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  int k;
  cin >> k;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }

  int ans;
  
  // ans = maxMinimumDistance_brute(v, k);
  ans = maxMinimumDistance_optimal(v, k);

  cout << "Maximum possible minimum distance: " << ans;
  

return 0;
}