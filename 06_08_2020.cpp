////////// CHALLENGE DESCRIPTION

// A string S consisting of N characters is called properly nested if:

// S is empty;
// S has the form "(U)" where U is a properly nested string;
// S has the form "VW" where V and W are properly nested strings.
// For example, string "(()(())())" is properly nested but string "())" isn't.

// Write a function:

// int solution(string &S);

// that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.

// For example, given S = "(()(())())", the function should return 1 and given S = "())", the function should return 0, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [0..1,000,000];
// string S consists only of the characters "(" and/or ")".


////////// SOLUTION 

#include <vector>
#include <string>

int solution(std::string &S) 
{
    std::vector<int> nesting;
    
    for (size_t i = 0; i < S.size(); ++i)
    {
        switch (S[i])
        {
            case 40:
                nesting.push_back(S[i]);
                break;
            case 41:
                if (!nesting.empty())
                    nesting.pop_back();
                else
                    return 0;
                break;
            default:
                break;
        }
    }
    return (nesting.empty()) ? 1 : 0;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)
////////// AVG ~ O(N)


////////// CHALLENGE DESCRIPTION

// You are going to build a stone wall. The wall should be straight and N meters long, and its thickness should be constant; however, it should have different heights in different places. The height of the wall is specified by an array H of N positive integers. H[I] is the height of the wall from I to I+1 meters to the right of its left end. In particular, H[0] is the height of the wall's left end and H[N−1] is the height of the wall's right end.

// The wall should be built of cuboid stone blocks (that is, all sides of such blocks are rectangular). Your task is to compute the minimum number of blocks needed to build the wall.

// Write a function:

// int solution(vector<int> &H);

// that, given an array H of N positive integers specifying the height of the wall, returns the minimum number of blocks needed to build it.

// For example, given array H containing N = 9 integers:

//   H[0] = 8    H[1] = 8    H[2] = 5
//   H[3] = 7    H[4] = 9    H[5] = 8
//   H[6] = 7    H[7] = 4    H[8] = 8

// the function should return 7. The figure shows one possible arrangement of seven blocks.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// each element of array H is an integer within the range [1..1,000,000,000].


////////// SOLUTION 

#include <vector>

int solution(std::vector<int> &H) 
{
    std::vector<int> blocks;
    int numBlocks = 0;
    
    for (size_t i = 0; i < H.size(); ++i)
    {
        while (!blocks.empty() && H[i] < blocks.back()) 
            blocks.pop_back();
        
        if (!blocks.empty() && H[i] == blocks.back())
            continue;
        
        blocks.push_back(H[i]);
        ++numBlocks;
    }
    return numBlocks;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ O(N)
////////// AVG ~ O(N)