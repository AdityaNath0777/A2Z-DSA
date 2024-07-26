#include <bits/stdc++.h>
using namespace std;

void binary_sort(vector<int> &v){

  for(int i=0; i<v.size(); ++i){
    for(int j=0; j<v.size()-i-1; ++j){
      // if next adj. is smaller
      if(v[j] > v[j+1]){
        // swap
        int temp = v[j];
        v[j] = v[j+1];
        v[j+1] = temp;
      }
    }
  }

}

int secondLargestBrute(vector<int> &v){
  binary_sort(v); // for sorting: TC -> O(N^2) -> QS or MS O(NlogN)

  int Max = v[v.size() - 1];

  // there might be duplicates of largest element
  for(int j=v.size()-1; j>=0; --j){

    // in our sorted array/vector
    // the moment we encounter first ele smaller than the largest
    // return that index
    if(Max > v[j]){
      return j;
    }
  }
}

int secondLargestBetter(vector<int> &v){
  int max = 0;
  int sMax = 0;

  // find the largest
  for(int i=0; i<v.size(); ++i){
    if (v[max] < v[i])
      max = i;
  } // TC -> O(N)

  // find new largest which is smaller than the largest
  for(int k=0; k<v.size(); ++k){
    if(v[sMax] < v[k] && v[k] != v[max]){
      sMax = k;
    }
  } // TC -> O(N)

  // Total TC -> O(2N)

  return sMax;
}

int secondLargestOptimal(vector<int> &v){

    int max = v[0];
    int sMax = INT_MIN; // to include -ve numbers case
    for(int i=0; i<v.size(); ++i){
        if(v[i] > max){
            sMax = max;
            max = v[i];
        }

        else if(v[i] > sMax && v[i] != max){
            sMax = v[i];
        }

    }

  // if all are duplicate elements
    if(sMax == max || sMax == INT_MIN)
        return -1;

    return sMax;
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

  // int s_largest_index = secondLargestBrute(v);
  // int s_largest_index = secondLargestBetter(v);
  int s_largest = secondLargestOptimal(v);

  cout << s_largest;
  // cout << v[s_largest_index];
return 0;
}