////////// SOLUTION
// I re-did the algortithm from past days in order to reduce time complexity.
    
#include <vector>
#include <algorithm>

int solution(std::vector<int> &A) 
{
    std::vector<long int> discOpen, discClose;
    int intersections = 0, openDiscs = 0;
    
    for (size_t i = 0; i < A.size(); ++i)
    {
        discOpen.push_back(i-A[i]);
        discClose.push_back(i+A[i]);
    }
    
    std::sort(discOpen.begin(), discOpen.end());
    std::sort(discClose.begin(), discClose.end());
    
    for (size_t i = 0, j = 0; i < discOpen.size(); i++)
    {
        if (discOpen[i] <= discClose[j])
        {
            intersections += openDiscs++;
            if (intersections > 10000000)
                return -1;
        }
        else if (discOpen[i] > discClose[j])
        {
            openDiscs--;
            j++;
            i--;
        }
    }
    
    return intersections;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(NlogN)
