/*
  Problem Statement: You are given an array of prices 
      where prices[i] is the price of a given stock on an ith day.

  You want to maximize your profit by choosing a single day to buy one stock 
  and choosing a different day in the future to sell that stock. 
  
  Return the maximum profit you can achieve from this transaction. 
  If you cannot achieve any profit, return 0.

*/

#include <bits/stdc++.h>
using namespace std;

/*
  we'll try to BUY the stocks,
    -> only when it's minimum

  and SELL when it's maximum

  // will not BUY & SELL on the same day,
    -> since, profit would be -> 0
*/

int maxProfit_brute(vector<int>& stocks){
  int maxi = INT_MIN;

  for(int i=0; i<stocks.size(); ++i){
    for(int j=i+1; j<stocks.size(); ++j){
      if (stocks[j] > stocks[i]){  
        maxi = max(maxi, stocks[j] - stocks[i]);
      }
    }
  }

  // total TC -> O(N^2)
  // total SC -> O(1)
  return maxi;
}

int maxProfit_optimal(vector<int>& stocks){
  int mini = stocks[0];
  int profit = 0;

  for(int i=1; i<stocks.size(); ++i){
    // calculating cost
    int cost = stocks[i] - mini;

    // to store the maximum profit
    profit = max(cost, profit);

    // to keep track of minimum stock
    mini = min(mini, stocks[i]);
  }

  // total TC -> O(N)
  // total SC -> O(1)
  return profit;
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

  // int maxProfit_brute_ans = maxProfit_brute(v);
  int maxProfit_brute_ans = maxProfit_optimal(v);

  cout << maxProfit_brute_ans;

return 0;
}