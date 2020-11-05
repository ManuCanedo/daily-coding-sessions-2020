////////// SOLUTION 

#include <vector>
#include <set>

int solution(int M, std::vector<int> &A) 
{
    int count = 0;
    std::set<int> caterpillar;
    
    for (size_t back = 0, front = 0; back < A.size(); ++back)
    {
        while (front < A.size() && caterpillar.insert(A[front]).second)
            ++front;
        caterpillar.erase(A[back]);
        
        count += front - back;
        if(count > 1000000000)
            return 1000000000;
    }
    
    return count;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)
