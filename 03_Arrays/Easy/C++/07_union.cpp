// given -> 2 sorted array
// return -> union with distinct elements in sorted order


#include <bits/stdc++.h>
using namespace std;

vector < int > unionOfArray_brute(vector < int > a, vector < int > b) {
    set<int> st; // ordered set to preserve the order

    for (int i=0; i<a.size(); ++i){
        st.insert(a[i]);
    }

    for (int i=0; i<b.size(); ++i){
        st.insert(b[i]);
    }

    vector<int> myUnion;

    for (auto it: st){
        myUnion.push_back(it);
    }

    return myUnion;

}

vector < int > unionOfArray_Optimal(vector < int > a, vector < int > b) {
//    2-ptr Approach -> optimal
  int n1 = a.size();
  int n2 = b.size();

  vector<int> myUnion;

  int i = 0;
  int j = 0;

  while(i<n1 && j<n2){
      if(a[i] <= b[j]){
           if(myUnion.size() == 0 || myUnion.back() != a[i] ){
               myUnion.push_back(a[i]);
           }
           i++;
      }
      else {
           if(myUnion.size() == 0 || myUnion.back() != b[j] ){
               myUnion.push_back(b[j]);
           }
           j++;

      }
  }

   // if 2nd array is exhausted earlier
   // but 1st array still remains
  while(i<n1){
        if(myUnion.size() == 0 || myUnion.back() != a[i] ){
            myUnion.push_back(a[i]);
        }
        i++;
  }

   // if 1st array is exhausted earlier
   // but 2nd array still remains
  while(j<n2){
       if(myUnion.size() == 0 || myUnion.back() != b[j] ){
            myUnion.push_back(b[j]);
        }
        j++;
  }

   return myUnion;
}

int main(int argc, char* argv[]){
  vector<int> a;
  vector<int> b;

  int sizeA;
  cin >> sizeA;
  for (int i=0; i<sizeA; ++i) {
    int x;
    cin >> x;
    a.push_back(x); 
  }

  int sizeB;
  cin >> sizeB;
  for (int i=0; i<sizeB; ++i) {
    int x;
    cin >> x;
    b.push_back(x);
  }


  // vector<int> myUnion =  sortedArray_brute(a, b);
  vector<int> myUnion =  unionOfArray_Optimal(a, b);

  for (int i=0; i<myUnion.size(); ++i){
    cout << myUnion[i] << " ";
  }
return 0;
}

