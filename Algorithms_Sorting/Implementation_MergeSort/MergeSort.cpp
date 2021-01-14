#include <vector>
#include <iostream>

template<typename T>
inline std::vector<T> Merge(const std::vector<T>& a, const std::vector<T>& b)
{
    std::vector<T> solution(a.size() + b.size());
    int aIndex {0}, bIndex {0};

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
        element = (b[bIndex] < a[aIndex]) ? b[bIndex++] : a[aIndex++];
    }
    return solution;
}

template<typename T>
void MergeSort(std::vector<T>& arr)
{
    std::vector<T> a(arr.begin(), arr.begin()+arr.size()/2);
    std::vector<T> b(arr.begin()+arr.size()/2, arr.end());

    if (a.size() > 1) MergeSort(a);
    if (b.size() > 1) MergeSort(b);
    arr = Merge(a, b);
}   

int main()
{
    std::vector<int> arrayInts {10, 5, 2, 6, 3, 9, 8, 3, 4, 1, 7, 10};

    MergeSort(arrayInts);
    for (auto& element : arrayInts)
        std::cout << element << " ";
    std::cout << std::endl;

    std::vector<char> arrayChars {'a', 'd', 'z', 'f', 'p'};
    
    MergeSort(arrayChars);
    for (auto& element : arrayChars)
        std::cout << element << " ";

    return 0;
}

// Uses at most 6n * log2n + 6n operations
// Time Complexity: O(n*logn)
// Space Complexity could be improved.