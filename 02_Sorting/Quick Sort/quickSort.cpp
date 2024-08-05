#include <bits/stdc++.h>
using namespace std;

int my_partition(vector<int> &arr, int low, int high){
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

void qS(vector<int> &arr, int low, int high){
  if (low < high){
    int partition_index = my_partition(arr, low, high);
    qS(arr, low, partition_index - 1);
    qS(arr, partition_index + 1, high);
  }
}

void quickSort(vector<int> &arr){
  qS(arr, 0, arr.size()-1);
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

  quickSort(v);

  for(int i=0; i<size; ++i){
    cout << v[i] << " ";
  }
return 0;
}