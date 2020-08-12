////////// CHALLENGE DESCRIPTION

// A non-empty array A consisting of N integers is given.

// A peak is an array element which is larger than its neighbours. More precisely, it is an index P such that 0 < P < N − 1 and A[P − 1] < A[P] > A[P + 1].

// For example, the following array A:

//     A[0] = 1
//     A[1] = 5
//     A[2] = 3
//     A[3] = 4
//     A[4] = 3
//     A[5] = 4
//     A[6] = 1
//     A[7] = 2
//     A[8] = 3
//     A[9] = 4
//     A[10] = 6
//     A[11] = 2

// has exactly four peaks: elements 1, 3, 5 and 10.

// You are going on a trip to a range of mountains whose relative heights are represented by array A, as shown in a figure below. You have to choose how many flags you should take with you. The goal is to set the maximum number of flags on the peaks, according to certain rules.

// Flags can only be set on peaks. What's more, if you take K flags, then the distance between any two flags should be greater than or equal to K. The distance between indices P and Q is the absolute value |P − Q|.

// For example, given the mountain range represented by array A, above, with N = 12, if you take:

// two flags, you can set them on peaks 1 and 5;
// three flags, you can set them on peaks 1, 5 and 10;
// four flags, you can set only three flags, on peaks 1, 5 and 10.
// You can therefore set a maximum of three flags in this case.

// Write a function:

// int solution(vector<int> &A);

// that, given a non-empty array A of N integers, returns the maximum number of flags that can be set on the peaks of the array.

// For example, the following array A:

//     A[0] = 1
//     A[1] = 5
//     A[2] = 3
//     A[3] = 4
//     A[4] = 3
//     A[5] = 4
//     A[6] = 1
//     A[7] = 2
//     A[8] = 3
//     A[9] = 4
//     A[10] = 6
//     A[11] = 2

// the function should return 3, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..400,000];
// each element of array A is an integer within the range [0..1,000,000,000].


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