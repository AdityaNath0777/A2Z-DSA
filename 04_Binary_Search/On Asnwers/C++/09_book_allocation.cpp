/**
 * Problem Statement: 
 * 
 * Given an array ‘arr of integer numbers, 
 * ‘arr[i]’ represents the number of pages in the ‘i-th’ book. 
 * There are a ‘m’ number of students, and the task is to allocate all the books to the students.
 * 
 * Allocate books in such a way that:
 *    * Each student gets at least one book.
 *    * Each book should be allocated to only one student.
 *    * Book allocation should be in a contiguous manner.
 * 
 * You have to allocate the book to ‘m’ students such that the maximum number of pages 
 * assigned to a student is minimum. 
 * 
 * If the allocation of books is not possible. return -1
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *          0    1   2   3
 * arr[] = [12, 34, 67, 90]
 * 
 * we've 2 studs ->[ 1st -> 12 + 34 = 46
 *                  2nd -> 67 + 90 = 157 ] -> max = 157
 * 
 *                 [ 1st -> 12 + 34 + 67 = 113 
 *                  2nd -> 90 ] ->            max = 113
 * 
 *                 [ 1st -> 12
 *                  2nd ->34 + 67 + 90 = 191 ] max = 191
 * 
 * here, in all these possible combinations, which satisfies the given conditions
 * only the 2nd combination where -> max = 113
 * has minimum pages of all others combinations
 * 
 * thus, we return 113
 * 
 * 
*/

int noOfStudentsToHoldBooks(vector<int>& nums, int pageLimit){
  int studCount = 1;
  int pagesHolding = nums[0];

  for(int i=1; i<nums.size(); ++i){

    // if student can hold the allowed no. of pages
    // let him that book
    if(pagesHolding + nums[i] <= pageLimit){
      pagesHolding += nums[i];
    }

    // if not, then
    else {
      // give the current book to the next student
      studCount++;
      pagesHolding = nums[i];
    }
  }


  // total TC -> O(N)
  // total SC -> O(1)
  return studCount;
}

int find_Minimum_of_MaximumPages_brute(vector<int>& nums, int studs){
  int n = nums.size();

  // if no. of students > no. of books we've
  if(n < studs) return -1;
  // as we're required to allot atleast one book to each student
  // and no can share the same book

  int low = *max_element(nums.begin(), nums.end());
  int high = accumulate(nums.begin(), nums.end(), 0);

  // maxPages -> max. pages one student can hold
  for(int maxPages = low; maxPages <= high; ++maxPages){
    int studentCount = noOfStudentsToHoldBooks(nums, maxPages);

    if(studentCount == studs)
      return maxPages;
  }

  // total TC -> O(N * (sum - max of nums[]))
  // total SC -> O(1) 
  return -1;
  
}

int find_Minimum_of_MaximumPages_optimal(vector<int>& nums, int studs){
  int n = nums.size();

  if (studs > n) return -1;

  int low = *max_element(nums.begin(), nums.end());
  int high = accumulate(nums.begin(), nums.end(), 0);

  while(low <= high){
    int mid = low + (high - low)/2;

    int studentCount = noOfStudentsToHoldBooks(nums, mid);

    if(studentCount <= studs){
      // it means, 1 student might hold too many pages than required
      // as we want minimum of this
      // so in order to reduce the max pages one can hold
      // we will move towards left
      // i.e. we will eliminate the right portion
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  } 

  // total TC -> O(N * Log2(sum - max of nums[]))
  // total SC -> O(1)
  return low;
}

int main(int argc, char* argv[]){
  vector<int> v;

  int size;
  cin >> size;

  int noOfStudents;
  cin >> noOfStudents;

  for(int i=0; i<size; ++i){
    int a;
    cin >> a;
    v.push_back(a);
  }


  int minOfMaxPages;

  // minOfMaxPages = find_Minimum_of_MaximumPages_brute(v, noOfStudents);
  minOfMaxPages = find_Minimum_of_MaximumPages_optimal(v, noOfStudents);

  cout << "The minimum of maximum pages alloted: " << minOfMaxPages;

return 0;
}