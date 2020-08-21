////////// CHALLENGE DESCRIPTION

// A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. The sum of a slice (P, Q) is the total of A[P] + A[P+1] + ... + A[Q].

// Write a function:

// int solution(vector<int> &A);

// that, given an array A consisting of N integers, returns the maximum sum of any slice of A.

// For example, given array A such that:

// A[0] = 3  A[1] = 2  A[2] = -6
// A[3] = 4  A[4] = 0
// the function should return 5 because:

// (3, 4) is a slice of A that has sum 4,
// (2, 2) is a slice of A that has sum −6,
// (0, 1) is a slice of A that has sum 5,
// no other slice of A has sum greater than (0, 1).
// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..1,000,000];
// each element of array A is an integer within the range [−1,000,000..1,000,000];
// the result will be an integer within the range [−2,147,483,648..2,147,483,647].


////////// SOLUTION 

#include <vector>

int solution(std::vector<int> &A) 
{
    int maxSum = A[0], currentSum = 0;
    
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        if (*it+currentSum < *it)
            currentSum = *it;
        else 
            currentSum += *it;
            
        if (currentSum > maxSum)
            maxSum = currentSum;
    }
    return maxSum;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)
////////// AVG ~ O(N)


////////// CHALLENGE DESCRIPTION

// An array A consisting of N integers is given. It contains daily prices of a stock share for a period of N consecutive days. If a single share was bought on day P and sold on day Q, where 0 ≤ P ≤ Q < N, then the profit of such transaction is equal to A[Q] − A[P], provided that A[Q] ≥ A[P]. Otherwise, the transaction brings loss of A[P] − A[Q].

// For example, consider the following array A consisting of six elements such that:

//   A[0] = 23171
//   A[1] = 21011
//   A[2] = 21123
//   A[3] = 21366
//   A[4] = 21013
//   A[5] = 21367
// If a share was bought on day 0 and sold on day 2, a loss of 2048 would occur because A[2] − A[0] = 21123 − 23171 = −2048. If a share was bought on day 4 and sold on day 5, a profit of 354 would occur because A[5] − A[4] = 21367 − 21013 = 354. Maximum possible profit was 356. It would occur if a share was bought on day 1 and sold on day 5.

// Write a function,

// int solution(vector<int> &A);

// that, given an array A consisting of N integers containing daily prices of a stock share for a period of N consecutive days, returns the maximum possible profit from one transaction during this period. The function should return 0 if it was impossible to gain any profit.

// For example, given array A consisting of six elements such that:

//   A[0] = 23171
//   A[1] = 21011
//   A[2] = 21123
//   A[3] = 21366
//   A[4] = 21013
//   A[5] = 21367
// the function should return 356, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [0..400,000];
// each element of array A is an integer within the range [0..200,000].


////////// SOLUTION 

#include <vector>

int solution(std::vector<int> &A) 
{   
    int bestBalanceTodate = 0, maxProfit = 0;

    if (A.empty() || A.size() == 1)
        return 0;
    
    for (size_t i = 1; i < A.size(); ++i)
    {
        if (bestBalanceTodate + A[i] - A[i-1] > 0)
        {
            bestBalanceTodate += A[i] - A[i-1];
            if (bestBalanceTodate > maxProfit)
                maxProfit = bestBalanceTodate;
        }
        else
            bestBalanceTodate = 0;
    }
    return maxProfit;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)
////////// AVG ~ O(N)
