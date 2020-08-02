////////// CHALLENGE DESCRIPTION

// A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P < Q < N, is called a slice of array A (notice that the slice contains at least two elements). The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).

// For example, array A such that:

//     A[0] = 4
//     A[1] = 2
//     A[2] = 2
//     A[3] = 5
//     A[4] = 1
//     A[5] = 5
//     A[6] = 8

// contains the following example slices:

// slice (1, 2), whose average is (2 + 2) / 2 = 2;
// slice (3, 4), whose average is (5 + 1) / 2 = 3;
// slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.
// The goal is to find the starting position of a slice whose average is minimal.

// Write a function:

// int solution(vector<int> &A);

// that, given a non-empty array A consisting of N integers, returns the starting position of the slice with the minimal average. If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.

// For example, given array A such that:

//     A[0] = 4
//     A[1] = 2
//     A[2] = 2
//     A[3] = 5
//     A[4] = 1
//     A[5] = 5
//     A[6] = 8

// the function should return 1, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [2..100,000];
// each element of array A is an integer within the range [−10,000..10,000].


////////// SOLUTION PROGRESS
// FIRST VERSION

// #include <vector>
// #include <map>

// int solution(std::vector<int> &A) {
//     std::vector<unsigned int> lowAvgOfTwo;

//     float lowestAvg = A[0];
//     unsigned int lowestAvgIndex = 0;
//     int previousInt = A[0];
    
//     for (unsigned int i = 1; i < A.size()-1; ++i)
//     {
//         if ((previousInt + A[i])/2 < lowestAvg)
//         {
//                 lowestAvg = (previousInt + A[i])/2;
//                 lowestAvgIndex = i-1;   
//         }
//         previousInt = A[i];
//     }

//     for (unsigned int i = 1; i < A.size()-1; ++i)
//     {
//         if ((previousInt + A[i])/2 == lowestAvg)
//         {
//             lowAvgOfTwo.push_back(i-1);  
//         }
//         previousInt = A[i];
//     }

//     for (unsigned int i = 1; i < lowAvgOfTwo.size(); ++i)
//     {
//         if ((A[lowAvgOfTwo[i]-1] + A[lowAvgOfTwo[i]] + A[lowAvgOfTwo[i]]) / 3 < lowestAvg)
//         {
//             lowestAvgIndex -= 1;
//             lowestAvg = (A[lowAvgOfTwo[i]-1] + A[lowAvgOfTwo[i]] + A[lowAvgOfTwo[i]]) / 3;
//         }
//     }
    
//     return lowestAvgIndex;
// }

////////// SOLUTION PROGRESS
// /////////////////// SECOND VERSION

// #include <vector>

// int solution(std::vector<int> &A) {
    
//     std::map<float,unsigned int> slices;
//     float currentAvg;
//     int currentSum;
//     unsigned int currentIndex, currentLength;
//     unsigned int lowestAvgIndex;

    
    
//     for (unsigned int i = 0; i < A.size(); )
//     {
//         currentIndex = i, currentLength = 2;
//         currentSum = A[i] + A[i+1];
//         currentAvg = currentSum / currentLength;
//         bool bSearchR = true, bSearchL = true;
        
//         while (bSearchR || bSearchL)
//         {
//             if ((currentSum + A[currentLength]) / (currentLength+1) < currentAvg)
//             {
//                 currentAvg = (currentSum + A[currentLength]) / (currentLength+1);
//                 currentLength++;
//             }
//             if (currentIndex > 0 && (currentSum + A[currentLength]) / (currentLength+1) < currentAvg)
//             {
                
//             }
//         }
//     }
    
//     return lowestAvgIndex;
// }
