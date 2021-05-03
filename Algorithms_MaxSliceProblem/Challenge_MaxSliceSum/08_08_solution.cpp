////////// SOLUTION

#include <vector>

int solution(std::vector<int>& A)
{
	int maxSum = A[0], currentSum = 0;

	for (auto it = A.begin(); it != A.end(); ++it) {
		if (*it + currentSum < *it)
			currentSum = *it;
		else
			currentSum += *it;
		if (currentSum > maxSum)
			maxSum = currentSum;
	}
	return maxSum;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)
