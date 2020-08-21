////////// CHALLENGE DESCRIPTION

// A positive integer D is a factor of a positive integer N if there exists an integer M such that N = D * M.

// For example, 6 is a factor of 24, because M = 4 satisfies the above condition (24 = 6 * 4).

// Write a function:

// int solution(int N);

// that, given a positive integer N, returns the number of its factors.

// For example, given N = 24, the function should return 8, because 24 has 8 factors, namely 1, 2, 3, 4, 6, 8, 12, 24. There are no other factors of 24.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..2,147,483,647].


////////// SOLUTION

int solution(int N) 
{
    int factorsCount = 0;
    
    for (long int i = 1; i*i <= N; i++)
    {
        if (N%i == 0)
        {
            if (i*i == N)
                factorsCount += 1; // Syntax used for legibility reasons
            else
                factorsCount += 2;
        }
    }
    return factorsCount;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N^1/2)
////////// AVG ~ 0(N^1/2)

