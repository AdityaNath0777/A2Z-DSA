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

// TC -> O(M)
void markRow(vector<vector<int>>& matrix, int i){
  // set all non-zero elements as -1 in the row i:
  for(int j=0; j<matrix[0].size(); ++j){
    if(matrix[i][j] != 0)
      matrix[i][j] = -1;
  }
}

// TC -> O(N)
void markCol(vector<vector<int>>& matrix, int j){
  // set all non-zero elements as -1 in the col j:
  for(int i=0; i<matrix.size(); ++i){
    if(matrix[i][j] != 0)
      matrix[i][j] = -1;
  }
}

// find zero & mark elements with -1 in the row & col which are not zero
// after that loop again, 
// where elem = -1 -> set it as zero
vector<vector<int>> setMatrix_Zero_brute(vector<vector<int>>& matrix){

  int n = matrix.size();
  int m = matrix[0].size();

  // TC -> O(N*M*(M+N))
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      if(matrix[i][j] == 0){
        markRow(matrix, i); // TC -> O(M)
        markCol(matrix, j); // TC -> O(N)
      }
    }
  }

  // TC -> O(N*M)
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      if(matrix[i][j] == -1)
        matrix[i][j] = 0;
    }
  }

  // total TC -> O(NM(M+N) + NM)
          //  ~ O(N^3)
  // total SC -> O(1)
  return matrix;
}

// rows[] & cols[] -> to mark individual array
vector<vector<int>> setMatrix_Zero_better(vector<vector<int>>& matrix){
  int n = matrix.size();
  int m = matrix[0].size();

  bool rows[n] = {false};
  bool cols[m] = {false};

  // TC -> O(NM)
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      if (matrix[i][j] == 0){
        rows[i] = true;
        cols[j] = true;
      }
    }
  }

  // TC -> O(NM)
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      if(rows[i] || cols[j]){
        matrix[i][j] = 0;
      }
    }
  }

  // total TC -> O(2NM)
      //      ~ O(N^2)
  // total SC -> O(N+M)
  return matrix;
}

// in-place setting of zero with O(1) space
// by using 1st row and 1st col to keep track of rows & cols which are needed to set zero
vector<vector<int>> setMatrix_Zero_optimal(vector<vector<int>>&  matrix){
  int n = matrix.size();
  int m = matrix[0].size();

  int col0 = 1;

/*
      
      1 1 1 1 1
      0 1 1 1 1
      1 0 0 1 1
      1 1 1 1 1
      
            replace with
      cols[m] -> col0 + col[1...(m-1)]
      rows[n] -> rows[0...(n-1)]

      find zero, and mark respective index of rows[] & cols[]

      after that
      start a new loop to set elems of marked rows & cols with zero
      make sure to exclude rows[] and cols[]
      -> to prevent the marked indexes and preserve the index 
        where there is no need to set elems as zero

      then make the first row 0 if matrix[0][0] is zero

      make the first col 0 if col0 = 0 


*/


  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){

      if(matrix[i][j] == 0){
        matrix[i][0] = 0;

        if(j!=0)
          matrix[0][j] = 0;
        else col0 = 0;
      }
    }
  }


  for(int i=1; i<n; ++i){
    for(int j=1; j<m; ++j){
      if(matrix[i][0] == 0 || matrix[0][j] == 0 ){
        matrix[i][j] = 0;
      }
    }
  }

  if(matrix[0][0] == 0){
    for(int j=m-1; j>0; --j){
      matrix[0][j] = 0;
    }
  }

  if(col0 == 0){
    for(int i=0; i<n; ++i){
      matrix[i][0] = 0;
    }
  }
  return matrix;
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
  // ans = setMatrix_Zero_my_brute(v);
  // ans = setMatrix_Zero_brute(v);
  // ans = setMatrix_Zero_better(v);
  ans = setMatrix_Zero_optimal(v);

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