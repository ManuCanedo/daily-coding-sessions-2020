////////// SOLUTION

#include <vector>

int solution(int K, std::vector<int>& A)
{
	int len = 0, ropes = 0;

	for (int& a : A) {
		len += a;
		if (len >= K) {
			++ropes;
			len = 0;
		}
	}

	return ropes;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)