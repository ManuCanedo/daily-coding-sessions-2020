// CONTINUATION 25_07

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

// #include <vector>
// #include <iostream>
// #include <algorithm> 

// float calcIndexAvg(std::vector<int> &A, int index, float &minAvg, int &minAvgIndex);

// int solution(std::vector<int> &A)
// {
//     int minAvgIndex = 0;
//     float minAvg = (float) (A[0]+A[1]) / 2;
//     float minIndexAvg = minAvg;
    
//     for (unsigned int i = 0; i < A.size()-1; i++)
//     {
//         // cout << "Iters for" << endl;
//         minIndexAvg = calcIndexAvg(A, (int)i, minAvg, minAvgIndex);
        
//         while (A[i+1] > minIndexAvg)
//         {
//             i++;
//         }
//     }
//     return minAvgIndex;
// }

// inline float calcIndexAvg(std::vector<int> &A, int index, float &minAvg, int &minAvgIndex)
// {
//     static int Asize = (int)A.size();
//     static int minValue = *std::min_element(A.begin(),A.end());
    
//     float currentSum = A[index] + A[index+1];
//     int sumLength = 2; 
//     float currentAvg = currentSum / sumLength;
//     float minIndexAvg = currentAvg;
//     float minTheoreticalSum = (minValue)*(Asize - index - sumLength);
//     float minTheoreticalAvg = (currentSum + minTheoreticalSum) / Asize;
    
//     if (currentAvg < minAvg)
//     {
//         // cout << "Updates Min" << endl;
//         minAvg = currentAvg;
//         minAvgIndex = index;
//     }
    
//     while (minTheoreticalAvg < minAvg && (Asize - index - sumLength) >= 0)
//     {
//         // cout << "Enters While" << endl;
//         // std::cout.precision(2);
//         // std::cout << "Current MinAvg is " << minAvg << endl;
//         currentSum += A[index+sumLength];
//         sumLength++;
//         currentAvg = currentSum / sumLength;
//         minTheoreticalSum = (minValue*(Asize - index - sumLength));
//         minTheoreticalAvg = (currentSum + minTheoreticalSum) / Asize;
        
//         if (currentAvg < minIndexAvg)
//             minIndexAvg = currentAvg;
        
//         if (currentAvg < minAvg)
//         {
//             // cout << "Updates Min" << endl;
//             minAvg = currentAvg;
//             minAvgIndex = index;
//         }
//     }
    
//     return minIndexAvg;
// }

// This code is still buggy, I will revert to the correct version and try to optimize from there.

#include <vector>
#include <iostream>

void calcIndexAvg(std::vector<int> &A, int index, float &minAvg, int &minAvgIndex);

int solution(std::vector<int> &A)
{
    int minAvgIndex = 0;
    float minAvg = (float) (A[0]+A[1]) / 2;
    for (unsigned int i = 0; i < A.size()-1; i++)
    {
        // cout << "Iters for" << endl;
        calcIndexAvg(A, (int)i, minAvg, minAvgIndex);
    }
    return minAvgIndex;
}

inline void calcIndexAvg(std::vector<int> &A, int index, float &minAvg, int &minAvgIndex)
{
    static int Asize = (int)A.size();
    
    float currentSum = A[index] + A[index+1];
    int sumLength = 2;
    float currentAvg = currentSum / sumLength;
    float minTheoreticalSum = (-10000)*(Asize - index - sumLength);
    float minTheoreticalAvg = (currentSum + minTheoreticalSum) / Asize;
    
    if (currentAvg < minAvg)
    {
        // cout << "Updates Min" << endl;
        minAvg = currentAvg;
        minAvgIndex = index;
    }
    
    while (minTheoreticalAvg < minAvg && (Asize - index - sumLength) >= 0)
    {
        // cout << "Enters While" << endl;
        // std::cout.precision(2);
        // std::cout << "Current MinAvg is " << minAvg << endl;
        currentSum += A[index+sumLength];
        sumLength++;
        currentAvg = currentSum / sumLength;
        minTheoreticalSum = (-10000*(Asize - index - sumLength));
        minTheoreticalAvg = (currentSum + minTheoreticalSum) / Asize;
        
        if (currentAvg < minAvg)
        {
            // cout << "Updates Min" << endl;
            minAvg = currentAvg;
            minAvgIndex = index;
        }
    }
}
