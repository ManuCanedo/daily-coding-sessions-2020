////////// CHALLENGE DESCRIPTION

// You are given an array A consisting of N integers.

// For each number A[i] such that 0 ≤ i < N, we want to count the number of elements of the array that are not the divisors of A[i]. We say that these elements are non-divisors.

// For example, consider integer N = 5 and array A such that:

//     A[0] = 3
//     A[1] = 1
//     A[2] = 2
//     A[3] = 3
//     A[4] = 6

// For the following elements:

// A[0] = 3, the non-divisors are: 2, 6,
// A[1] = 1, the non-divisors are: 3, 2, 3, 6,
// A[2] = 2, the non-divisors are: 3, 3, 6,
// A[3] = 3, the non-divisors are: 2, 6,
// A[4] = 6, there aren't any non-divisors.

// Write a function:

// vector<int> solution(vector<int> &A);

// that, given an array A consisting of N integers, returns a sequence of integers representing the amount of non-divisors.

// Result array should be returned as a vector of integers.

// For example, given:

//     A[0] = 3
//     A[1] = 1
//     A[2] = 2
//     A[3] = 3
//     A[4] = 6

// the function should return [2, 4, 3, 2, 0], as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..50,000];
// each element of array A is an integer within the range [1..2 * N].


////////// SOLUTION

#include <vector>

std::vector<int> solution(std::vector<int> &A) 
{
    std::vector<int> factors(2*A.size()+1,0);
    std::vector<int> sieve(factors.size(),0);
    std::vector<int> result;
    unsigned long int k = 1, product = 0;
    
    for (int a : A)
    {
        ++factors[a];
    }
    
    for (size_t i = 0; i < sieve.size(); ++i)
    {
        if (factors[i] == 0)
            continue;
        k = 1;
        product = k*i;
        while (product < sieve.size())
        {
            sieve[product] += factors[i];
            ++k;
            product = k*i;
        }
    }
    
    for (int a : A)
    {
        result.push_back(A.size()-sieve[a]);
    }
    return result;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(NlogN)
////////// AVG ~ 0(NlogN)