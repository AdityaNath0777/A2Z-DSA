/*
  Problem Statement: Given a matrix, 
    if an element in the matrix is 0 
    then you will have to set its entire column and row to 0 
    and then return the matrix.
*/

#include <bits/stdc++.h>
using namespace std;

// if only one zero is present in the matrix
vector<vector<int>> setMatrix_Zero_oneZero_brute(vector<vector<int>>& nums){
  vector<vector<int>> ans;
  int coord[2] = {-1, -1};

  for(int i=0; i<nums.size(); ++i){
    for(int j=0; j<nums[i].size(); ++j){
      if( nums[i][j] == 0){
        coord[0] = i;
        coord[1] = j;
        break;
      }
    }

    if(coord[0] != -1)
      break;
  }

/*
  for(int i=0; i<nums.size(); ++i){
    nums[i][coord[1]] = 0;
  }

  for(int j=0; j<nums[0].size(); ++j){
    nums[coord[0]][j] = 0;
  }

*/

  for(int i=0; i<nums.size(); ++i){
    vector<int> temp;
    for(int j=0; j<nums[i].size(); ++j){
      if( i == coord[0] || j == coord[1] )
        temp.push_back(0);
      else 
        temp.push_back(nums[i][j]);
    }
    ans.push_back(temp);
  }

  return ans;
}

// if more than one zero is present in the matrix
vector<vector<int>> setMatrix_Zero_my_brute(vector<vector<int>>& nums){
  /* Side Note: Bro, I wrote this logic myself 😎 in one-go  */
  
  // initialsing 2D vector (Matrix) with 0
  vector<vector<int>> ans(nums.size(), vector<int>(nums[0].size(), 0));

  vector<pair<int, int>> coord;

  // first get to know where are the zeros in the Matrix
  for(int i=0; i<nums.size(); ++i){
    vector<int> temp(nums[0].size(), 0);
    for(int j=0; j<nums[0].size(); ++j){
      if( nums[i][j] == 0 ){
        coord.push_back(pair<int, int>(i , j));
          
      }
      else temp[j] = nums[i][j];
    }

    ans[i] = temp;
  }

  for(auto it:coord){
    cout << it.first << ", " << it.second << "\n";
    for(int i=0; i<nums.size(); ++i){
      ans[i][it.second] = 0;
    }

    for(int j=0; j<nums[0].size(); ++j){
      ans[it.first][j] = 0;
    }
  }

  cout << endl;

  return ans;
}

// for in-place conversion
void setZeroes(vector<vector<int>>& matrix) {

  vector<pair<int, int>> coord;

  // first get to know where are the zeros in the Matrix
  for(int i=0; i<matrix.size(); ++i){
    for(int j=0; j<matrix[0].size(); ++j){
      if( matrix[i][j] == 0 ){
        coord.push_back(pair<int, int>(i , j));
          
      }
    }
  }

  for(auto it:coord){
    // cout << it.first << ", " << it.second << "\n";
    for(int i=0; i<matrix.size(); ++i){
      matrix[i][it.second] = 0;
    }

    for(int j=0; j<matrix[0].size(); ++j){
      matrix[it.first][j] = 0;
    }
  }
}

int main(int argc, char* argv[]){
  vector<vector<int>> v;
  int rows;
  int cols;
  cin >> rows;
  cin >> cols;

  for(int i=0; i<rows; ++i){
    vector<int> temp;
    for(int j=0; j<cols; ++j){
      int a;
      cin >> a;
      temp.push_back(a);
    }
    v.push_back(temp);
  }

  vector<vector<int>> ans(rows, vector<int>(cols, 0));

  // ans = setMatrix_Zero_oneZero_brute(v);
  ans = setMatrix_Zero_my_brute(v);

  for(int i=0; i<v.size(); ++i){
    for(int j=0; j<v[i].size(); ++j){
      cout << v[i][j] << " ";
    }
    cout << "\n";
  }

  cout << "\n\nAnswer is: \n";
  for(int i=0; i<ans.size(); ++i){
    for(int j=0; j<ans[i].size(); ++j){
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
return 0;
} 