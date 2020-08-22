////////// CHALLENGE DESCRIPTION

// The Fibonacci sequence is defined using the following recursive formula:

//     F(0) = 0
//     F(1) = 1
//     F(M) = F(M - 1) + F(M - 2) if M >= 2
// A small frog wants to get to the other side of a river. The frog is initially located at one bank of the river (position −1) and wants to get to the other bank (position N). The frog can jump over any distance F(K), where F(K) is the K-th Fibonacci number. Luckily, there are many leaves on the river, and the frog can jump between the leaves, but only in the direction of the bank at position N.

// The leaves on the river are represented in an array A consisting of N integers. Consecutive elements of array A represent consecutive positions from 0 to N − 1 on the river. Array A contains only 0s and/or 1s:

// 0 represents a position without a leaf;
// 1 represents a position containing a leaf.
// The goal is to count the minimum number of jumps in which the frog can get to the other side of the river (from position −1 to position N). The frog can jump between positions −1 and N (the banks of the river) and every position containing a leaf.

// For example, consider array A such that:

//     A[0] = 0
//     A[1] = 0
//     A[2] = 0
//     A[3] = 1
//     A[4] = 1
//     A[5] = 0
//     A[6] = 1
//     A[7] = 0
//     A[8] = 0
//     A[9] = 0
//     A[10] = 0

// The frog can make three jumps of length F(5) = 5, F(3) = 2 and F(5) = 5.

// Write a function:

// int solution(vector<int> &A);

// that, given an array A consisting of N integers, returns the minimum number of jumps by which the frog can get to the other side of the river. If the frog cannot reach the other side of the river, the function should return −1.

// For example, given:

//     A[0] = 0
//     A[1] = 0
//     A[2] = 0
//     A[3] = 1
//     A[4] = 1
//     A[5] = 0
//     A[6] = 1
//     A[7] = 0
//     A[8] = 0
//     A[9] = 0
//     A[10] = 0

// the function should return 3, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [0..100,000];
// each element of array A is an integer that can have one of the following values: 0, 1.

////////// SOLUTION

#include <set>
#include <vector>

std::vector<int> generateFibonacci(int length);

int solution(std::vector<int> &A)
{
    int N = A.size();
    std::vector<int> fibonacci = generateFibonacci(N + 1);

    std::set<int> positions;
    positions.insert(N);

    for (int steps = 1;; ++steps)
    {
        std::set<int> indexes;
        for (int p : positions)
        {
            for (int f : fibonacci)
            {
                int index = p - f;
                if (index == -1)
                    return steps;
                if (index < 0)
                    break;
                if (A[index])
                    indexes.insert(index);
            }
        }
        if (indexes.size() == 0)
            return -1;
        positions = indexes;
    }
    return -1;
}

inline std::vector<int> generateFibonacci(int length)
{
    std::vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);

    while (fib[fib.size() - 1] <= length + 1)
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);

    return fib;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(NlogN)