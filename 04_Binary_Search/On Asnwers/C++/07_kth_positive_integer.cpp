/**
 * Problem Statement: 
 * 
 * You are given a strictly increasing array ‘vec’ and a positive integer 'k'. 
 * Find the 'kth' positive integer missing from 'vec'.
*/

#include <bits/stdc++.h>
using namespace std;

// linear search to find
bool isNumberFound_brute(vector<int>& nums, const int& target){
  int n = nums.size();

  int i=0;
  while(nums[i] <= target && i<n){
    if(nums[i] == target)
      return true;
    ++i;
  }

  return false;
}

// binary search to find
bool isNumberFound_optimal(vector<int>& nums, const int& target){
  int n = nums.size();
  int low = 0;
  int high = n - 1;

  while(low <= high){
    int mid = low + (high - low)/2;

    if(nums[mid] == target)
      return true;

    if(nums[mid] > target){
      high = mid - 1;
    }

    else low = mid + 1;
  }

  return false;
}

// brute force
int find_kth_missing_integer_my_brute(vector<int>& nums, const int& k){

  int n = nums.size();

  int maxi = *max_element(nums.begin(), nums.end());

  int cnt = 0;
  for(int i = 1; i<= maxi; ++i){ // TC -> O(MaxiElement)

    // TC -> O(logN)
    if(! isNumberFound_optimal(nums, i)){
      cnt++;
    }

    if(cnt == k)
      return i;
  }

  // if 1 to maxi all are present
  // return maxi + k;

  // if less than k are missing
  return maxi + k - cnt;

  // total TC -> O(MaxiElement * logN)
  // total SC -> O(1)
}

// brute force -> Linear Search
int find_kth_missing_integer_better(vector<int>& nums, int k) {

  int n = nums.size();

  for (int i = 0; i < n; i++) {
    if (nums[i] <= k) k++; //shifting k
    else break;
  }

    // total TC -> O(N)
    // total SC -> O(1)
    return k;
}

// optimal -> using Binary Search
int find_kth_missing_integer_optimal(vector<int>& nums, int k){
  int n = nums.size();
  int low = 0;
  int high = n-1;

  /**
   * 
   * basically what we're doing is,
   * 
   * after observing the array, it's index and the number it should have 
   *        to find the kth missing number
   * 
   * we got to know, 
   *    * the array must contain n+k elements
   *    * the difference b/w two consecutive elements would be 1 is no number is missing b/w them
   *    * ideally -> (index + 1) should be the element at that index
   *   
   * so we're subtracting the element at index mid with the number it's supposed to contain
   * i.e. nums[mid] - (mid + 1)
   * 
   * if diff > k:
   *    upto the current index there are more missing numbers than the required one
   *    eliminate right -> move left
   *    high = mid - 1;
   * 
   * if diff == k:
   *    upto the current index, there are required missing numbers,
   *    However, we need to continue searching to find the smallest index where this happens.
   *    to ensures we accurately determine the k-th missing number's position.
   *    eliminate right -> move left
   *    high = mid - 1;
   * 
   * if diff < k:
   *    upto the current index, there are less missing number than the required one
   *    eliminate left -> move right
   *    low = mid + 1
   * 
   * loop ends
   * 
   * We don't break the loop on exact matches because we want to find the first position
   * where the count of missing numbers is greater than or equal to k.
   * 
  */
  while(low <= high){
    int mid = low + (high - low)/2;

    int nofMissingNums = nums[mid] - (mid + 1);

    // cout << nofMissingNums << ", \t";
    // cout << high << " :: " << low << "\n\n";
    if (nofMissingNums < k) low = mid + 1;
    else high = mid - 1;;

  }

  // cout << endl;
  // cout << high << " :: " << low << "\n\n";

  // After the loop, low is the position where the k-th missing number would be.
  // The k-th missing number is k more than the number of elements before it.
  return k + low;

  // or
  // return k + high + 1;
  // as the loop ends when low crosses high, 
  //    and they end up adjacent to each other, differing by 1
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


  int kthMissingNum;

  // kthMissingNum = find_kth_missing_integer_my_brute(v, k);
  // kthMissingNum = find_kth_missing_integer_better(v, k);
  kthMissingNum = find_kth_missing_integer_optimal(v, k);

  cout << "kth missing positive integer is: " << kthMissingNum;

return 0;
}