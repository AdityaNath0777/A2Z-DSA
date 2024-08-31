/**
 * Problem Statement: 
 * 
 * You are given 'N’ roses and you are also given an array 'arr'  
 * where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
 * 
 * You can only pick already bloomed roses that are adjacent to make a bouquet. 
 * and require exactly 'k' adjacent bloomed roses to make a single bouquet.
 * 
 * Find the minimum number of days required to make at least ‘m' bouquets 
 * each containing 'k' roses. 
 * 
 * Return -1 if it is not possible.
*/

#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int>& nums){
  int maxi = INT_MIN;

  for(int i=0; i<nums.size(); ++i){
    maxi = max(maxi, nums[i]);
  }

  return maxi;
}
int findMin(vector<int>& nums){
  int mini = INT_MAX;

  for(int i=0; i<nums.size(); ++i){
    mini = min(mini, nums[i]);
  }

  return mini;
}

// brute force -> my approach -> Linear Search
int findMiniNoOfDaysRequired_my_brute(vector<int>& nums, const int& m, const int& k){
  // m -> no. of bouquets required
  // k -> no. of roses req. in a single bouquet
  // total no. of roses req -> m*k

  // total no. of roses given -> size of array
  int N = nums.size();

  // not possible to make bouquets for the req. amount of roses
  if(N < m*k) return -1;

  int maxi = findMax(nums);
  int mini = findMin(nums);

  int miniDays = mini;
  int maxiDays = maxi;

  int maxBloomTime = INT_MIN;

  // iterating for each bouquet
  for(int j = 1; j<= m; ++j){

    // iterating to select roses for the current bouquet
    int myMin = maxi;
    int start = 0;
    int end = 0;
    for(int i=0; i<N-3; ++i){
      cout << i << "\n";
      int d = INT_MIN;
      bool skip = false;
      for(int a=i; a<i+3; ++a){
      // start = a;
      // end = a+3;
        int num = nums[a];
        cout << num << " ";
        if(nums[i] == -1) {
          skip = true;
          break;
        }
        d = max(d, num);
      }

      cout << endl;

      if(skip) continue;
      myMin = min(d, myMin);
      
    }

    for(int i = start; i<end; ++i){
      nums[i] = -1;
    }
    miniDays = myMin;

  }

  return miniDays;

}

// brute force
bool isBouquetPossible(vector<int> nums, const int& day, const int& m, const int& k){

  int cnt = 0;
  int bq = 0;
  for(int i=0; i<=nums.size(); ++i){
    if(nums[i] <= day){
      cnt++;
    }
    else {
      bq += cnt/k;
      cnt = 0;
    }
  }
  
  bq += cnt/k; 
  // if(bq == m) return true;
  // return false;

  return bq >= m;
}

int findMiniNoOfDaysRequired_brute(vector<int>& nums, const int& m, const int& k){
  // m -> no. of bouquets required
  // k -> no. of roses req. in a single bouquet
  // total no. of roses req -> m*k

  // total no. of roses given -> size of array
  int N = nums.size();

  // not possible to make bouquets for the req. amount of roses
  if(N < m*k) return -1;

  int mini = findMin(nums);
  int maxi = findMax(nums);

  for(int i=mini; i<=maxi; ++i){
    if(isBouquetPossible(nums, i, m, k))
      return i;
  }
  return -1;
}

int main(int argc, char* argv[]){
  vector<int> v;

  int N;
  cin >> N;

  int noOfBouquets;
  cin >> noOfBouquets;

  int noOfRosesInABouquet;
  cin >> noOfRosesInABouquet;

  for(int i=0; i<N; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }

  
  int miniNoOfDaysRequired;

  // miniNoOfDaysRequired = findMiniNoOfDaysRequired_my_brute(v, noOfBouquets, noOfRosesInABouquet);
  miniNoOfDaysRequired = findMiniNoOfDaysRequired_brute(v, noOfBouquets, noOfRosesInABouquet);

  if(miniNoOfDaysRequired == -1)
    cout << "not possible to make bouquets for the req. amount of roses \nreturning -1";
  else cout << "Minimum no. of days required: " << miniNoOfDaysRequired;
  

return 0;
}