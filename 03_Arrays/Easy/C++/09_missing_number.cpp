#include <bits/stdc++.h>
using namespace std;

int my_partition(vector<int>& arr, int low, int high){
  int pivot = arr[low];
  int i = low;
  int j = high;

  while( i < j ){
    while( arr[i] <= pivot && i <= high - 1){
      ++i;
    }

    while( arr[j] > pivot && j >= low + 1){
      --j;
    }

    if(i < j){
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[low], arr[j]);

  return j;
}

void qS(vector<int>& arr, int low, int high){
  if (low < high){
    int partition_index = my_partition(arr, low, high);
    qS(arr, low, partition_index - 1);
    qS(arr, partition_index + 1, high);
  }
}

void quickSort(vector<int>& arr){
  qS(arr, 0, arr.size()-1);
}

int missingNumber_brute(vector<int>& a, int N){
  
  for(int i=1; i<=N; ++i){ // range of values

    // initially assume, the num 'i' is missing
    bool isMissing = true;
    for(int j=0; j<a.size(); ++j){ // ptr to the values of arr

      if(a[j] == i){
        // if number is found in the array
        // set the missing flag to false
        isMissing = false;
        break;
      }
    }

    if(isMissing){
      return i;
    }
  }

  return N;
}

int missingNumber_myBrute(vector<int>& a, int N) {
    // a[]: [1 -> n]
    // sort
    // diff b/w consectuive elements would be 1
    // the moment it is greater, 
    // break the loop, and return smaller + 1
    quickSort(a); // TC -> (NlogN)

    // TC -> O(N)
    for(int i=1; i<a.size(); ++i){
        if(a[i]-a[i-1] > 1){
            return a[i-1] + 1;
        }
    }

    // Total TC -> O(NlogN + N) 
    return N;
}

// better
int missingNumber_better(vector<int>& a, int N){
// hash map
  vector<bool> visited(N, false);

  // visited index -> [0, N-1]
  //    with value -> {0}

  // if value of arr acts as index for the visited
  // then value with 0 at the end will be the our answer

  for(int i=0; i<a.size(); ++i){
    visited[a[i]] = true;
  }

  for(int i=1; i<=a.size(); ++i){
    if (!visited[i]){
      return i;
    }
  }

  return N;
}

// optimal: method: #1 (using sum of N natural nums)
int missingNumber_optimal_sumN(vector<int>& a, int N){

  long sumN = N*(N+1)/2;

  long sum = 0;
  int rem = sumN;
  for(int i=0; i<a.size(); ++i){
    rem = rem - a[i];
    sum += a[i];
  }

  return rem;
}

// optimal: method: #2 (using XOR)
int missingNumber_optimal_xor(vector<int>& a, int N){
  int xor_N = 0;
  int xor_a = 0;

  // a ^ a = 0
  // 0 ^ a = a
  // xor_a ^ xor_N -> (1^1)^(2^2)^...^(missing Num)^...^(N^N)
            //     -> 0 ^ (missing Num) ^ 0
            //     -> missing Num
  for(int i=0; i<a.size(); ++i){
    // xor_N = 1^2^...^a.size() (remeber: a.size() -> N-1)
    xor_N = xor_N ^ (i+1);

    // xor of elements in the array
    xor_a = xor_a ^ a[i];
  }

  // to compensate the remaining N in the xor
  xor_N = xor_N ^ N;
  return xor_a ^ xor_N;

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

  // int missingNum = missingNumber_brute(v, target);
  // int missingNum = missingNumber_myBrute(v, target);
  // int missingNum = missingNumber_better(v, target);
  // int missingNum = missingNumber_optimal_sumN(v, target);
  int missingNum = missingNumber_optimal_xor(v, target);

  cout << "Missing Number is: " << missingNum;
return 0;
}