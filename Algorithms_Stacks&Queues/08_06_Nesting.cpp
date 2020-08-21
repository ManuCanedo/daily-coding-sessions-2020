////////// CHALLENGE DESCRIPTION

// A string S consisting of N characters is called properly nested if:

// S is empty;
// S has the form "(U)" where U is a properly nested string;
// S has the form "VW" where V and W are properly nested strings.
// For example, string "(()(())())" is properly nested but string "())" isn't.

// Write a function:

// int solution(string &S);

// that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.

// For example, given S = "(()(())())", the function should return 1 and given S = "())", the function should return 0, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [0..1,000,000];
// string S consists only of the characters "(" and/or ")".


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
                else
                    return 0;
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
////////// AVG ~ O(N)
