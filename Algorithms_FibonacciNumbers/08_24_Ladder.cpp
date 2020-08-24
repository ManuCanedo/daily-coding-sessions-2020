////////// CHALLENGE DESCRIPTION

// You have to climb up a ladder. The ladder has exactly N rungs, numbered from 1 to N. With each step, you can ascend by one or two rungs. More precisely:

// with your first step you can stand on rung 1 or 2,
// if you are on rung K, you can move to rungs K + 1 or K + 2,
// finally you have to stand on rung N.
// Your task is to count the number of different ways of climbing to the top of the ladder.

// For example, given N = 4, you have five different ways of climbing, ascending by:

// 1, 1, 1 and 1 rung,
// 1, 1 and 2 rungs,
// 1, 2 and 1 rung,
// 2, 1 and 1 rungs, and
// 2 and 2 rungs.
// Given N = 5, you have eight different ways of climbing, ascending by:

// 1, 1, 1, 1 and 1 rung,
// 1, 1, 1 and 2 rungs,
// 1, 1, 2 and 1 rung,
// 1, 2, 1 and 1 rung,
// 1, 2 and 2 rungs,
// 2, 1, 1 and 1 rungs,
// 2, 1 and 2 rungs, and
// 2, 2 and 1 rung.

// The number of different ways can be very large, so it is sufficient to return the result modulo 2P, for a given integer P.

// Write a function:

// vector<int> solution(vector<int> &A, vector<int> &B);

// that, given two non-empty arrays A and B of L integers, returns an array consisting of L integers specifying the consecutive answers; position I should contain the number of different ways of climbing the ladder with A[I] rungs modulo 2B[I].

// For example, given L = 5 and:

//     A[0] = 4   B[0] = 3
//     A[1] = 4   B[1] = 2
//     A[2] = 5   B[2] = 4
//     A[3] = 5   B[3] = 3
//     A[4] = 1   B[4] = 1
// the function should return the sequence [5, 1, 8, 0, 1], as explained above.

// Write an efficient algorithm for the following assumptions:

// L is an integer within the range [1..50,000];
// each element of array A is an integer within the range [1..L];
// each element of array B is an integer within the range [1..30].


////////// SOLUTION 

#include <vector>
#include <algorithm>
#include <math.h>

std::vector<unsigned long long> generateFibonacci(int length);

std::vector<int> solution(std::vector<int> &A, std::vector<int> &B) 
{
    std::vector<int> solution(A.size());
    int fibLim = *std::max_element(std::begin(A), std::end(A)) + 2;
    std::vector<unsigned long long> fib = generateFibonacci(fibLim);
    
    for (size_t i = 0; i < A.size(); ++i)
        solution[i] = fib[A[i]+1] % (int)(pow(2, B[i]));
    
    return solution;
}   

inline std::vector<unsigned long long> generateFibonacci(int length)
{
    std::vector<unsigned long long> fib;
    fib.push_back(0);
    fib.push_back(1);

    for (int i = 2; i < length; ++i)
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
       
    return fib;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(L)