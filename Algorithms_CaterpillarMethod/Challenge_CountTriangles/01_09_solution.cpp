////////// SOLUTION

#include <vector>
#include <algorithm>

int solution(std::vector<int>& A)
{
	std::sort(A.begin(), A.end());
	unsigned int triangles = 0;

	for (size_t x = 0; x < A.size(); ++x) {
		unsigned int y = x + 1, z = x + 2;
		while (z < A.size()) {
			if (A[x] + A[y] > A[z]) {
				triangles += z - y;
				++z;
			} else if (y < z - 1)
				++y;
			else {
				++z;
				++y;
			}
		}
	}

	return triangles;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N^2)