////////// SOLUTION 

#include <vector>
#include <set>

int solution(std::vector<int> &A) 
{
    std::set<int> uniqueAbs;
    
    for (int &a : A)
        uniqueAbs.insert(abs(a));
        
    return uniqueAbs.size();
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)
