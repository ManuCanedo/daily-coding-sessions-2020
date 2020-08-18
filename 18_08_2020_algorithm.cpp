////////// CHALLENGE DESCRIPTION

// Two positive integers N and M are given. Integer N represents the number of chocolates arranged in a circle, numbered from 0 to N − 1.

// You start to eat the chocolates. After eating a chocolate you leave only a wrapper.

// You begin with eating chocolate number 0. Then you omit the next M − 1 chocolates or wrappers on the circle, and eat the following one.

// More precisely, if you ate chocolate number X, then you will next eat the chocolate with number (X + M) modulo N (remainder of division).

// You stop eating when you encounter an empty wrapper.

// For example, given integers N = 10 and M = 4. You will eat the following chocolates: 0, 4, 8, 2, 6.

// The goal is to count the number of chocolates that you will eat, following the above rules.

// Write a function:

// int solution(int N, int M);

// that, given two positive integers N and M, returns the number of chocolates that you will eat.

// For example, given integers N = 10 and M = 4. the function should return 5, as explained above.

// Write an efficient algorithm for the following assumptions:

// N and M are integers within the range [1..1,000,000,000].


////////// SOLUTION
// Attempted with prime factorization (algorithm based in Sieve of Erathostenes). It works only with relatively small numbers.
// Current algorithm time complexity is O(N+M). Tomorrow will rework it to use Euclidean Algorithm.

#include <vector>
#include <algorithm>

int solution(int N, int M) 
{
    int sieveSize = (N>M) ? N : M;
    int sieveIndexN = N, sieveIndexM = M, MCD = 1;
    std::vector<int> sieve(sieveSize+1,0);
    std::vector<int> primeFactorsN, primeFactorsM, MCDFactors;

    for (int i = 2; i*i <= sieveSize; ++i)
        if (sieve[i] == 0)
            for (int k = i*i; k <= sieveSize; k += i)
                sieve[k] = i;

    for (size_t i = 2; i < sieve.size(); ++i)
        if (sieve[i] == 0)
            sieve[i] = i;
    
    while (sieve[sieveIndexN] > 0)
    {
        primeFactorsN.push_back(sieve[sieveIndexN]);
        sieveIndexN /= sieve[sieveIndexN];
    }
    while (sieve[sieveIndexM] > 0)
    {
        primeFactorsM.push_back(sieve[sieveIndexM]);
        sieveIndexM /= sieve[sieveIndexM];
    }
    std::sort(primeFactorsN.begin(), primeFactorsN.end());
    std::sort(primeFactorsM.begin(), primeFactorsM.end());

    for (size_t i = 0, j = 0; i < primeFactorsN.size() && j < primeFactorsM.size(); ++i)
    {
        while (primeFactorsM[j] < primeFactorsN[i])
            ++j;
        if (primeFactorsM[j] == primeFactorsN[i])
            MCDFactors.push_back(primeFactorsM[j++]);
    }
    
    for (int pF : MCDFactors)
        MCD *= pF;
    return N/MCD;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N+M)
////////// AVG ~ 0(N+M)
