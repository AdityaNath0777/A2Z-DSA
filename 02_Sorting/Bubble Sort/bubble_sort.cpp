#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int size);
void getArray(int arr[], int size);
void showArray(int arr[], int size);
void swap(int &x, int &y);

int main(int argc, char* argv[]){
  int size;
  cin >> size;

  int arr[size];

  getArray(arr, size);

  bubble_sort(arr, size);

  showArray(arr, size);
return 0;
}

void bubble_sort(int arr[], int size){
  // send largest element to the end
  // by adjacent swapping

  for(int i=0; i<size-1; ++i){

    // brute force
    // for(int j=0; j<size-1; ++j){

    // better approach
    // as array is being sorted from the last element,
    // there is no need to sort till the end (which has been sorted)
    for(int j=0; j<size-1-i; ++j){
      if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
      }
    }
  }
}

void swap(int &x, int &y){
  int temp = x;
  x = y;
  y = temp;
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
