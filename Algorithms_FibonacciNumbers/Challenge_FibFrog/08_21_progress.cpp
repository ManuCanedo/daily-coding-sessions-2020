////////// SOLUTION PROGRESS

// #include <vector>
// #include <iostream>

// std::vector<int> generateFibonacci(int length);

// int solution(std::vector<int> &A)
// {
//     int otherSide = A.end() - A.begin() + 1, frog = -1, countSteps = 0;
//     std::vector<int> fibonacci = generateFibonacci(otherSide);
//     std::vector<int> river(A.size(), 0);
//     bool bTrying = true;

//     for (int f : fibonacci)
//     {
//         std::cout << f << " ";
//     }

//     while (frog != otherSide && bTrying)
//     {
//         steps++;

//         for (size_t i = 0; i < fibonacci.size(); ++i)
//         {
//             if (fibonacci[i] + frog == otherSide)
//                 return steps;
//             if (A[fibonacci[i] + frog] == 1 && river[fibonacci[i] + frog] == 0)
//                 river[fibonacci[i] + frog] == steps;
//         }

//        // Continue here
//     }

//     return (bTrying) ? steps : -1;
// }

// inline std::vector<int> generateFibonacci(int length)
// {
//     std::vector<int> fibonacci;
//     int fibonacciTerm = 1;

//     fibonacci.push_back(0);
//     while (fibonacciTerm < length)
//     {
//         fibonacci.push_back(fibonacciTerm);
//         fibonacciTerm += *(fibonacci.end() - 2);
//     }
//     return fibonacci;
// }
