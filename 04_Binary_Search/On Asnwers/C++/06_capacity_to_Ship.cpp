/**
 * Problem Statement: 
 * 
 * You are the owner of a Shipment company. 
 * You use conveyor belts to ship packages from one port to another. 
 * The packages must be shipped within 'd' days.
 * 
 * The weights of the packages are given in an array 'of weights'. 
 * The packages are loaded on the conveyor belts every day in the same order 
 * as they appear in the array. 
 * The loaded weights must not exceed the maximum weight capacity of the ship.
 * 
 * Find out the least-weight capacity so that you can ship all the packages within 'd' days.
*/

#include <bits/stdc++.h>
using namespace std;

int findRequiredShipmentDays(vector<int>& weights, const int& cap){
  int n = weights.size();

  int days = 1; // on first day
  int load = 0;
  for(int i=0; i<n; ++i){
    if(load + weights[i] > cap){
      days++; // ship it next day
      load = weights[i]; // load the weight for the shipment on next shipment day
    }
    else {
      // load the weight on the same day
      load += weights[i];
    }
  }

  // total TC -> O(N)
  // total SC -> O(1)
  return days;

  /**
      int days = 0;
      int w01 = 0;
      for(int i=0; i<n; ++i){
        w01 += weights[i]; 
        if(w01 > cap){
          w01 = weights[i];
          days++;
        }
      }

      // ship the remaining weights
      days++;

      return days;
  */
}

// brute force  -> Linear Search
int findLeastCapToShipInDdays_my_brute(vector<int>& weights, const int& d){
  int n = weights.size();

  int maxi = INT_MIN;
  long long sum = 0;
  for(int i=0; i<n; ++i){
    maxi = max(maxi, weights[i]);
    sum += weights[i];
  }

  int ans = sum;
  // cout << "sum is: " << sum <<"\n";
  for(int w = maxi; w<= sum; ++w){
    int shipmentDays = 0;

    long long w01 = 0;
    cout << "if mini w: " << w << "\n";
    shipmentDays = findRequiredShipmentDays(weights, w);
    // for (int i = 0; i < n; i++){
    //   w01 += weights[i];
    //   if(w01 > w){
    //     w01 = weights[i];
    //     shipmentDays++;
    //   }
    //   // cout << shipmentDays << "th day: " << w01 << "\n";
    // }

    // shipmentDays++;
    cout << "shipment days: " << shipmentDays << "\n" << endl;

    if(shipmentDays <= d){
      ans = min(ans, w);
      break;
    }
  }

  return ans;
}

// optimal -> Binary Search
int findLeastCapToShipInDdays_my_optimal(vector<int>& weights, const int& d){
  int n = weights.size();

  int maxi = INT_MIN;
  long long sum = 0;
  for(int i=0; i<n; ++i){
    maxi = max(maxi, weights[i]);
    sum += weights[i];
  }

  int low = maxi;
  int high = sum;
  // int ans = -1;
  // using STL to find ax & accumulate
  /*
  low = *max_element(weights.begin(), weights.end());
  // in accumulate, the last arg is initializer, a Starting value to add other values to.
  high = accumulate(weights.begin(), weights.end(), 0); 
  */
  while(low <= high){
    int mid = low + (high - low)/2;

    int shipmentDays = findRequiredShipmentDays(weights, mid);

    if(shipmentDays <= d){
      // ans = mid; // as low points to the target at the end of the loop 
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }

  // return ans;

  // cout << low << ", " << high <<"\n\n";
  // -> as we got to know, low will always point at the req. mini weight
  // so we are returning low
  return low;

  // total TC -> O(N*log2(sum - maxi))
  // total SC -> O(1)
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  int days;
  cin >> days;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }


  int leastCapacity;

  // leastCapacity = findLeastCapToShipInDdays_my_brute(v, days);
  leastCapacity = findLeastCapToShipInDdays_my_optimal(v, days);

  cout << "Least capacity to ship within " << days << " days: " << leastCapacity;

return 0;
}