#include <bits/stdc++.h>
using namespace std;


// max size of array
// gloabally     -> 10^7
// inside main() -> 10^6 

// using sorting (Brute force)
void selection_sort(vector<int> &v){
  
  for(int i=0; i<v.size(); ++i){
    int min = i;
    for(int j=0; j<v.size(); ++j){
      if(v[j] < v[min])
        min = j;
    }

    int temp = v[i];
    v[i] = v[min];
    v[min] = temp;
  } 
}

int largestBrute(vector<int> &v){
  selection_sort(v);

  // return the last element
  return v.back();
}

// Optimal approach
int largestElement(vector<int> &v){
  int max = v[0]; // initialization

  // TC -> O(N)
  // SC -> O(1)
  for(int i=0; i<v.size(); ++i){
    if(v[i] > max)
      max = i;
  }

  return max;
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

  // int largest_index = largestElement(v);
  int largest_index = largestBrute(v);

  cout << v[largest_index];

return 0;
}