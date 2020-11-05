#include <vector>

int solution(std::vector<int> &A, std::vector<int> &B) 
{
    std::vector<int> fishUp, fishDown;
    
    for (size_t i = 0; i < B.size(); i++)
    {
        switch (B[i])
        {
            case 0:
                while (!fishDown.empty() && fishDown.back() < A[i])
                    fishDown.pop_back();   
                if (fishDown.empty())
                    fishUp.push_back(A[i]);
                break;
            case 1:
                fishDown.push_back(A[i]);
                break;
            default:
                break;
        }
    }
    
    return fishUp.size() + fishDown.size();
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)
