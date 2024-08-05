// given -> 1) sorted array
//          2) target to find in the array

#include <bits/stdc++.h>
using namespace std;

// it assumess the array is already sorted
int binarySearch(vector<int> &arr, int target){
  int low = 0;
  int high = arr.size() - 1;

  // it uses bisection method
  while( low <= high ){
    int mid = low + (high - low)/2;
    
    if( arr[mid] == target )
      return mid;

      // if mid element is > target
      //    -> target might be before the mid
      //    -> so update high
    else if( arr[mid] > target )
            high = mid - 1;

      // else if mid element is < target
      //    -> target might be after the mid
      //    -> update the loq
    else low = mid + 1;
  }

  // if target not found
  return -1;
}

int bs_algo(vector<int>&arr, int low, int high, int target){
  // base condition
  if( low > high ) return -1;


  int mid = low + (high-low)/2;

  if(arr[mid] == target)
    return mid;
  else if(arr[mid] > target)
    return bs_algo(arr, low, mid - 1, target);
  else return bs_algo(arr, mid + 1, high, target);

}

int binarySearch_recursive(vector<int>& arr, int target){
  int low = 0;
  int high = arr.size() - 1;

  return bs_algo(arr, low, high, target);
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  // enter sorted array
  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }

  int target;
  cin >> target;

  // int target_index = binarySearch(v, target);
  int target_index = binarySearch_recursive(v, target);

  if(target_index >= 0)
    cout << "Target found at index: " << target_index;
  else
    cout << "Target NOT found";
return 0;
}