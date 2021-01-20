#include <vector>
#include <iostream>

template<typename T>
inline std::pair<std::vector<T>, int> MergeCount(const std::vector<T>& a, const std::vector<T>& b)
{
    std::vector<T> solution(a.size() + b.size());
    int aIndex {0}, bIndex {0}, invCount{0};

    for (auto& element : solution)
    {
        if (aIndex == a.size())
        {
            element = b[bIndex++];
            continue;
        }
        if (bIndex == b.size())
        {
            element = a[aIndex++];
            continue;
        }
        if (b[bIndex] < a[aIndex])
        {
            element = b[bIndex++];
            invCount += solution.size() - aIndex;
        }
        else
            a[aIndex++];
    }

    return { solution, invCount };
}

template<typename T>
int CountInversions(std::vector<T>& arr)
{
    if (arr.size() == 1) return 0;

    std::vector<T> a(arr.begin(), arr.begin()+arr.size()/2);
    std::vector<T> b(arr.begin()+arr.size()/2, arr.end());

    const int invCountA = CountInversions(a);
    const int invCountB = CountInversions(b);
    auto merge = MergeCount(a, b);

    arr = merge.first;
    return invCountA + invCountB + merge.second;
}   

int main()
{
    std::cout << "Hello world!";
    std::vector<int> arrayInts {10, 5, 2, 6, 3, 9, 8, 3, 4, 1, 7, 10};
    std::cout << "The number of total inversions is " << CountInversions(arrayInts) << std::endl;

    for (auto& element : arrayInts)
        std::cout << element << " ";
    std::cout << std::endl;
    
    std::vector<char> arrayChars {'a', 'd', 'z', 'f', 'p'};
    std::cout << "The number of total inversions is " << CountInversions(arrayChars) << std::endl;

    for (auto& element : arrayChars)
        std::cout << element << " ";

    return 0;
}

// Uses at most 6n * log2n + 6n operations
// Time Complexity: O(n*logn)
// Space Complexity could be improved.