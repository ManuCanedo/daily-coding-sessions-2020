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


#include <vector>
#include <numeric>
#include <iostream>

int solution(std::vector<int> &A) 
{
    if (A.empty() || A.size() == 1)
        return 0;
        
    int totalIntersections = 0, N = A.size() + A[A.size()-2] -1;
    std::vector<int> hLimit(N,0);
    unsigned int itIndex = 0;
    
    for (unsigned int i = 0; i < A.size()-1; i++)
    {   
        if (A[i] != 0)
            hLimit[i+A[i]]++; 
    }
    // for (auto it = hLimit.begin(); it != hLimit.end(); ++it)
    // {
    //     cout << *it << " ";
    // }
    
    // std::cout << std::endl;
            
    for (int i = A.size()-1; i >= 0; i--)
    {
        if (i != (int)A.size()-1)
            hLimit[i+A[i]]--;
        
        itIndex = (i-A[i] > 0) ? (i-A[i]) : 0;
        totalIntersections += (accumulate(hLimit.begin()+itIndex, hLimit.end(), 0));
        
        if (totalIntersections > 10000000)
            return -1;
    }
    // for (auto it = hLimit.begin(); it != hLimit.end(); ++it)
    // {
    //     cout << *it << " ";
    // }
    
    return totalIntersections;
}


//// Discarded first approach because was calculatin unique intersections instead of combination with repetition

#include <vector>
#include <numeric>
#include <iostream>

int solution(std::vector<int> &A) 
{
    if (A.empty() || A.size() == 1)
        return 0;
    
    int lBound = 0, hBound = 0;
    int totalIntersections = 0;
    
    std::vector<std::vector<int>> myIntersections;
    myIntersections.resize(A.size());
    
    for (int i = 0; i < (int)A.size(); i++)
    {
        lBound = (i-A[i] > 0) ? i-A[i] : 0;
        hBound = (i+A[i] < (int)A.size()) ? i+A[i] : (int)A.size();
        for (int j = lBound; j < hBound; j++)
        {
            myIntersections[j].push_back(i);
        }
    }

    // Tomorrow will complete this section.

    if (totalIntersections > 10000000)
        return -1;
    return totalIntersections;
}