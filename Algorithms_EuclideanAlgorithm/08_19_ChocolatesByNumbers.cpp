////////// CHALLENGE DESCRIPTION

// Two positive integers N and M are given. Integer N represents the number of chocolates arranged in a circle, numbered from 0 to N − 1.

// You start to eat the chocolates. After eating a chocolate you leave only a wrapper.

// You begin with eating chocolate number 0. Then you omit the next M − 1 chocolates or wrappers on the circle, and eat the following one.

// More precisely, if you ate chocolate number X, then you will next eat the chocolate with number (X + M) modulo N (remainder of division).

// You stop eating when you encounter an empty wrapper.

// For example, given integers N = 10 and M = 4. You will eat the following chocolates: 0, 4, 8, 2, 6.

// The goal is to count the number of chocolates that you will eat, following the above rules.

// Write a function:

// int solution(int N, int M);

// that, given two positive integers N and M, returns the number of chocolates that you will eat.

// For example, given integers N = 10 and M = 4. the function should return 5, as explained above.

// Write an efficient algorithm for the following assumptions:

// N and M are integers within the range [1..1,000,000,000].


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
////////// AVG ~ 0(log(N+M))

