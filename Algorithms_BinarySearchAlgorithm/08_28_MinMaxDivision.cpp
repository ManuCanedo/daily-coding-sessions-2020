////////// CHALLENGE DESCRIPTION

// You are given integers K, M and a non-empty array A consisting of N integers. Every element of the array is not greater than M.

// You should divide this array into K blocks of consecutive elements. The size of the block is any integer between 0 and N. Every element of the array should belong to some block.

// The sum of the block from X to Y equals A[X] + A[X + 1] + ... + A[Y]. The sum of empty block equals 0.

// The large sum is the maximal sum of any block.

// For example, you are given integers K = 3, M = 5 and array A such that:

//   A[0] = 2
//   A[1] = 1
//   A[2] = 5
//   A[3] = 1
//   A[4] = 2
//   A[5] = 2
//   A[6] = 2

// The array can be divided, for example, into the following blocks:

// [2, 1, 5, 1, 2, 2, 2], [], [] with a large sum of 15;
// [2], [1, 5, 1, 2], [2, 2] with a large sum of 9;
// [2, 1, 5], [], [1, 2, 2, 2] with a large sum of 8;
// [2, 1], [5, 1], [2, 2, 2] with a large sum of 6.

// The goal is to minimize the large sum. In the above example, 6 is the minimal large sum.

// Write a function:

// int solution(int K, int M, vector<int> &A);

// that, given integers K, M and a non-empty array A consisting of N integers, returns the minimal large sum.

// For example, given K = 3, M = 5 and array A such that:

//   A[0] = 2
//   A[1] = 1
//   A[2] = 5
//   A[3] = 1
//   A[4] = 2
//   A[5] = 2
//   A[6] = 2

// the function should return 6, as explained above.

// Write an efficient algorithm for the following assumptions:

// N and K are integers within the range [1..100,000];
// M is an integer within the range [0..10,000];
// each element of array A is an integer within the range [0..M].


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