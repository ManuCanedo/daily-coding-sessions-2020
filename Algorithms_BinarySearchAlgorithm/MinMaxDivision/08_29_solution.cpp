////////// SOLUTION 

#include <vector>

bool checkLargeSum(int mid, int K, const std::vector<int> &A);

int solution(int K, int M, std::vector<int> &A) 
{
    int maxElement = A[0], accum = 0;

    for (size_t i = 0; i < A.size(); ++i)
    {
        maxElement = maxElement < A[i] ? A[i] : maxElement;
        accum += A[i];
    }

    int beg = maxElement, end = accum, largeSum = accum;
        
    while (beg < end)
    {
        int mid = (beg + end) / 2;
        if (checkLargeSum(mid, K, A))
        {
            largeSum = mid;
            end = mid;
        }
        else
            beg = mid + 1;
    }    

    return largeSum;
}

inline bool checkLargeSum(int largeSumLimit, int K, const std::vector<int> &A)
{
    int accum = 0;
    for (size_t i = 0; i < A.size(); ++i)
    {
        accum += A[i];
        if (accum > largeSumLimit)
        {
            accum = A[i];
            if (!--K) 
                return false;
        }
    }

    return true;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(Nlog(N+M))
