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
