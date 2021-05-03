////////// SOLUTION

#include <vector>

void calcIndexAvg(std::vector<int>& A, int index, float& minAvg, int& minAvgIndex);

int solution(std::vector<int>& A)
{
	int minAvgIndex = 0;
	float minAvg = (float)(A[0] + A[1]) / 2;

	for (unsigned int i = 0; i < A.size() - 1; i++)
		calcIndexAvg(A, (int)i, minAvg, minAvgIndex);

	return minAvgIndex;
}

inline void calcIndexAvg(std::vector<int>& A, int index, float& minAvg, int& minAvgIndex)
{
	static int Asize = (int)A.size();

	float currentSum = A[index] + A[index + 1];
	int sumLength = 2;
	float currentAvg = currentSum / sumLength;
	float minTheoreticalSum = (-10000) * (Asize - index - sumLength);
	float minTheoreticalAvg = (currentSum + minTheoreticalSum) / Asize;

	if (currentAvg < minAvg) {
		minAvg = currentAvg;
		minAvgIndex = index;
	}

	while (minTheoreticalAvg < minAvg && (Asize - index - sumLength) >= 0) {
		currentSum += A[index + sumLength];
		sumLength++;
		currentAvg = currentSum / sumLength;
		minTheoreticalSum = (-10000 * (Asize - index - sumLength));
		minTheoreticalAvg = (currentSum + minTheoreticalSum) / Asize;

		if (currentAvg < minAvg) {
			minAvg = currentAvg;
			minAvgIndex = index;
		}
	}
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N*N)
