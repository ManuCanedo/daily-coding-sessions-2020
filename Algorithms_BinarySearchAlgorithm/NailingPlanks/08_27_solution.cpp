////////// SOLUTION

#include <vector>
#include <algorithm>

bool enoughNails(const std::vector<int> &A, const std::vector<int> &B, const std::vector<int> &nails);

int solution(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C) 
{
    int maxValBoards = *std::max_element(B.begin(), B.end());
    int maxValNails = *std::max_element(C.begin(), C.end());
    int maxVal = std::max(maxValBoards,maxValNails), result = -1;
    std::vector<int>::iterator beg = C.begin(), end = C.end(), mid;
    
    while (beg != end)
    {
        mid = beg + (end-beg)/2;
        std::vector<int> nails(maxVal+1,0);
        for (std::vector<int>::iterator it = C.begin(); it != mid+1; ++it)
            nails[*it] = 1;
            
        if (!enoughNails(A, B, nails))
            beg = mid + 1;
        else
        {
            end = mid;
            result = mid-C.begin()+1;
        }
    }
    
    return result;
}

inline bool enoughNails(const std::vector<int> &A, const std::vector<int> &B, const std::vector<int> &nails)
{
    bool bAllBoardsNailed = true;
    
    for (unsigned int i = 0; i < A.size() && bAllBoardsNailed; ++i)
    {
        for (int j = A[i]; j <= B[i]; ++j)
        {
            bAllBoardsNailed = false;
            if (nails[j])
            {
                bAllBoardsNailed = true;
                break;
            }
        }
    }

    return bAllBoardsNailed;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O((N+M)log(M))
