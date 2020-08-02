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


// Been working on a different approach to yesterday's challenge. I don't like the O(N*N*N) time complexity. This version will be O(N).
// Tomorrow I will finish this algorithm.

// #include <vector>
// #include <algorithm>

// int solution(vector<int> &A) {
//     std::vector<int> discOpen, discClose, numDiscs;
//     int intersections = 0, openDiscs = 0, closedDiscs = 0;
    
//     for (size_t i = 0; i < A.size(); ++i)
//     {
//         discOpen.push_back(i-A[i]);
//         discClose.push_back(i+A[i]);
//     }
//     std::sort(discOpen.begin(), discOpen.end());
//     std::sort(discClose.begin(), discClose.end());
//     // ////
//     // for (int s : discClose)
//     // {
//     //     std::cout << s << " ";
//     // }
//     // std::cout << endl << endl;
//     // ////
    
//     int rangeStart = 0, rangeEnd = 0, minValue = discOpen[0];
//     for (size_t i = 0; i < discOpen.size()-1; ++i)
//     {
//         openDiscs++;
//         rangeStart = discOpen[i];
//         rangeEnd = discOpen[i+1];
//         for (int j = rangeStart; j < rangeEnd; j++)
//         {
//             numDiscs.push_back(openDiscs);
//         }
//     }
//     // ////
//     // for (int s : numDiscs)
//     // {
//     //     std::cout << s << " ";
//     // }
//     // std::cout << endl;
//     // ////
    
//     for (size_t i = 0; i < discClose.size()-1; ++i)
//     {
//         closedDiscs++;
//         rangeStart = discClose[i];
//         rangeEnd = discClose[i+1];
//         if (rangeStart == rangeEnd)
//         {
//             closedDiscs++;
//             numDiscs[rangeStart-minValue]-=closedDiscs;
//         }
//         for (int j = rangeStart; j < rangeEnd; ++j)
//         {
//             if (j < *(std::end(numDiscs)-1))
//                 numDiscs[j-minValue]-=closedDiscs;
//         }
//     }
//     // ////
//     // for (int s : numDiscs)
//     // {
//     //     std::cout << s << " ";
//     // }
//     // std::cout << endl;
//     // ////
    
//     openDiscs = numDiscs[0];
//     for (size_t i = 1; i < numDiscs.size(); ++i)
//     {
//         if (numDiscs[i] > openDiscs)
//         {
//             for (int k = 0; k < numDiscs[i]-openDiscs; ++k)
//             {
//                 intersections += openDiscs;
//                 openDiscs++;
//             }
//             if (intersections > 10000000)
//                     return -1;
//             openDiscs = numDiscs[i];
//         }
//         else if (numDiscs[i] < openDiscs)
//         {
//             openDiscs = numDiscs[i];
//         }
//     }
//     return intersections;
// }


////////// OTHER CONTRIBUTIONS
///////////////////////////////////////////////////////////////////////////////// In addition I created this algorithm to help a friend in a challenge of his own. 
// I don't have the written specifications for it.

#include <vector>
#include <iostream>

inline void check(std::vector<char>& mySequence, std::vector<char>& myFragment, const int &i, int& myCounter, int &indexStart, bool &bErrorUsed, bool &bChecking)
{
    if (mySequence[i] == myFragment[i - indexStart])
    {
        if ((myFragment.begin() + i - indexStart + 1) == myFragment.end())
        {
            myCounter++;
            indexStart = -1;
            bChecking = bErrorUsed = false;
        }
    }
    else if (!bErrorUsed)
    {
        if ((myFragment.begin() + i - indexStart + 1) == myFragment.end())
        {
            myCounter++;
            indexStart = -1;
            bChecking = bErrorUsed = false;
        }
        else
        {
            bErrorUsed = true;
        }
    }
}

inline int function(std::vector<char> &mySequence, std::vector<char> &myFragment)
{
    int myCounter = 0, indexStart = -1, indexStartSecond = 0;
    bool bChecking = false, bErrorUsed = false;
    std::vector<int> possibles;

    for (size_t i = 0; i < mySequence.size(); ++i)
    {
        if (bChecking)
        {
            check(mySequence, myFragment, i, myCounter, indexStart, bErrorUsed, bChecking);

            if (mySequence[i] == myFragment[0])
            {
                possibles.push_back(i);
            }
            else if (i > 0 && mySequence[i] == myFragment[1])
            {
                possibles.push_back(i-1);
            }
        }
        else if (!bChecking)
        {
            if (mySequence[i] == myFragment[0])
            {
                bChecking = true;
                indexStart = i;
            }
            else if (i > 0 && mySequence[i] == myFragment[1])
            {
                bChecking = bErrorUsed = true;
                indexStart = i - 1;
            }
        }
    }

    // Second iteration here to operate with the other possible sequence matches starting points, in case that the specifications require it.

    return myCounter;
}

int main()
{
    std::vector<char> mySequence = {'a', 'd', 'D', 'F', 'a', 'd', 'a', 'd', 'F', 'a', 'F'};
    std::vector<char> myFragment = {'a', 'd'};
    int result = function(mySequence, myFragment);

    std::cout << result << std::endl;
    std::cin >> result;
    return 0;
}
