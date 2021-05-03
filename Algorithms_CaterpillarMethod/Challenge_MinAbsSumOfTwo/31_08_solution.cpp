////////// SOLUTION

#include <vector>
#include <set>
#include <algorithm>

int solution(std::vector<int>& A)
{
	std::set<int> negatives;
	std::vector<int>::iterator it = A.begin();
	int minSum = 2000000000;

	std::sort(A.begin(), A.end());

	if (*A.begin() >= 0)
		return abs(*A.begin() * 2);
	if (*(A.end() - 1) <= 0)
		return abs(*(A.end() - 1) * 2);

	while (*it <= 0) {
		if (*it == 0)
			return 0;
		minSum = (abs(*it * 2) < minSum) ? abs(*it * 2) : minSum;
		negatives.insert(abs(*it++));
	}

	while (it != A.end()) {
		minSum = (abs(*it * 2) < minSum) ? abs(*it * 2) : minSum;
		std::pair<std::set<int>::iterator, bool> ret = negatives.insert(*it);
		std::set<int>::iterator prev, next, mid;

		if (ret.second) {
			mid = ret.first;
			prev = --mid;
			mid = ret.first;
			next = ++mid;

			if (ret.first != negatives.begin() && ret.first != --(negatives.end())) {
				minSum = (abs(*(ret.first) - *prev) < minSum) ?
						       abs(*(ret.first) - *prev) :
						       minSum;
				minSum = (abs(*(ret.first) - *next) < minSum) ?
						       abs(*(ret.first) - *next) :
						       minSum;
			} else if (ret.first == negatives.begin())
				minSum = (abs(*(ret.first) - *next) < minSum) ?
						       abs(*(ret.first) - *next) :
						       minSum;
			else if (ret.first == --(negatives.end()))
				minSum = (abs(*(ret.first) - *prev) < minSum) ?
						       abs(*(ret.first) - *prev) :
						       minSum;

			negatives.erase(ret.first);
		} else
			return 0;

		++it;
	}

	return minSum;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(NlogN)
