////////// SOLUTION

#include <algorithm>
#include <vector>

int solution(vector<int> &A) {
    if (A.size() == 0)
        return 0;
        
    std::sort(A.begin(),A.end());
    auto it = std::unique(A.begin(), A.end());
    A.resize(std::distance(A.begin(), it));
    
    return A.size();
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N*logN)
