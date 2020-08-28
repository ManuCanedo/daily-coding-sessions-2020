////////// SOLUTION

int solution(int A, int B, int K) 
{
    int factors = 0, rangeStart = A;
    
    if (A == 0)
        factors++;
        
    if (K > B)
        return factors;

    rangeStart = (A > K) ? A: K;
    
    if (rangeStart%K == 0)
        factors++;
        
    factors += (B-rangeStart)/K;
    return factors;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ 0(1)
