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

