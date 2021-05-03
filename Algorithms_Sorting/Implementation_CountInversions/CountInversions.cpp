#include <vector>
#include <iostream>

inline std::pair<std::vector<int>, int> MergeCount(const std::vector<int>& a,
						   const std::vector<int>& b)
{
	std::vector<int> solution(a.size() + b.size());
	int aIndex{ 0 }, bIndex{ 0 }, invCount{ 0 };

	for (auto& element : solution) {
		if (aIndex == a.size()) {
			element = b[bIndex++];
			continue;
		}
		if (bIndex == b.size()) {
			element = a[aIndex++];
			continue;
		}
		if (b[bIndex] < a[aIndex]) {
			element = b[bIndex++];
			invCount += a.size() - aIndex;
		} else
			element = a[aIndex++];
	}

	return { solution, invCount };
}

std::pair<std::vector<int>, int> CountInversions(const std::vector<int>& arr)
{
	if (arr.size() == 1)
		return { arr, 0 };

	std::vector<int> a(arr.begin(), arr.begin() + arr.size() / 2);
	std::vector<int> b(arr.begin() + arr.size() / 2, arr.end());

	std::pair<std::vector<int>, int> countInvA = CountInversions(a),
					 countInvB = CountInversions(b);
	std::pair<std::vector<int>, int> countInvMerged =
		MergeCount(countInvA.first, countInvB.first);

	return { countInvMerged.first,
		 countInvA.second + countInvB.second + countInvMerged.second };
}

int main()
{
	std::vector<int> arrayInts{ 10, 5, 2, 6, 3, 9, 8, 3, 4, 1, 7, 10 };

	std::cout << "The unsorted int array is the following: " << std::endl;
	for (auto& element : arrayInts)
		std::cout << element << " ";

	std::cout << std::endl;
	std::pair<std::vector<int>, int> countInvInts = CountInversions(arrayInts);
	std::cout << "\nThe sorted int array is the following: " << std::endl;
	for (auto& element : countInvInts.first)
		std::cout << element << " ";

	std::cout << "\nThe number of total inversions is " << countInvInts.second << std::endl;

	return 0;
}

// Uses at most 6n * log2n + 6n operations
// Time Complexity: O(n*logn)
// Space Complexity could be improved.