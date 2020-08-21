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
