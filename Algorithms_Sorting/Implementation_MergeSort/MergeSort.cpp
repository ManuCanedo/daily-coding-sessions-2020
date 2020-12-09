#include <vector>
#include <iostream>

inline std::vector<int> Merge(const std::vector<int>& a, const std::vector<int>& b)
{
    std::vector<int> solution(a.size() + b.size());
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

void MergeSort(std::vector<int>& arr)
{
    std::vector<int> a(arr.begin(), arr.begin()+arr.size()/2);
    std::vector<int> b(arr.begin()+arr.size()/2, arr.end());

    if (a.size() > 1) MergeSort(a);
    if (b.size() > 1) MergeSort(b);
    arr = Merge(a, b);
}   

int main()
{
    std::vector<int> array {10, 5, 2, 6, 3, 9, 8, 3, 4, 1, 7, 10};
    MergeSort(array);

    for (auto& element : array)
        std::cout << element << " ";

    return 0;
}

// Uses at most 6n * log2n + 6n operations
// Time Complexity: O(n*logn)