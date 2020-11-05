////////// SOLUTION

int solution(int N) 
{
    int currentPerimeter = 0, minPerimeter = 0;
    
    for (long int i = 1; i*i <= N; i++)
    {
        if (N%i == 0)
        {
            currentPerimeter = 2*(i+N/i);
            if (minPerimeter == 0 || currentPerimeter < minPerimeter)
                minPerimeter = currentPerimeter;
        }
    }
    return minPerimeter;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N^1/2)
