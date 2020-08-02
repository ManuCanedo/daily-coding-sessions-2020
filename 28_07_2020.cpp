////////// CHALLENGE DESCRIPTION

// Write a function

// int solution(vector<int> &A);

// that, given an array A consisting of N integers, returns the number of distinct values in array A.

// For example, given array A consisting of six elements such that:

//  A[0] = 2    A[1] = 1    A[2] = 1
//  A[3] = 2    A[4] = 3    A[5] = 1
// the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [0..100,000];
// each element of array A is an integer within the range [−1,000,000..1,000,000].


////////// SOLUTION

#include <algorithm>
#include <vector>

int solution(vector<int> &A) {
    if (A.size() == 0)
        return 0;
        
    std::sort(A.begin(),A.end());
    auto it = std::unique(A.begin(), A.end());
    A.resize(std::distance(A.begin(), it));
    
    return A.size();
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N*logN)
////////// AVG ~ O(N*logN)
