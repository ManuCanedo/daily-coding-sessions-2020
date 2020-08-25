////////// CHALLENGE DESCRIPTION

// A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:

// S is empty;
// S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
// S has the form "VW" where V and W are properly nested strings.

// For example, the string "{[()()]}" is properly nested but "([)()]" is not.

// Write a function:

// class Solution { public int solution(String S); }

// that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

// For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [0..200,000];
// string S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")".


////////// SOLUTION 

#include <vector>
#include <string>

int solution(std::string &S) {
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
                {
                    nesting.pop_back();
                }
                else 
                {
                    return 0;
                }
                break;
            case 123:
                nesting.push_back(*it);
                break;
            case 125:
                if (nesting.size() > 0 && nesting.back() == 123)
                {
                    nesting.pop_back();
                }
                else 
                {
                    return 0;
                }
                break;
            case 40:
                nesting.push_back(*it);
                break;
            case 41:
                if (nesting.size() > 0 && nesting.back() == 40)
                {
                    nesting.pop_back();
                }
                else 
                {
                    return 0;
                }
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
////////// AVG ~ O(N)


// Draft code to reduce 27_07 time complexity.

// #include <vector>
// #include <iostream>

// int solution(std::vector<int> &A)
// {
//     std::vector<float> accumulatedSum(A.size()+1,0);
//     int previousValue = 0;
//     for (size_t i = 0; i <= accumulatedSum.size(); i++)
//     {
//         accumulatedSum[i] = previousValue;
//         previousValue += A[i];
//     }
    
//     int initIndex = 0, endIndex = 1, minAvgIndex = 0;
//     float currentAvg = (A[initIndex]+A[endIndex])/2;
//     float minAvg = currentAvg;

//     while (endIndex < (int)accumulatedSum.size()-1)
//     {
//         if ((endIndex-initIndex+1) > 2 && (accumulatedSum[endIndex]-accumulatedSum[initIndex+1])/(endIndex-initIndex) < currentAvg)
//         {
//             currentAvg = (accumulatedSum[endIndex]-accumulatedSum[initIndex+1])/(endIndex-initIndex);
//             initIndex++;
//             if(currentAvg < minAvg)
//             {
//                 minAvg = currentAvg;
//                 minAvgIndex = initIndex;
//             }
//             continue;
//         }
//         else if ((accumulatedSum[endIndex+1]-accumulatedSum[initIndex])/(endIndex-initIndex+2) < currentAvg)
//         {
//             currentAvg = (accumulatedSum[endIndex+1]-accumulatedSum[initIndex])/(endIndex-initIndex+2);
//             endIndex++;
//             if(currentAvg < minAvg)
//             {
//                 minAvg = currentAvg;
//                 minAvgIndex = initIndex;
//             }
//             continue;
//         }
//             initIndex = endIndex++;
//     }
//     return minAvgIndex;
// }
