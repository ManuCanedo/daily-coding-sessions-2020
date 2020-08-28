////////// SOLUTION
// Developed algorithm that calculates greater common divisor using Euclidean Algorithm and Divide and Conquer strategy.
// Achieved correctness for large numbers and improved yesterday's time complexity to O(log(N+M)). And it looks beautiful.

int gcd (int A, int B, int res);

int solution (int N, int M) 
{
    return N/gcd (N, M, 1);
}

inline int gcd (int A, int B, int res)
{
    if (A == B) 
        return A*res;
    else if (A%2 == 0 && B%2 == 0)
        return gcd(A/2, B/2, res*2);
    else if (A%2 == 0)
        return gcd(A/2, B, res);
    else if (B%2 == 0)
        return gcd(A, B/2, res);
    else if (A > B)
        return gcd(A-B, B, res);
    else
        return gcd(A, B-A, res);
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(log(N+M))

