////////// SOLUTION 

#include <vector>
#include <algorithm>
#include <math.h>

std::vector<unsigned long long> generateFibonacci(int length);

std::vector<int> solution(std::vector<int> &A, std::vector<int> &B) 
{
    std::vector<int> solution(A.size());
    int fibLim = *std::max_element(std::begin(A), std::end(A)) + 2;
    std::vector<unsigned long long> fib = generateFibonacci(fibLim);
    
    for (size_t i = 0; i < A.size(); ++i)
        solution[i] = fib[A[i]+1] % (int)(pow(2, B[i]));
    
    return solution;
}   

inline std::vector<unsigned long long> generateFibonacci(int length)
{
    std::vector<unsigned long long> fib;
    fib.push_back(0);
    fib.push_back(1);

    for (int i = 2; i < length; ++i)
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
       
    return fib;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(L)
