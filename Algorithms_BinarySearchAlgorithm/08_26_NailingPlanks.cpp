////////// CHALLENGE DESCRIPTION

// You are given two non-empty arrays A and B consisting of N integers. These arrays represent N planks. More precisely, A[K] is the start and B[K] the end of the K−th plank.

// Next, you are given a non-empty array C consisting of M integers. This array represents M nails. More precisely, C[I] is the position where you can hammer in the I−th nail.

// We say that a plank (A[K], B[K]) is nailed if there exists a nail C[I] such that A[K] ≤ C[I] ≤ B[K].

// The goal is to find the minimum number of nails that must be used until all the planks are nailed. In other words, you should find a value J such that all planks will be nailed after using only the first J nails. More precisely, for every plank (A[K], B[K]) such that 0 ≤ K < N, there should exist a nail C[I] such that I < J and A[K] ≤ C[I] ≤ B[K].

// For example, given arrays A, B such that:

//     A[0] = 1    B[0] = 4
//     A[1] = 4    B[1] = 5
//     A[2] = 5    B[2] = 9
//     A[3] = 8    B[3] = 10

// four planks are represented: [1, 4], [4, 5], [5, 9] and [8, 10].

// Given array C such that:

//     C[0] = 4
//     C[1] = 6
//     C[2] = 7
//     C[3] = 10
//     C[4] = 2

// if we use the following nails:

// 0, then planks [1, 4] and [4, 5] will both be nailed.
// 0, 1, then planks [1, 4], [4, 5] and [5, 9] will be nailed.
// 0, 1, 2, then planks [1, 4], [4, 5] and [5, 9] will be nailed.
// 0, 1, 2, 3, then all the planks will be nailed.

// Thus, four is the minimum number of nails that, used sequentially, allow all the planks to be nailed.

// Write a function:

// int solution(vector<int> &A, vector<int> &B, vector<int> &C);

// that, given two non-empty arrays A and B consisting of N integers and a non-empty array C consisting of M integers, returns the minimum number of nails that, used sequentially, allow all the planks to be nailed.

// If it is not possible to nail all the planks, the function should return −1.

// For example, given arrays A, B, C such that:

//     A[0] = 1    B[0] = 4
//     A[1] = 4    B[1] = 5
//     A[2] = 5    B[2] = 9
//     A[3] = 8    B[3] = 10

//     C[0] = 4
//     C[1] = 6
//     C[2] = 7
//     C[3] = 10
//     C[4] = 2

// the function should return 4, as explained above.

// Write an efficient algorithm for the following assumptions:

// N and M are integers within the range [1..30,000];
// each element of arrays A, B, C is an integer within the range [1..2*M];
// A[K] ≤ B[K].


////////// SOLUTION PROGRESS

// #include <vector>
// #include <map>

// bool enoughNails(std::multimap<int,int> boards, const std::vector<int> &C, unsigned int endSearch);

// int solution(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C) 
// {
//     std::multimap<int, int> boards;
//     for (size_t i = 0; i < A.size(); ++i)
//         boards.insert(std::pair<int,int>(A[i],B[i]));

//     std::vector<int>::iterator beg = C.begin(), end = C.end(), mid;
//     int result = -1;

//     while (beg != end)
//     {
//         mid = beg + (end-beg)/2;
//         if (!enoughNails(boards, C, mid-C.begin()))
//         {
//             beg = mid + 1;
//         else
//         {
//             end = mid;
//             result = mid-C.begin()+1;
//         }
//     }
    
//     return result;
// }

// inline bool enoughNails(std::multimap<int,int> boards, const std::vector<int> &C, unsigned int endSearch)
// {
//     for (unsigned int j = 0; j <= endSearch; ++j)
//     {
//         std::vector<std::multimap<int,int>::iterator> nailedBoards;
        
//         for (std::multimap<int,int>::iterator it = boards.begin(); it != boards.end(); ++it)
//             if (it->first <= C[j] && C[j] <= it->second)
//                 nailedBoards.push_back(it);

//         for (std::multimap<int,int>::iterator it : nailedBoards)
//             boards.erase(it);
//     }

//     return (boards.size() == 0) ? true : false;
// }


////////// SOLUTION PROGRESS

// #include <vector>
// #include <iostream>

// bool enoughNails(const std::vector<int> &A, const std::vector<int> &B, const std::vector<int> &C, unsigned int endSearch);

// int solution(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C) 
// {
//     std::vector<int>::iterator beg = C.begin(), end = C.end(), mid;
//     int result = -1;

//     while (beg != end)
//     {
//         mid = beg + (end-beg)/2;
//         if (!enoughNails(A, B, C, mid-C.begin()))
//         {
//             beg = mid + 1;
//         }
//         else
//         {
//             end = mid;
//             result = mid-C.begin()+1;
//         }
//     }
    
//     return result;
// }

// inline bool enoughNails(const std::vector<int> &A, const std::vector<int> &B, const std::vector<int> &C, unsigned int endSearch)
// {
//     size_t indexIt = 0;
//     bool bAllBoardsNailed = false;
    
//     for (unsigned int j = 0; j <= endSearch && !bAllBoardsNailed; ++j)
//     {
//         for (size_t i = indexIt; i < A.size(); ++i)
//         {
//             if (A[i] > C[j] || B[i] < C[j])
//             {
//                 indexIt = i;
//                 break;
//             }
//             if (i == A.size()-1)
//                 bAllBoardsNailed = true;
//         }
//     }
    
//     return bAllBoardsNailed;
// }
