////////// SOLUTION PROGRESS
// Solved 03_08_2020 with time complexity O(N*logN)

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
