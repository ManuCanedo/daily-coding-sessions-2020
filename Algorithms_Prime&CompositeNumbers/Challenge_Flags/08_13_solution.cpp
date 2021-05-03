////////// SOLUTION

#include <vector>

int solution(std::vector<int>& A)
{
	std::vector<int> peaks;
	int flags = 0, previousFlag = 0;

	if (A.size() < 3)
		return 0;

	for (auto it = (A.begin() + 1); it != (A.end() - 1); ++it)
		if (*(it - 1) < *it && *it > *(it + 1))
			peaks.push_back(it - A.begin());

	for (int i = 1; i <= peaks.size(); ++i) {
		flags = i;
		for (auto it = peaks.begin(); it != peaks.end(); ++it) {
			if (it == peaks.begin() || (*it - previousFlag) >= i) {
				--flags;
				previousFlag = *it;
			}
			if (flags == 0)
				break;
		}
		if (flags == 0)
			continue;
		return i - 1;
	}

	return peaks.size();
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)
