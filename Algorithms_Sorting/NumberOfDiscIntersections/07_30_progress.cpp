////////// SOLUTION PROGRESS
// Solved 02_08_2020 with time complexity O(N*logN)

// #include <vector>
// #include <numeric>
// #include <iostream>

// int solution(std::vector<int> &A) 
// {
//     if (A.empty() || A.size() == 1)
//         return 0;
        
//     int totalIntersections = 0, N = A.size() + A[A.size()-2] -1;
//     std::vector<int> hLimit(N,0);
//     unsigned int itIndex = 0;
    
//     for (unsigned int i = 0; i < A.size()-1; i++)
//     {   
//         if (A[i] != 0)
//             hLimit[i+A[i]]++; 
//     }
//     // for (auto it = hLimit.begin(); it != hLimit.end(); ++it)
//     // {
//     //     cout << *it << " ";
//     // }
    
//     // std::cout << std::endl;
            
//     for (int i = A.size()-1; i >= 0; i--)
//     {
//         if (i != (int)A.size()-1)
//             hLimit[i+A[i]]--;
        
//         itIndex = (i-A[i] > 0) ? (i-A[i]) : 0;
//         totalIntersections += (accumulate(hLimit.begin()+itIndex, hLimit.end(), 0));
        
//         if (totalIntersections > 10000000)
//             return -1;
//     }
//     // for (auto it = hLimit.begin(); it != hLimit.end(); ++it)
//     // {
//     //     cout << *it << " ";
//     // }
    
//     return totalIntersections;
// }

////////// SOLUTION PROGRESS
//// Discarded first approach because was calculatin unique intersections instead of combination with repetition

// #include <vector>
// #include <numeric>
// #include <iostream>

// int solution(std::vector<int> &A) 
// {
//     if (A.empty() || A.size() == 1)
//         return 0;
    
//     int lBound = 0, hBound = 0;
//     int totalIntersections = 0;
    
//     std::vector<std::vector<int>> myIntersections;
//     myIntersections.resize(A.size());
    
//     for (int i = 0; i < (int)A.size(); i++)
//     {
//         lBound = (i-A[i] > 0) ? i-A[i] : 0;
//         hBound = (i+A[i] < (int)A.size()) ? i+A[i] : (int)A.size();
//         for (int j = lBound; j < hBound; j++)
//         {
//             myIntersections[j].push_back(i);
//         }
//     }

//     // Tomorrow will complete this section.

//     if (totalIntersections > 10000000)
//         return -1;
//     return totalIntersections;
// }
