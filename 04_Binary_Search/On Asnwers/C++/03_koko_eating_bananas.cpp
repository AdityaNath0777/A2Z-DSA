/*
 * Problem Statement: 
 * 
 * A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. 
 * An integer ‘h’ is also given, which denotes the time (in hours) 
 * for all the bananas to be eaten.
 * 
 * Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. 
 * If the pile contains less than ‘k’ bananas, 
 * then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
 * 
 * Find the minimum number of bananas ‘k’ to eat per hour 
 * so that the monkey can eat all the bananas within ‘h’ hours.
 * 
 */

#include <bits/stdc++.h>
using namespace std;


// my approach -> brute force -> using Linear Search
int minimumRateToEatBananas_myBrute(vector<int>& nums, int hours){
  // int k = INT_MAX;

  int n = nums.size();

  int maxi = INT_MIN;
  for(int i=0; i<n; ++i){ // TC -> O(N)
    maxi = max(maxi, nums[i]);
  }

  cout << "maximum is: " << maxi << "\n\n";
  for(int i=1; i<= maxi; ++i){ // TC -> O(M*N)
    int time_taken = 0;
    int h0 = 0;
    
    // cout << "if k = "<< i << endl;
    for(int j=0; j< n; ++j){
      time_taken += (ceil(nums[j]*1.0/i));
      h0++;
      // cout << "tt: " << time_taken << "\n";
    }

    cout << "tt: " << time_taken << "\n\n";

    if(time_taken <= hours)
      return i;
    // if(time_taken <= hours)
    //   k = min(i, k);
    
    // if(time_taken == hours) break;
  }


  return maxi;
}

// brute force -> using Linear Search
long long calcTimeRequiredToEat(vector<int>& piles, const int& perHour){
  long long timeTaken = 0;

  for(int i=0; i<piles.size(); ++i){
    timeTaken += ceil((double)piles[i]/(double)perHour);
  }

  return timeTaken;
}
int minimumRateToEatBananas_brute(vector<int>& piles, const int& hours){
  int n = piles.size();

  int maxi = INT_MIN;
  for(int i=0; i<n; ++i) 
    maxi = max(maxi, piles[i]);

  for(int i=1; i<=maxi; ++i){
    int requiredTime = calcTimeRequiredToEat(piles, i);

    if(requiredTime <= hours)
      return i;
  }

  return maxi;
}


// optimal -> using Binary Search
int minimumRateToEatBananas_optimal(vector<int>& piles, const int& hours){
  int maxi = INT_MIN;
  for(int i=0; i<piles.size(); ++i){
    maxi = max(maxi, piles[i]);
  }
  
  int low = 1;
  int high = maxi;
  // int ans = maxi;

  while(low <= high){
    int mid = low + (high - low)/2;

    long long requiredTime = calcTimeRequiredToEat(piles, mid);
    // cout << "for: " << mid << ", the required time: " << requiredTime << "\n"; 

    if(requiredTime <= hours){
      // move left
      // eliminate right
      high = mid - 1;
      // ans = mid;
    } 
    else {
      // move right
      // eliminate left
      low = mid + 1;
    }
  }

  // total TC -> O(N + N*log2(MaxElement))
  // total SC -> O(1)
  return low;
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  int target_hours;
  cin >> target_hours;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }

  int k_bananas;

  // k_bananas = minimumRateToEatBananas_myBrute(v, target_hours);
  // k_bananas = minimumRateToEatBananas_brute(v, target_hours);
  k_bananas = minimumRateToEatBananas_optimal(v, target_hours);

  cout << k_bananas;

  

return 0;
}