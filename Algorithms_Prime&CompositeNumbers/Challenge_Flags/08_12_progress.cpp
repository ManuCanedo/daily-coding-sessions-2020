////////// SOLUTION PROGRESS
// Solved 13_08_2020 with time complexity O(N)

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


////////// SOLUTION PROGRESS

// #include <vector>

// int solution(std::vector<int> &A) 
// {
//     std::vector<unsigned int> peaks;

//     if (A.size < 3)
//         return 0;
    
//     for (auto it = (A.begin()+1); it != (A.end()-1); ++it)
//     {
//         if (*(it-1) < *it && *it > *(it+1))
//         {
//             peaks.push_back(it-A.begin());
//         }
//     }
    
//     int maxFlags = 1;
//     int currentFlags = 0, previousPeakIndex = 0;
    
//     for (size_t i = 2; i <= peaks.size(); ++i)
//     {
//         currentFlags = i;
//         for (size_t j = 0; j < peaks.size(); ++j)
//         {
//             if (j == 0 || (peaks[j]-previousPeakIndex) > i)
//             {
//                 previousPeakIndex = peaks[j];
//                 --currentFlags;
//                 if (currentFlags == 0)
//                 {
//                     maxFlags = i;
//                     break;
//                 }
//             }
//         }
//     }
    
//     return maxFlags;
// }


////////// SOLUTION PROGRESS

// #include <vector>

// int solution(std::vector<int> &A) 
// {
//     std::vector<int> peaks;
//     unsigned int countPeaks = 0, previousPeakIndex = 0; 
//     int distance = 0, minDistance = (int)A.size();
    
//     if (A.size() < 3)
//         return 0;
    
//     for (auto it = (A.begin()+1); it != (A.end()-1); ++it)
//     {
//         if (*(it-1) < *it && *it > *(it+1))
//         {
//             ++countPeaks;
//             peaks.push_back(it-A.begin());
//             if (previousPeakIndex != 0)
//             {
//                 distance = abs(previousPeakIndex-(it-A.begin()));
//                 if (distance < minDistance)
//                     minDistance = distance;
//             }
//             previousPeakIndex = it-A.begin();
//         }
//     }
    
//     int maxFlags = (peaks.back()-peaks.front())/minDistance;
//     int flags = maxFlags;
//     int lastFlag = 0;
    
//     // std::cout << "Range: " << (peaks.back()-peaks.front()) << endl;
//     // std::cout << "maxFlags: " << maxFlags << endl;
    
//     for (size_t i = 0; i < peaks.size(); ++i)
//     {
//         if (i == 0)
//         {
//             --flags;
//             lastFlag = peaks[0];
//             // std::cout << "0 Last flag: " << lastFlag << endl;
//         }
//         else if (peaks[i]-lastFlag >= maxFlags)
//         {
//             --flags;
//             lastFlag = peaks[i];
//             // std::cout << "Last flag: " << lastFlag << endl;
//         }
//         if (flags == 0)
//         {
//             ++maxFlags;
//             break;
//         }
//     }
//     return maxFlags-1;
// }
