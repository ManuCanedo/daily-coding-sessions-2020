////////// CHALLENGE DESCRIPTION

// We draw N discs on a plane. The discs are numbered from 0 to N − 1. An array A of N non-negative integers, specifying the radiuses of the discs, is given. The J-th disc is drawn with its center at (J, 0) and radius A[J].

// We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).

// The figure below shows discs drawn for N = 6 and A as follows:

//   A[0] = 1
//   A[1] = 5
//   A[2] = 2
//   A[3] = 1
//   A[4] = 4
//   A[5] = 0

// There are eleven (unordered) pairs of discs that intersect, namely:

// discs 1 and 4 intersect, and both intersect with all the other discs;
// disc 2 also intersects with discs 0 and 3.
// Write a function:

// int solution(vector<int> &A);

// that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. The function should return −1 if the number of intersecting pairs exceeds 10,000,000.

// Given array A shown above, the function should return 11, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [0..100,000];
// each element of array A is an integer within the range [0..2,147,483,647].

////////// SOLUTION
// I re-did the algortithm from past days in order to reduce time complexity.
// This is the final O(N*logN) solution with 100% performance scores.
    
#include <vector>
#include <algorithm>

int solution(std::vector<int> &A) 
{
    std::vector<long int> discOpen, discClose;
    int intersections = 0, openDiscs = 0;
    
    for (size_t i = 0; i < A.size(); ++i)
    {
        discOpen.push_back(i-A[i]);
        discClose.push_back(i+A[i]);
    }
    
    std::sort(discOpen.begin(), discOpen.end());
    std::sort(discClose.begin(), discClose.end());
    
    for (size_t i = 0, j = 0; i < discOpen.size(); i++)
    {
        if (discOpen[i] <= discClose[j])
        {
            intersections += openDiscs++;
            if (intersections > 10000000)
                return -1;
        }
        else if (discOpen[i] > discClose[j])
        {
            openDiscs--;
            j++;
            i--;
        }
    }
    
    return intersections;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)
////////// AVG ~ O(N)
