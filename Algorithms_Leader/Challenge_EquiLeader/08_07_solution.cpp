////////// SOLUTION

#include <algorithm>
#include <vector>

int solution(std::vector<int>& A)
{
	if (A.empty())
		return -1;

	std::vector<int> myVector = A;
	std::sort(myVector.begin(), myVector.end());

	unsigned int occurrences = 0, maxOccurrences = 0;
	long int previousValue = myVector[0], maxOccurringValue = previousValue;

	for (size_t i = 0; i < myVector.size(); ++i) {
		if (previousValue == myVector[i])
			++occurrences;
		else {
			occurrences = 1;
			previousValue = myVector[i];
		}
		if (occurrences > maxOccurrences) {
			maxOccurrences = occurrences;
			maxOccurringValue = previousValue;
		}
	}

	unsigned int lenL = 1, lenR = A.size() - 1, equiLeadersCount = 0;
	unsigned int leaderOccurrencesL = 0, leaderOccurrencesR = maxOccurrences;

	for (size_t i = 0; i < A.size(); ++i, ++lenL, --lenR) {
		if (A[i] == maxOccurringValue) {
			++leaderOccurrencesL;
			--leaderOccurrencesR;
		}
		if (leaderOccurrencesL > (lenL / 2) && leaderOccurrencesR > (lenR / 2))
			++equiLeadersCount;
	}

	return equiLeadersCount;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(NlogN)
