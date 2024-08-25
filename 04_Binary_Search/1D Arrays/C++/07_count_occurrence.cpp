/*
 * Problem Statement
 * 
 * You are given a sorted array containing N integers and a number X, 
 * you have to find the occurrences of X in the given array.
 */

#include<bits/stdc++.h>
using namespace std;

int count_brute(vector<int>& arr, int n, const int &target) {
  int cnt = 0;

  for(int i=0; i<n; ++i){
    if(arr[i] == target)
      cnt++;
  }

  return cnt;
}

int firstOccurrence(vector<int>& arr, const int &target){
  int n = arr.size();
  int first = -1;

  int low = 0;
  int high = n-1;

  while(low <= high){
    int mid = low + (high-low)/2;

    if(arr[mid] == target){
      first = mid;
      high = mid - 1;
    }
    else if(arr[mid] < target){
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }

  return first;
}

int lastOccurrence(vector<int>& arr, const int &target){
  int n = arr.size();
  int last = -1;

  int low = 0;
  int high = n-1;

  while(low <= high){
    int mid = low + (high - low)/2;

    if(arr[mid] == target){
      last = mid;
      low = mid + 1;
    }
    else if(arr[mid] < target){
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }

  return last;
}

int count_optimal(vector<int>& arr, int n, const int &target) {
  
  int cnt = 0;
  /*
    n -> 12
    arr[] = [1 2 2 2 2 4 4 5 5 6 7 7]
    target -> 2

    we know that array is -> sorted,

    if we take any random value, say num, from the array 

    if num == target
      cnt++

    if num < target
      -> it would mean, the target might exist after the num,
      -> to reach there, we need to move right
      -> for that -> low = curr_pos + 1

    if num < target
      -> it would mean, the target might exist before the num,
      -> to reach there, we need to move left
      -> for that -> high = curr_pos - 1


    We can also do something,
    if we can somehow know the starting & ending point of the target,
    then by subtracting the position distance
    we can get the count

    starting point -> lower bound of target
    ending point -> upper bound of target
  */

  int start = firstOccurrence(arr, target);

  // target not found
  if (start == -1)
    return 0;
  
  int end = lastOccurrence(arr, target);

  // adding 1 to include the 'start' and 'end' indices
  cnt = end - start + 1;

  return cnt;
}

int count_optimal_STL(vector<int>& arr, int n, const int &target) {

  // if we use C++ STL
  auto first = lower_bound(arr.begin(), arr.end(), target);
  auto last = upper_bound(arr.begin(), arr.end(), target);

  return int(last - first);
}

int main(){
  vector<int> v;

  int size; 
  cin>>size;

  int target;
  cin >> target;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }

  int ans;
  // ans = count_brute(v, size, target);
  // ans = count_optimal(v, size, target);
  ans = count_optimal_STL(v, size, target);
  cout << "The number of occurrences of " << target << " is: "
        << ans << "\n";
  return 0;
}

