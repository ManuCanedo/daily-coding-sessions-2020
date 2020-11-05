////////// SOLUTION 

#include <vector>

int solution(std::vector<int> &H) 
{
    std::vector<int> blocks;
    int numBlocks = 0;
    
    for (size_t i = 0; i < H.size(); ++i)
    {
        while (!blocks.empty() && H[i] < blocks.back()) 
            blocks.pop_back();
        if (!blocks.empty() && H[i] == blocks.back())
            continue;
        blocks.push_back(H[i]);
        ++numBlocks;
    }
    
    return numBlocks;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)
