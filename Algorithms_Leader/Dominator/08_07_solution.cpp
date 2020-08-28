////////// SOLUTION 

#include <algorithm>
#include <vector>

int solution(std::vector<int> &A) 
{
    if (A.empty())
        return -1;
    
    const unsigned int half = (A.size()/2);
    std::vector<int> myVector = A;
    std::sort(myVector.begin(), myVector.end());
    
    unsigned int occurrences = 0;
    long int previousValue = myVector[0];
    
    for (size_t i = 0; i < myVector.size(); ++i)
    {
        if (previousValue == myVector[i])
            ++occurrences;
        else
        {
            occurrences = 1;
            previousValue = myVector[i];
        }
        if (occurrences > half)
        {
            auto it = std::find (A.begin(), A.end(), previousValue);
            return (it-A.begin());
        }
    }
    return -1; 
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(NlogN)
