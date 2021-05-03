////////// SOLUTION PROGRESS

// #include <vector>
// #include <algorithm>

// int solution(int K, int M, std::vector<int> &A)
// {
//     int sumFirstBlock = 0, sumSecondBlock = 0, sumThirdBlock = 0, partialLargeSum = 0, largeSum = 0;
//     std::vector<int>::iterator beg = A.begin(), end = A.end(), mid;

//     for (size_t i = 1; i < A.size(); ++i)
//         A[i] += A[i-1];

//     largeSum = A[A.size()-1];

//     for (unsigned int i = 0; i <= A.size(); ++i)
//     {
//         if (i) sumFirstBlock = A[i-1];

//         beg = A.begin()+i;
//         end = A.end();

//         while (beg != end)
//         {
//             mid = beg + (end-beg)/2;
//             sumSecondBlock = *(mid-1)-sumFirstBlock;
//             sumThirdBlock = *(A.end()-1)-sumSecondBlock-sumFirstBlock;

//             partialLargeSum = std::max({sumFirstBlock,sumSecondBlock,sumThirdBlock});
//             if (partialLargeSum < largeSum)
//                 largeSum = partialLargeSum;

//             if (sumSecondBlock < sumThirdBlock)
//                 beg = mid + 1;
//             else if (sumSecondBlock > sumThirdBlock)
//                 end = mid;
//             else
//                 break;
//         }
//     }

//     return largeSum;
// }
