#include <bits/stdc++.h>
using namespace std;

vector<int> arrayIntersection_brute(vector<int> &arr1, int n, vector<int> &arr2, int m){
	// TC -> O(n*m)
	// SC -> O(m)

  // array to keep track of visited elements,
  // if visited that means they are already in the intersection array
	vector<int> visited(m, 0); // 0 -> NOT visited, 1 -> visited

	vector<int> myIntersection;

  // iterate over 1st array
	for (int i=0; i<n; ++i){

    // iterate over 2ns array
		for (int j=0; j<m; ++j){

      // check whether visted or not
			if ( arr1[i] == arr2[j] && visited[j] == 0){
				myIntersection.push_back(arr2[j]);
				visited[j] = 1;
				break;
			}

			if ( arr1[i] < arr2[j]){
        // it means, all other elements in the arr2 will be greater than arr1[i]
        // so break inner loop,
        // and move onto the next iteration of 'i'
				break;
			}
		}
	}

	return myIntersection;

}

vector<int> arrayIntersection_optimal(vector<int> &arr1, int n, vector<int> &arr2, int m) {
	// TC -. O( n + m )
	// SC -> O( min(m, n) )

  // 2-ptr approach
	int i = 0;
	int j = 0;

	vector<int> myIntersection;

	while( i<n && j<m ){

    if (arr1[i] < arr2[j]){
      // it means
      // there in sorted arr2, all other elements will be > arr1[i]
      // thus we increment i
      // to move onto the next element in arr1
      ++i;
    }

    else if (arr1[i] > arr2[j]){
    // similarly move onto the next element in arr2
      ++j;
    }
    else {
    // if both are equal,
    // insert them into the array
    // and move onto the next element in both the arrays
      myIntersection.push_back(arr1[i]);
      ++i;
      ++j;
    }
	}

	return myIntersection;
}

vector<int> intersection_unique(vector<int>& nums1, vector<int>& nums2) {
     unordered_set<int> nums1_set(nums1.begin(), nums1.end());
     unordered_set<int> myIntersection;

     for ( int it : nums2 ){
      if (nums1_set.count(it)){
        // if 'it' is in nums1_set
        myIntersection.insert(it);
      }
     }

     return vector<int>(myIntersection.begin(), myIntersection.end());
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


  // vector<int> myIntersection =  arrayIntersection_brute(a, sizeA, b, sizeB);
  // vector<int> myIntersection =  arrayIntersection_optimal(a, sizeA, b, sizeB);
  vector<int> myIntersection =  intersection_unique(a, b);

  for (int i=0; i<myIntersection.size(); ++i){
    cout << myIntersection[i] << " ";
  }

  return 0;
}