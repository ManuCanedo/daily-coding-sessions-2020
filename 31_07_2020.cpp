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


////////// SOLUTION PROGRESS
// INITIAL APPROACH 

// #include <vector>
// #include <numeric>
// #include <iostream>
// #include <algorithm>

// int solution(std::vector<int> &A) 
// {
//     if (A.empty() || A.size() == 1)
//         return 0;
    
//     int lBound = 0, hBound = 0;
//     int totalIntersections = 0;
    
//     std::vector<std::vector<int>> myIntersections;
//     std::vector<int> crosses(A.size(),0);
//     myIntersections.resize(A.size());
    
//     for (int i = 0; i < (int)A.size(); i++)
//     {
//         lBound = (i-A[i] > 0) ? i-A[i] : 0;
//         hBound = (i+A[i] < (int)A.size()) ? i+A[i] : (int)A.size();
//         for (int j = lBound; j < hBound; j++)
//         {
//             myIntersections[j].push_back(i);
//         }
//     }
//     for (int i = 0; i < (int)A.size(); i++)
//     {
//         lBound = (i-A[i] > 0) ? i-A[i] : 0;
//         hBound = (i+A[i] < (int)A.size()) ? i+A[i] : (int)A.size();
//         std::vector<int> crosses = myIntersections[lBound];
//         std::vector<int> unionVector;
//         std::vector<int>::iterator it;
//         for (int j = lBound+1; j < hBound; j++)
//         {
//             it=std::set_union (crosses.begin(), crosses.end(), myIntersections[j].begin(), myIntersections[j].end(), unionVector.begin());
//             unionVector.resize(it-unionVector.begin());
//             crosses = unionVector;
//         }
//         totalIntersections += crosses.size()-1;
//         if (totalIntersections > 10000000)
//             return -1;
//     }
//     return totalIntersections;
// }


////////// SOLUTION
// CORRECT BEHAVIOUR CODE, OPTIMIZATION TOMORROW
// Solved 02_08_2020 with time complexity O(N*logN)

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

template<class ForwardIt1, class ForwardIt2>
bool has_common_elements(ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last);

int solution(std::vector<int> &A) 
{
    if (A.empty() || A.size() == 1)
        return 0;
    
    int lBound = 0, hBound = 0;
    int totalIntersections = 0;
    std::vector<std::vector<int>> myRanges;
    myRanges.resize(A.size());

    for (int i = 0; i < (int)A.size(); i++)
    {
        lBound = (i-A[i] > 0) ? i-A[i] : 0;
        hBound = (i+A[i] < (int)A.size()) ? i+A[i] : (int)A.size();
        std::vector<int> rangeI(hBound+1-lBound) ;
        std::iota (std::begin(rangeI), std::end(rangeI), lBound);
        myRanges.push_back(rangeI);
        // for (int s : rangeI)
        // {
        //     std::cout << s << " ";
        // }
        // std::cout << endl;
    }

    for (std::size_t i = 0; i < myRanges.size(); i++)
    {
        for (std::size_t j = i+1; j < myRanges.size(); j++)
        {
            if (has_common_elements(myRanges[i].begin(), myRanges[i].end(), myRanges[j].begin(), myRanges[j].end()))
            {
                totalIntersections++;
                if (totalIntersections+1 > 10000000)
                    return -1;
            }
        }
    }
    return totalIntersections;
}

template<class ForwardIt1, class ForwardIt2>
inline bool has_common_elements(ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last)
{
    auto it = first;
    auto s_it = s_first;
    while(it < last && s_it < s_last)
    {
        if(*it == *s_it)
        {
            return true;
        }
        *it < *s_it ? ++it : ++s_it;
    }
    return false;
}

// Will re-do it tomorrow.
////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N*N*N)
////////// AVG ~ O(N*N*N)
