#include <vector>
#include <set>

int solution(vector<int> &A) 
{
    std::set<int> uniqueAbs;
    
    for (int a : A)
        uniqueAbs.insert(abs(a));
        
    return uniqueAbs.size();
}