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


////////// CHALLENGE DESCRIPTION

// An integer N is given, representing the area of some rectangle.

// The area of a rectangle whose sides are of length A and B is A * B, and the perimeter is 2 * (A + B).

// The goal is to find the minimal perimeter of any rectangle whose area equals N. The sides of this rectangle should be only integers.

// For example, given integer N = 30, rectangles of area 30 are:

// (1, 30), with a perimeter of 62,
// (2, 15), with a perimeter of 34,
// (3, 10), with a perimeter of 26,
// (5, 6), with a perimeter of 22.
// Write a function:

// int solution(int N);

// that, given an integer N, returns the minimal perimeter of any rectangle whose area is exactly equal to N.

// For example, given an integer N = 30, the function should return 22, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..1,000,000,000].


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
////////// AVG ~ 0(N^1/2)

