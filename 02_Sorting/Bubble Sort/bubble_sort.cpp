#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int size);
void bubbleSwap(int arr[], int start, int stop){
  // base condition
  if(start > stop)
    return;

  // now, after, say, stop = 10
  // start = 9
  // do something
  // call bubbleSwap -> burst finish

  if (arr[start] > arr[stop]){
    int temp = arr[start];
    arr[start] = arr[stop];
    arr[stop] =  temp;


    cout << "(" << arr[stop] << "," << arr[start] << ")"
         << "(" << arr[start] << "," << arr[stop] << ")" << endl;
  }
  
  bubbleSwap(arr, start+1, stop);


}
void bubble_sort_recursion(int arr[], int start, int stop){
  // fn01 -> no of iterate
  // fn02 -> iterate through array & swap

  // for fn01: base case -> n <= 0
  // for fn02: base case -> n <= 1

  // fn01 -> @params -> (arr[], start, stop)
  // fn02 -> @params -> (arr[], start, stop)

  // fn02 -> bubbleSwap

  if(start > stop)
    return;

  bubbleSwap(arr, start, stop-start);



  bubble_sort_recursion(arr, start+1, stop);
  
}
void getArray(int arr[], int size);
void showArray(int arr[], int size);
void swap(int &x, int &y);

int main(int argc, char* argv[]){
  int size;
  cin >> size;

  int arr[size];

  getArray(arr, size);

  // bubble_sort(arr, size);
  bubble_sort_recursion(arr, 0, size-1);

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
