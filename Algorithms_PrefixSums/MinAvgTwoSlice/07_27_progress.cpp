////////// SOLUTION PROGRESS

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


////////// SOLUTION PROGRESS
// This code is still buggy, I will revert to the correct version and try to optimize from there.

// #include <vector>
// #include <iostream>

// void calcIndexAvg(std::vector<int> &A, int index, float &minAvg, int &minAvgIndex);

// int solution(std::vector<int> &A)
// {
//     int minAvgIndex = 0;
//     float minAvg = (float) (A[0]+A[1]) / 2;
//     for (unsigned int i = 0; i < A.size()-1; i++)
//     {
//         // cout << "Iters for" << endl;
//         calcIndexAvg(A, (int)i, minAvg, minAvgIndex);
//     }
//     return minAvgIndex;
// }

// inline void calcIndexAvg(std::vector<int> &A, int index, float &minAvg, int &minAvgIndex)
// {
//     static int Asize = (int)A.size();
    
//     float currentSum = A[index] + A[index+1];
//     int sumLength = 2;
//     float currentAvg = currentSum / sumLength;
//     float minTheoreticalSum = (-10000)*(Asize - index - sumLength);
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
//         minTheoreticalSum = (-10000*(Asize - index - sumLength));
//         minTheoreticalAvg = (currentSum + minTheoreticalSum) / Asize;
        
//         if (currentAvg < minAvg)
//         {
//             // cout << "Updates Min" << endl;
//             minAvg = currentAvg;
//             minAvgIndex = index;
//         }
//     }
// }
