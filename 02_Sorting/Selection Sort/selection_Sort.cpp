#include <bits/stdc++.h>
using namespace std;

// function declaration
void selection_sort(int arr[], int size);
void getArray(int arr[], int size);
void showArray(int arr[], int size);
void swap(int &x, int &y){
  int temp = x;
  x = y;
  y = temp;
}

// using recursion
int select_min_index(vector<int> &arr, int start, int stop, int min_index);
vector<int> selection_sort_recursion(vector<int> &arr, int start);
void showVector(vector<int> &arr){
  for(int i=0; i<arr.size(); ++i) {
    cout << arr[i] << " ";
  }
}

int main(int argc, char* argv[]){
  int size;
  cin >> size;

  int arr[100];

  getArray(arr, size);

  // selection_sort(arr, size);

  vector<int> v;
  for(int i=0; i<size; ++i){
    v.push_back(arr[i]);
  }
  selection_sort_recursion(v, 0);

  // showArray(arr, size);
  showVector(v);
  
return 0;
}

// function definition
void selection_sort(int arr[], int size){
  // find minimum & place it at the front
  int min_index = 0;

  for(int i=0; i<size; ++i){
    min_index = i;
    for(int j=i+1; j<size; ++j){
      if(arr[min_index] > arr[j]){
        min_index = j;
      }
    }

/* Small Optimization */
    // don't swap if min_index != i
    if(min_index != i){
      swap(arr[min_index], arr[i]);
    }
  }
}



void getArray(int arr[], int size){
  for (int i = 0; i < size; ++i){
    cin >> arr[i];
  } 
}

void showArray(int arr[], int size){
  for(int i=0; i<size; ++i) {
    cout << arr[i] << " ";
  }
}


// selcting index of minimum element
int select_min_index(vector<int> &arr, int start, int stop, int min_index){

  // base condition
  if (start > stop)
    return min_index;

  // if elem at min_index is greater
  // means there is an element which is smaller than it
  if(arr[min_index] > arr[start])
    min_index = start; // update the min_index

  // go to next element and return the min_index
  return select_min_index(arr, start+1, stop, min_index);
 
}

// recursion implementation with vectors
vector<int> selection_sort_recursion(vector<int> &arr, int start = 0){

  // base condition
  if(start >= arr.size())
    return arr;

  int min_index = select_min_index(arr, start, arr.size()-1, start);

  if(min_index != start)
    swap(arr[min_index], arr[start]);
  return selection_sort_recursion(arr, start+1);
}