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
