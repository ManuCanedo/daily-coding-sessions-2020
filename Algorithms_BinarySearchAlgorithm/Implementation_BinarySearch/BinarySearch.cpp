#include <vector>
#include <iostream>

std::vector<int>::iterator BinarySearch(std::vector<int>& arr, const int num)
{
    std::vector<int>::iterator beg = arr.begin(), end = arr.end(), mid;

    while (beg != end)
    {
        mid = beg + (end-beg)/2;
        if (*mid == num) return mid;
        (*mid < num) ? beg = mid + 1 : end = mid;
    }
    return arr.end();
}

int main()
{
    std::vector<int> array {10, 5, 2, 6, 3, 9, 8, 3, 4, 1, 7, 10};
    const int numToFind {5};

    if (auto it = BinarySearch(array, numToFind); it != array.end())
        std::cout << numToFind << " has been found at position " << it - array.begin() << std::endl;
    else
        std::cout << numToFind << " is not part of the array." << std::endl;

    return 0;
}

// Time Complexity: O(logn)