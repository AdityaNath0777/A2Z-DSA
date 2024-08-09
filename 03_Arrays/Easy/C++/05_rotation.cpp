#include <bits/stdc++.h>
using namespace std;

void rotateRight(vector<int>& nums, int k) {
        int n = nums.size();
        k = k  % n;

        vector<int> temp;
        for (int i = n-k; i<n; ++i){
          temp.push_back(nums[i]);
        }

        for (int i = n-k-1; i>=0; --i){
          nums[i+k] = nums[i];
        }

        for (int j = 0; j < k; ++j){
          nums[j] = temp[j];
        }
    }

void rotateLeft_brute(vector<int>& nums, int k){
  /*
    arr[] = [ 1 2 3 4 5 6 7 ]
    
    k -> degree of rotation

    k = 0 OR k%len(arr) = 0 -> no rotation

    k = 1
    arr[] = [ 2 3 4 5 6 7 1 ]

    k = 2
    arr[] = [ 3 4 5 6 7 1 2 ]

    arr[] = [ 1 2 3 4 5 6 7 ]

    temp[] = [first k elements]

    for i -> 
    arr[i] = arr[i+k-1]


    temp[] = [ i = [k-1 to len(arr) ]  ] + [ first k elements ]

    for i ->
      arr[i] = temp[i]
  */

  vector<int> temp;
  int n = nums.size();
  k = k%n;

  // TC -> O(N-k)
  for (int i=k; i<n; ++i){
    temp.push_back(nums[i]);
  }

  // TC -> O(k)
  for (int i = 0; i<k; ++i){
    temp.push_back(nums[i]);
  }

  // TC -> O(N)
  for (int i =0; i<n; ++i){
    nums[i] = temp[i];
  }


  // total TC -> O(2N)
  // total SC -> O(N)
}

void rotateLeft_array(int arr[], int size, int k){
  int temp[size] = {0};

  k = k%size;

  // 8
  // k = 3
  // 1 2 3 4 5 6 7 8 
  // index = 3
  // temp[0], arr[3] -> arr[size-1]

  // i = [0 -> k]
  // temp[size-k-i] = arr[i]

    for(int i=k; i<size; ++i){
      temp[i-k] = arr[i];
    }

    for(int i = 0; i<k; ++i){
      temp[size-k+i] = arr[i];
    }

    for(int i=0; i<size; ++i){
      arr[i] = temp[i];
    }

  // TC-> O(2N)
  // SC -> O(N)
}

void rotateLeft_better(vector<int>& nums, int k){
  int n = nums.size();
  k = k%n;

  vector<int> temp(k,0);

  // TC -> O(k)
  for (int i = 0; i < k; i++){
    temp[i] = nums[i];
  }

  // TC -> O(N-k)
  for (int i = k; i < n; i++){
    nums[i-k] = nums[i];
  }

  // TC -> O(k)
  for (int i=n-k; i<n; ++i){
    nums[i] = temp[i-n+k];
  }

  // TC -> O(N + k)
  // SC -> O(k)
}

void rotateRight_brute(vector<int>& nums, int k){
  /*
  arr[] = [ 1 2 3 4 5 6 7 8 ]

  k = 3
  arr[] = [ 6 7 8 1 2 3 4 5 ]

  temp[].append() -> arr[i], i = [size-k-1] -> [size-1] 

  temp[].append() -> arr[i], i = [0] -> [size-k-2]

  arr[i] = temp[i]
  */  

  int n = nums.size();
  k = k%n;

  vector<int> temp(n, 0);

  // TC -> O(k)
  for(int i=n-k; i<n; ++i){
    temp[i-(n-k)] = nums[i];
  }

  // TC -> O(N-k)
  for (int i = 0; i < n-k; i++){
    temp[i+k] = nums[i];
  }

  // TC -> O(N)
  for(int i=0; i<n; ++i){
    nums[i] = temp[i];
  }
  
  // total TC -> O(2N)
  // total SC -> O(N)
}

void rotateRight_better(vector<int>& nums, int k){
  int n = nums.size();
  k = k%n;

  vector<int> temp(k,0);

  // TC -> O(k)
  for(int i=n-k; i<n; ++i){
    temp[i-(n-k)] = nums[i];
  }

  // TC -> O(N-k)
  for(int i=n-k-1; i>=0; --i){
    nums[i+k] = nums[i];
  }

  // TC -> O(k)
  for(int i=0; i<k; ++i){
    nums[i] = temp[i];
  } 


  // total TC -> O(N+k)
  // total SC -> O(k)
}

// optimal -> using reversal algo
void Reverse(vector<int> &nums, int left, int right){
  while(left < right){
    int temp = nums[left];
    nums[left] = nums[right];
    nums[right] = temp;

    ++left;
    --right;
  }
}
void rotateRight_optimal(vector<int> &nums, int k){
  int n = nums.size();

  // arr[] = [ 1 2 3 4 5 6 7 8 ]

  // rev -> last k elements
  Reverse(nums, n-k, n-1); // TC -> O(N-k)
  // arr[] = [ 3 2 1 8 7 6 5 4 ]

  // rev -> rest of the elements
  Reverse(nums, 0, n-k-1); // TC -> O(k)
  // arr[] = [ 3 2 1 4 5 6 7 8 ]

  // rev -> complete array
  Reverse(nums, 0, n-1); // TC -> O(N)
  // arr[] = [ 6 7 8 1 2 3 4 5 ] -> our answer

  // total TC -> O(N)
  // total SC -> O(1) // since we are not using any extra space
  // just modifying the array itself using reversal
}

void rotateLeft_optimal(vector<int> &nums, int k){
  int n = nums.size();

  // arr[] = [ 1 2 3 4 5 6 7 8 ]


  // rev -> first k elements
  Reverse(nums, 0, k-1); // TC -> O(k)
  // arr[] = [ 3 2 1 4 5 6 7 8 ]

  // rev -> rest of the elements
  Reverse(nums, k, n-1); // TC -> O(N-k)
  // arr[] = [ 3 2 1 8 7 6 5 4 ]

  // rev -> compelete
  Reverse(nums, 0, n-1); // TC -> O(N)
  // arr[] = [ 4 5 6 7 8 1 2 3 ] -> our answer

  // total TC -> O(N)
  // total SC -> O(1) // since we are not using any extra space
  // just modifying the array itself using reversal
}


int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  for (int i=0; i<size; ++i) {
    int a;
    cin >> a;
    v.push_back(a); 
  }

  int k = 0;

  cin >> k;

  int arr[100];
  for (int i=0; i<size; ++i){
    arr[i] = v[i];
  }

  // rotateRight(v, k);
  // rotateRight_brute(v, k);
  // rotateRight_better(v, k);
  // rotateRight_optimal(v, k);
  // rotateLeft_brute(v, k);
  // rotateLeft_better(v, k);
  rotateLeft_optimal(v, k);
  // rotateLeft_array(arr, size, k);

  for (int i=0; i<size; ++i){
    cout << v[i] << " ";
    // cout << arr[i] << " ";
  }
return 0;
}