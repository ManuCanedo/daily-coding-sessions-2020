////////// SOLUTION PROGRESS

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
                   // Continue...
//             }
//         }
//     }
    
//     return lowestAvgIndex;
// }
