////////// SOLUTION

#include <vector>

int solution(std::vector<int> &A) 
{
    int numberOnes = std::count(A.begin(), A.end(), 1), passingCars = 0;
    
    for (auto it = A.begin(); it != A.end(); it++)
    {
        if (*it == 0)
        {
            if (passingCars <= (1000000000 - numberOnes))
                passingCars += numberOnes;
            else 
                return -1;
        }
        else
            numberOnes--;
    }
    
    return passingCars;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ 0(N)
