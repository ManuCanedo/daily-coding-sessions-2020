////////// SOLUTION PROGRESS

// #include <vector>

// std::vector<int> getNextAvgVectorR (std::vector<int>& A, std::vector<int>& avgVector, int newAvgLength);

// float lowestAvg;
// unsigned int lowestAvgIndex;

// int solution(std::vector<int> &A) {
//     std::vector<int> lowAvgOfTwo;

//     lowestAvg = A[0];
//     lowestAvgIndex = 0;
//     int previousInt = A[0];
    
//     for (unsigned int i = 1; i < A.size()-1; ++i)
//     {
//         if ((previousInt + A[i])/2 < 2*lowestAvg)
//         {
//             lowAvgOfTwo.push_back(i-1);
            
//             if ((previousInt + A[i])/2 < lowestAvg)
//             {
//                 lowestAvg = (previousInt + A[i])/2;
//                 lowestAvgIndex = i-1;    
//             }
//         }
//         previousInt = A[i];
//     }
    
//     std::vector<int> nextLowAvg = lowAvgOfTwo;
//     for (unsigned int i = 3; i < A.size(); ++i)
//     {
//         nextLowAvg = getNextAvgVectorR (A, nextLowAvg, i);
//         if (nextLowAvg.empty())
//         {
//             break;
//         }
//     }
    
//     return lowestAvgIndex;
// }

// inline std::vector<int> getNextAvgVectorR (std::vector<int>& A, std::vector<int>& avgVector, int newAvgLength)
// {
//     std::vector<int> nextAvgVector;
//     float elementSum = 0;
    
//     for (unsigned int i = 0; i < avgVector.size(); i++)
//     {
//         for (int j = 0; j < newAvgLength; ++j)
//         {
//            elementSum += A[avgVector[i] + j]; 
//         }
//         if (elementSum / newAvgLength < 2*lowestAvg)
//         {
//             nextAvgVector.push_back(avgVector[i]);
//             if (elementSum / newAvgLength < lowestAvg)
//             {
//                 lowestAvg = elementSum / newAvgLength;
//                 lowestAvgIndex = avgVector[i];    
//             }
//         }
//     }

//     return nextAvgVector;
// }
