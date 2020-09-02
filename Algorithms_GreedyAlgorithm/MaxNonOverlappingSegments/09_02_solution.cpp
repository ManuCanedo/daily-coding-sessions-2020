////////// SOLUTION 

#include <vector>

int solution(std::vector<int> &A, std::vector<int> &B) 
{
    int segEnd = -1, segCount = 0;
    
    for (size_t i = 0; i < A.size(); ++i)
    {
        if (A[i] > segEnd)
        {
            segEnd = B[i];
            ++segCount;
        }
        if (B[i] < segEnd)
            segEnd = B[i];
    }
    
    return segCount;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)