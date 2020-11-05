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
        {
            for (int k = 2, product = k*i; product <= N; ++k)
            {
                if (sieve[k] == 0)
                    semiPrimes[product] = 1;
                product = (k+1)*i;
            }
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
