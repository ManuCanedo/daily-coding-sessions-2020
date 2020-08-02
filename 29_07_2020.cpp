////////// CHALLENGE DESCRIPTION

// An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:

// A[P] + A[Q] > A[R],
// A[Q] + A[R] > A[P],
// A[R] + A[P] > A[Q].
// For example, consider array A such that:

//   A[0] = 10    A[1] = 2    A[2] = 5
//   A[3] = 1     A[4] = 8    A[5] = 20
// Triplet (0, 2, 4) is triangular.

// Write a function:

// class Solution { public int solution(int[] A); }

// that, given an array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.

// For example, given array A such that:

//   A[0] = 10    A[1] = 2    A[2] = 5
//   A[3] = 1     A[4] = 8    A[5] = 20
// the function should return 1, as explained above. Given array A such that:

//   A[0] = 10    A[1] = 50    A[2] = 5
//   A[3] = 1
// the function should return 0.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [0..100,000];
// each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].


////////// SOLUTION PROGRESS
// Initial code with Time Complexity O(N**3).

// #include <vector>

// bool isTriangle(int Pvalue, int Qvalue, int Rvalue);

// int solution(std::vector<int> &A) 
// {
//     int Pvalue = 0, Qvalue = 0, Rvalue = 0; 
//     unsigned int N = A.size();
    
//     if (A.size() < 3)
//         return 0;

//     for (unsigned int i = 0; i < N-2; i++)
//     {
//         Pvalue = A[i];
//         for (unsigned int j = i+1; j < N-1; j++)
//         {
//             Qvalue = A[j];
//             for (unsigned int k = j+1; k < N; k++)
//             {
//                     Rvalue = A[k];
//                     if (isTriangle(Pvalue,Qvalue,Rvalue))
//                         return 1;
//                     while (A[k]>=A[k+1] && k < N)
//                     {
//                         k++;
//                     }
//             }
//             while (A[j]>=A[j+1] && j < N-1)
//             {
//                 j++;
//             }
//         }
//         while (A[i]>=A[i+1] && i < N-2)
//         {
//             i++;
//         }
//     }
//     return 0;
// }

// inline bool isTriangle(int Pvalue, int Qvalue, int Rvalue)
// {
//     if ((Pvalue + Qvalue) <= Rvalue)
//         return false;
//     if ((Qvalue + Rvalue) <= Pvalue)
//         return false;
//     if ((Rvalue + Pvalue) <= Qvalue)
//         return false;
//     return true;
// }
