////////// SOLUTION 

#include <vector>
#include <string>

int solution(std::string &S) 
{
    std::vector<int> nesting;
    
    for (auto it = S.begin(); it != S.end(); it++)
    {
        switch (*it)
        {
            case 91:
                nesting.push_back(*it);
                break;
            case 93:
                if (nesting.size() > 0 && nesting.back() == 91)
                    nesting.pop_back();
                else return 0;
                break;
            case 123:
                nesting.push_back(*it);
                break;
            case 125:
                if (nesting.size() > 0 && nesting.back() == 123)
                    nesting.pop_back();
                else return 0;
                break;
            case 40:
                nesting.push_back(*it);
                break;
            case 41:
                if (nesting.size() > 0 && nesting.back() == 40)
                    nesting.pop_back();
                else return 0;
                break;
            default:
                break;
        }
    }
    
    return (nesting.size() == 0) ? 1 : 0;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)
