////////// SOLUTION 

#include <vector>
#include <algorithm>

int solution(std::vector<int> &A)
{
    std::sort(A.begin(), A.end());
    size_t lastElement = A.size()-1;

    if (A[lastElement] < 0)
        return A[lastElement-2]*A[lastElement-1]*A[lastElement];

    int productMinNumbers = A[0]*A[1], productSecondMaxNumbers = A[lastElement-1]*A[lastElement-2];
    
    return (productMinNumbers > productSecondMaxNumbers) ? productMinNumbers*A[lastElement] : productSecondMaxNumbers*A[lastElement];
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(NlogN)
