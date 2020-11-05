////////// SOLUTION
// Behaviour ir correct but time complexity N^2 is not acceptable. I will re-do this tomorrow using factors calculation properties.

#include <algorithm>
#include <vector>

std::vector<int> solution(std::vector<int> &A) 
{
    std::vector<int> nonDivisors;
    int nonDivCount = 0;
    
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        nonDivCount = 0;
        for (long int i = 1; i*i <= *it && (*it)%i == 0; i++)
        {
            if (i*i != *it)
                nonDivCount += std::count(A.begin(), A.end(), (*it)/i);
            nonDivCount += std::count(A.begin(), A.end(), i);
        }
        nonDivisors.push_back(A.size()-nonDivCount);
    }
    return nonDivisors;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N*N)
