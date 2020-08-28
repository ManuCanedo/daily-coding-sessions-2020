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
