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

int main(int argc, char* argv[]){
  int size;
  cin >> size;

  int arr[size];

  getArray(arr, size);

  selection_sort(arr, size);

  showArray(arr, size);
  
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
