////////// CHALLENGE DESCRIPTION




////////// SOLUTION PROGRESS

// #include <vector>

// int solution(std::vector<int> &A) 
// {
//     std::vector<unsigned int> distances(A.size(), 0);
//     unsigned int peakCount = 0;
//     unsigned int previousPeakIndex = 0, distance = 0;
    
//     for (auto it = (A.begin()+1); it != (A.end()-1); ++it)
//     {
//         if (*(it-1) < *it && *it > *(it+1))
//         {
//             ++peakCount;
//             if (previousPeakIndex != 0)
//             {
//                 distance = abs(previousPeakIndex-(it-A.begin()));
//                 ++distances[distance];
//             }
//             previousPeakIndex = it-A.begin();
//         }
//     }
    
//     int maxFlags = 0, currentFlags = 0;
    
//     for (size_t i = 1; i < distances.size(); ++i)
//     {
//         distances[i] += distances[i-1];
//     }
//     for (size_t i = 1; i < distances.size(); ++i)
//     {
//         if (i <= peakCount-distances[i-2])
//             currentFlags = i;
//         else
//             currentFlags = peakCount-distances[i-2];
//         if (currentFlags > maxFlags)
//             maxFlags = currentFlags;
//     }
    
//     return maxFlags;
// }


////////// SOLUTION

#include <vector>

int solution(std::vector<int> &A) 
{
    std::vector<unsigned int> peaks;

    if (A.size < 3)
        return 0;
    
    for (auto it = (A.begin()+1); it != (A.end()-1); ++it)
    {
        if (*(it-1) < *it && *it > *(it+1))
        {
            peaks.push_back(it-A.begin());
        }
    }
    
    int maxFlags = 1;
    int currentFlags = 0, previousPeakIndex = 0;
    
    for (size_t i = 2; i <= peaks.size(); ++i)
    {
        currentFlags = i;
        for (size_t j = 0; j < peaks.size(); ++j)
        {
            if (j == 0 || (peaks[j]-previousPeakIndex) > i)
            {
                previousPeakIndex = peaks[j];
                --currentFlags;
                if (currentFlags == 0)
                {
                    maxFlags = i;
                    break;
                }
            }
        }
    }
    
    return maxFlags;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N^1/2)
////////// AVG ~ 0(N^1/2)