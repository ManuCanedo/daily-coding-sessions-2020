////////// SOLUTION 

#include <vector>

int solution(std::vector<int> &A) 
{
    if (A.size() <= 3)
        return 0;
    
    int maxSum = 0, currentSum = 0, minValue = A[1];
        
    for (auto it = A.begin()+2; it != A.end()-1; ++it)
    {
        if (*it+currentSum <= *it)
        {
            currentSum = 0;
            minValue = *it;
            continue;
        }
        
        if (*it < minValue)
        {
            currentSum += minValue;
            minValue = *it;  
        }
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
