////////// SOLUTION 

#include <vector>
#include <string>

int solution(std::string &S) 
{
    std::vector<int> nesting;
    
    for (size_t i = 0; i < S.size(); ++i)
    {
        switch (S[i])
        {
            case 40:
                nesting.push_back(S[i]);
                break;
            case 41:
                if (!nesting.empty())
                    nesting.pop_back();
                else return 0;
                break;
            default:
                break;
        }
    }
    
    return (nesting.empty()) ? 1 : 0;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)
