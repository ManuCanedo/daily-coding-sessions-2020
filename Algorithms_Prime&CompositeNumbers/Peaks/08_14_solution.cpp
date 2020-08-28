////////// SOLUTION

#include <vector>
#include <algorithm>

int solution(std::vector<int> &A)
{
    std::vector<int> peaks, blocks;
    int elements = A.end() - A.begin(), lowLimit = 0, topLimit = 0, maxBlocks = 1;

    if (A.size() < 3)
        return 0;

    for (auto it = (A.begin() + 1); it != (A.end() - 1); ++it)
        if (*(it - 1) < *it && *it > *(it + 1))
            peaks.push_back(it - A.begin());

    if (peaks.empty())
        return 0;

    for (long int i = 1; i * i <= elements; i++)
        if (elements % i == 0)
            blocks.push_back(i);
    
    for (int i = blocks.size() - 1; i >= 0; --i)
        blocks.push_back(elements / blocks[i]);

    std::reverse(blocks.begin(), blocks.end());
    for (auto it = blocks.begin(); it != blocks.end(); ++it)
    {
        lowLimit = 0;
        topLimit = *it;
        for (int p : peaks)
        {
            if (lowLimit <= p && p < topLimit)
            {
                lowLimit += *it;
                topLimit += *it;
            }
            if (lowLimit == elements)
                maxBlocks = elements / (*it);
        }
    }

    return maxBlocks;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(Nlog(logN))
