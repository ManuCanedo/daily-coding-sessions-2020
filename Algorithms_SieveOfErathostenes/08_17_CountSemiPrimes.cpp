////////// CHALLENGE DESCRIPTION

// A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.

// A semiprime is a natural number that is the product of two (not necessarily distinct) prime numbers. The first few semiprimes are 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.

// You are given two non-empty arrays P and Q, each consisting of M integers. These arrays represent queries about the number of semiprimes within specified ranges.

// Query K requires you to find the number of semiprimes within the range (P[K], Q[K]), where 1 ≤ P[K] ≤ Q[K] ≤ N.

// For example, consider an integer N = 26 and arrays P, Q such that:

//     P[0] = 1    Q[0] = 26
//     P[1] = 4    Q[1] = 10
//     P[2] = 16   Q[2] = 20

// The number of semiprimes within each of these ranges is as follows:

// (1, 26) is 10,
// (4, 10) is 4,
// (16, 20) is 0.
// Write a function:

// vector<int> solution(int N, vector<int> &P, vector<int> &Q);

// that, given an integer N and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M elements specifying the consecutive answers to all the queries.

// For example, given an integer N = 26 and arrays P, Q such that:

//     P[0] = 1    Q[0] = 26
//     P[1] = 4    Q[1] = 10
//     P[2] = 16   Q[2] = 20

// the function should return the values [10, 4, 0], as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..50,000];
// M is an integer within the range [1..30,000];
// each element of arrays P, Q is an integer within the range [1..N];
// P[i] ≤ Q[i].


////////// SOLUTION
// Learned my lesson from previous algorithm, this time I straight ahead calculated the Sieve of Erathostenes
// avoiding O(N*N) while calculating the prime numbers lesser than N.

#include <vector>

std::vector<int> solution(int N, std::vector<int> &P, std::vector<int> &Q) 
{
    std::vector<int> semiPrimes(N+1,0);
    std::vector<int> sieve = semiPrimes;
    std::vector<int> result;
    
    sieve[0] = sieve[1] = 1;
    
    for (int i = 2; i*i <= N; ++i)
        if (sieve[i] == 0)
            for (int k = i*i; k <= N; k += i)
                sieve[k] = 1;

    for (int i = 2; i <= N; ++i)
    {
        if (sieve[i] == 0)
            for (int k = 2, product = k*i; product <= N; ++k)
            {
                if (sieve[k] == 0)
                    semiPrimes[product] = 1;
                product = (k+1)*i;
            }
    }
    
    for (size_t i = 1; i < semiPrimes.size(); ++i)
        semiPrimes[i] += semiPrimes[i-1];
      
    for (size_t i = 0; i < P.size(); ++i)
        result.push_back(semiPrimes[Q[i]]-semiPrimes[P[i]-1]);
    
    return result;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(Nlog(log(N)))
////////// AVG ~ 0(Nlog(log(N)))
