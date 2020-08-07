////////// CHALLENGE DESCRIPTION

// An array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.

// For example, consider array A such that

//  A[0] = 3    A[1] = 4    A[2] =  3
//  A[3] = 2    A[4] = 3    A[5] = -1
//  A[6] = 3    A[7] = 3

// The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.

// Write a function

// int solution(vector<int> &A);

// that, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. The function should return −1 if array A does not have a dominator.

// For example, given array A such that

//  A[0] = 3    A[1] = 4    A[2] =  3
//  A[3] = 2    A[4] = 3    A[5] = -1
//  A[6] = 3    A[7] = 3

// the function may return 0, 2, 4, 6 or 7, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [0..100,000];
// each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].


////////// SOLUTION 

#include <algorithm>
#include <vector>

int solution(std::vector<int> &A) 
{
    if (A.empty())
        return -1;
    
    const unsigned int half = (A.size()/2);
    std::vector<int> myVector = A;
    std::sort(myVector.begin(), myVector.end());
    
    unsigned int occurrences = 0;
    long int previousValue = myVector[0];
    
    for (size_t i = 0; i < myVector.size(); ++i)
    {
        if (previousValue == myVector[i])
            ++occurrences;
        else
        {
            occurrences = 1;
            previousValue = myVector[i];
        }
        
        if (occurrences > half)
        {
            auto it = std::find (A.begin(), A.end(), previousValue);
            return (it-A.begin());
        }
    }
    return -1; 
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(NlogN)
////////// AVG ~ O(N)


////////// CHALLENGE DESCRIPTION

// A non-empty array A consisting of N integers is given.

// The leader of this array is the value that occurs in more than half of the elements of A.

// An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.

// For example, given array A such that:

//     A[0] = 4
//     A[1] = 3
//     A[2] = 4
//     A[3] = 4
//     A[4] = 4
//     A[5] = 2

// we can find two equi leaders:

// 0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
// 2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
// The goal is to count the number of equi leaders.

// Write a function:

// int solution(vector<int> &A);

// that, given a non-empty array A consisting of N integers, returns the number of equi leaders.

// For example, given:

//     A[0] = 4
//     A[1] = 3
//     A[2] = 4
//     A[3] = 4
//     A[4] = 4
//     A[5] = 2

// the function should return 2, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].


////////// SOLUTION 

#include <algorithm>
#include <vector>
//#include <iostream>

int solution(std::vector<int> &A) 
{
    if (A.empty())
        return -1;

    std::vector<int> myVector = A;
    std::sort(myVector.begin(), myVector.end());
    
    unsigned int occurrences = 0, maxOccurrences = 0;
    long int previousValue = myVector[0], maxOccurringValue = previousValue;
    
    for (size_t i = 0; i < myVector.size(); ++i)
    {
        if (previousValue == myVector[i])
            ++occurrences;
        else
        {
            occurrences = 1;
            previousValue = myVector[i];
        }

        if (occurrences > maxOccurrences)
        {
            maxOccurrences = occurrences;
            maxOccurringValue = previousValue;
        }
    }

    unsigned int lenL = 1, lenR = A.size()-1;
    unsigned int leaderOccurrencesL = 0, leaderOccurrencesR = maxOccurrences;
    unsigned int equiLeadersCount = 0;
    
    for (size_t i = 0; i < A.size(); ++i, ++lenL, --lenR)
    {
        if (A[i] == maxOccurringValue)
        {
            ++leaderOccurrencesL;
            --leaderOccurrencesR;
        }
        
        if (leaderOccurrencesL > (lenL/2) && leaderOccurrencesR > (lenR/2))
            ++equiLeadersCount;
    }

    return equiLeadersCount;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(NlogN)
////////// AVG ~ O(N)
