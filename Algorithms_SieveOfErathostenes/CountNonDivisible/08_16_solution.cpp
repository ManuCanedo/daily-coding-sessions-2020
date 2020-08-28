////////// SOLUTION

#include <vector>

std::vector<int> solution(std::vector<int> &A) 
{
    std::vector<int> factors(2*A.size()+1,0);
    std::vector<int> sieve(factors.size(),0);
    std::vector<int> result;
    unsigned long int k = 1, product = 0;
    
    for (int a : A)
        ++factors[a];
    
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
        result.push_back(A.size()-sieve[a]);
    
    return result;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(NlogN)
