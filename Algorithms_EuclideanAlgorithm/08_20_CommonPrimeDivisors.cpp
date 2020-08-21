////////// CHALLENGE DESCRIPTION

// A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.

// A prime D is called a prime divisor of a positive integer P if there exists a positive integer K such that D * K = P. For example, 2 and 5 are prime divisors of 20.

// You are given two positive integers N and M. The goal is to check whether the sets of prime divisors of integers N and M are exactly the same.

// For example, given:

// N = 15 and M = 75, the prime divisors are the same: {3, 5};
// N = 10 and M = 30, the prime divisors aren't the same: {2, 5} is not equal to {2, 3, 5};
// N = 9 and M = 5, the prime divisors aren't the same: {3} is not equal to {5}.

// Write a function:

// int solution(vector<int> &A, vector<int> &B);

// that, given two non-empty arrays A and B of Z integers, returns the number of positions K for which the prime divisors of A[K] and B[K] are exactly the same.

// For example, given:

//     A[0] = 15   B[0] = 75
//     A[1] = 10   B[1] = 30
//     A[2] = 3    B[2] = 5

// the function should return 1, because only one pair (15, 75) has the same set of prime divisors.

// Write an efficient algorithm for the following assumptions:

// Z is an integer within the range [1..6,000];
// each element of arrays A, B is an integer within the range [1..2,147,483,647].


////////// SOLUTION

#include <vector>

int greatestCommonDivisor(int A, int B, int res);

int solution(std::vector<int> &A, std::vector<int> &B) 
{
    int gcd = 1, gcdA = 1, gcdB = 1, result = 0;

    for (size_t i = 0; i < A.size(); ++i)
    {
        gcd = greatestCommonDivisor(A[i], B[i], 1);
        while (A[i] != 1)
        {
            gcdA = greatestCommonDivisor(A[i], gcd, 1);
            if (gcdA == 1)
                break;
            A[i] /= gcdA;
        }
        if (A[i] != 1)
            continue;
        
        while (B[i] != 1)
        {
            gcdB = greatestCommonDivisor(B[i], gcd, 1);
            if (gcdB == 1)
                break;
            B[i] /= gcdB;
        }
        if (B[i] == 1)
            ++result;
    }
    return result;
}

inline int greatestCommonDivisor(int A, int B, int res)
{
    if (A == B) 
        return A*res;
    else if (A%2 == 0 && B%2 == 0)
        return greatestCommonDivisor(A/2, B/2, res*2);
    else if (A%2 == 0)
        return greatestCommonDivisor(A/2, B, res);
    else if (B%2 == 0)
        return greatestCommonDivisor(A, B/2, res);
    else if (A > B)
        return greatestCommonDivisor(A-B, B, res);
    else
        return greatestCommonDivisor(A, B-A, res);
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(Z*log(A+B)*log(A+B))


////////// SOLUTION PROGRESS
// This is just a version of the same algorithm calculating prime factors through Sieve, in order to compare behaviours.

#include <vector>
#include <set>

int solution(std::vector<int> &A, std::vector<int> &B) 
{
    int sieveSize = 0, sieveIndexN = 0, sieveIndexM = 0, result = 0;
    
    for (size_t i = 0; i < A.size(); ++i)
    {
        if (A[i] > sieveSize && A[i] > B[i])
            sieveSize = A[i];
        if (B[i] > sieveSize && B[i] > A[i])
            sieveSize = B[i];
    }
    
    std::vector<int> sieve(sieveSize+1,0);
    for (int i = 2; i*i <= sieveSize; ++i)
        if (sieve[i] == 0)
            for (int k = i*i; k <= sieveSize; k += i)
                sieve[k] = i;
                
    for (size_t i = 2; i < sieve.size(); ++i)
        if (sieve[i] == 0)
            sieve[i] = i;
    
    for (size_t i = 0; i < A.size(); ++i)
    {
        std::set<int> primeFactorsN, primeFactorsM;
        sieveIndexN = A[i];
        sieveIndexM = B[i];
        while (sieve[sieveIndexN] > 0)
        {
            primeFactorsN.insert(sieve[sieveIndexN]);
            sieveIndexN /= sieve[sieveIndexN];
        }
        while (sieve[sieveIndexM] > 0)
        {
            primeFactorsM.insert(sieve[sieveIndexM]);
            sieveIndexM /= sieve[sieveIndexM];
        }
        if (primeFactorsN == primeFactorsM)
            ++result;
    }
    
    return result;
}

////////// CORRECT BEHAVIOUR FOR SMALL ARRAYS (POOR SPACE COMPLEXITY)
////////// TIME COMPLEXITY:
////////// MAX ~ O(Z(A+B))
