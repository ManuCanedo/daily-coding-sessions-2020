////////// SOLUTION PROGRESS
// Attempted with prime factorization (algorithm based in Sieve of Erathostenes). It works only with relatively small numbers.
// Current algorithm time complexity is O(N+M). Tomorrow will rework it to use Euclidean Algorithm.
// Solved 19_08_2020 with time complexity O(log(N+M)).

#include <vector>
#include <algorithm>

int solution(int N, int M)
{
	int sieveSize = (N > M) ? N : M;
	int sieveIndexN = N, sieveIndexM = M, MCD = 1;
	std::vector<int> sieve(sieveSize + 1, 0);
	std::vector<int> primeFactorsN, primeFactorsM;

	for (int i = 2; i * i <= sieveSize; ++i)
		if (sieve[i] == 0)
			for (int k = i * i; k <= sieveSize; k += i)
				sieve[k] = i;

	for (size_t i = 2; i < sieve.size(); ++i)
		if (sieve[i] == 0)
			sieve[i] = i;

	while (sieve[sieveIndexN] > 0) {
		primeFactorsN.push_back(sieve[sieveIndexN]);
		sieveIndexN /= sieve[sieveIndexN];
	}
	while (sieve[sieveIndexM] > 0) {
		primeFactorsM.push_back(sieve[sieveIndexM]);
		sieveIndexM /= sieve[sieveIndexM];
	}
	std::sort(primeFactorsN.begin(), primeFactorsN.end());
	std::sort(primeFactorsM.begin(), primeFactorsM.end());

	std::vector<int> MCDFactors;
	for (size_t i = 0, j = 0; i < primeFactorsN.size() && j < primeFactorsM.size(); ++i) {
		while (primeFactorsM[j] < primeFactorsN[i])
			++j;
		if (primeFactorsM[j] == primeFactorsN[i])
			MCDFactors.push_back(primeFactorsM[j++]);
	}

	for (int pF : MCDFactors)
		MCD *= pF;
	return N / MCD;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N+M)
