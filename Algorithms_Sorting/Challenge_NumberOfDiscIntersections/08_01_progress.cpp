////////// SOLUTION PROGRESS
// Solved 02_08_2020 with time complexity O(N*logN)

// #include <vector>
// #include <algorithm>

// int solution(vector<int> &A) {
//     std::vector<int> discOpen, discClose, numDiscs;
//     int intersections = 0, openDiscs = 0, closedDiscs = 0;
    
//     for (size_t i = 0; i < A.size(); ++i)
//     {
//         discOpen.push_back(i-A[i]);
//         discClose.push_back(i+A[i]);
//     }
//     std::sort(discOpen.begin(), discOpen.end());
//     std::sort(discClose.begin(), discClose.end());
//     // ////
//     // for (int s : discClose)
//     // {
//     //     std::cout << s << " ";
//     // }
//     // std::cout << endl << endl;
//     // ////
    
//     int rangeStart = 0, rangeEnd = 0, minValue = discOpen[0];
//     for (size_t i = 0; i < discOpen.size()-1; ++i)
//     {
//         openDiscs++;
//         rangeStart = discOpen[i];
//         rangeEnd = discOpen[i+1];
//         for (int j = rangeStart; j < rangeEnd; j++)
//         {
//             numDiscs.push_back(openDiscs);
//         }
//     }
//     // ////
//     // for (int s : numDiscs)
//     // {
//     //     std::cout << s << " ";
//     // }
//     // std::cout << endl;
//     // ////
    
//     for (size_t i = 0; i < discClose.size()-1; ++i)
//     {
//         closedDiscs++;
//         rangeStart = discClose[i];
//         rangeEnd = discClose[i+1];
//         if (rangeStart == rangeEnd)
//         {
//             closedDiscs++;
//             numDiscs[rangeStart-minValue]-=closedDiscs;
//         }
//         for (int j = rangeStart; j < rangeEnd; ++j)
//         {
//             if (j < *(std::end(numDiscs)-1))
//                 numDiscs[j-minValue]-=closedDiscs;
//         }
//     }
//     // ////
//     // for (int s : numDiscs)
//     // {
//     //     std::cout << s << " ";
//     // }
//     // std::cout << endl;
//     // ////
    
//     openDiscs = numDiscs[0];
//     for (size_t i = 1; i < numDiscs.size(); ++i)
//     {
//         if (numDiscs[i] > openDiscs)
//         {
//             for (int k = 0; k < numDiscs[i]-openDiscs; ++k)
//             {
//                 intersections += openDiscs;
//                 openDiscs++;
//             }
//             if (intersections > 10000000)
//                     return -1;
//             openDiscs = numDiscs[i];
//         }
//         else if (numDiscs[i] < openDiscs)
//         {
//             openDiscs = numDiscs[i];
//         }
//     }
//     return intersections;
// }


////////// OTHER CONTRIBUTIONS
///////////////////////////////////////////////////////////////////////////////// In addition I created this algorithm to help a friend in a challenge of his own. 
// I don't have the written specifications for it.

// #include <vector>
// #include <iostream>

// inline void check(std::vector<char>& mySequence, std::vector<char>& myFragment, const int &i, int& myCounter, int &indexStart, bool &bErrorUsed, bool &bChecking)
// {
//     if (mySequence[i] == myFragment[i - indexStart])
//     {
//         if ((myFragment.begin() + i - indexStart + 1) == myFragment.end())
//         {
//             myCounter++;
//             indexStart = -1;
//             bChecking = bErrorUsed = false;
//         }
//     }
//     else if (!bErrorUsed)
//     {
//         if ((myFragment.begin() + i - indexStart + 1) == myFragment.end())
//         {
//             myCounter++;
//             indexStart = -1;
//             bChecking = bErrorUsed = false;
//         }
//         else
//         {
//             bErrorUsed = true;
//         }
//     }
// }

// inline int function(std::vector<char> &mySequence, std::vector<char> &myFragment)
// {
//     int myCounter = 0, indexStart = -1, indexStartSecond = 0;
//     bool bChecking = false, bErrorUsed = false;
//     std::vector<int> possibles;

//     for (size_t i = 0; i < mySequence.size(); ++i)
//     {
//         if (bChecking)
//         {
//             check(mySequence, myFragment, i, myCounter, indexStart, bErrorUsed, bChecking);

//             if (mySequence[i] == myFragment[0])
//             {
//                 possibles.push_back(i);
//             }
//             else if (i > 0 && mySequence[i] == myFragment[1])
//             {
//                 possibles.push_back(i-1);
//             }
//         }
//         else if (!bChecking)
//         {
//             if (mySequence[i] == myFragment[0])
//             {
//                 bChecking = true;
//                 indexStart = i;
//             }
//             else if (i > 0 && mySequence[i] == myFragment[1])
//             {
//                 bChecking = bErrorUsed = true;
//                 indexStart = i - 1;
//             }
//         }
//     }

//     // Second iteration here to operate with the other possible sequence matches starting points, in case that the specifications require it.

//     return myCounter;
// }

// int main()
// {
//     std::vector<char> mySequence = {'a', 'd', 'D', 'F', 'a', 'd', 'a', 'd', 'F', 'a', 'F'};
//     std::vector<char> myFragment = {'a', 'd'};
//     int result = function(mySequence, myFragment);

//     std::cout << result << std::endl;
//     std::cin >> result;
//     return 0;
// }
