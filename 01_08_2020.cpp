// This is a code I wrote to help a friend of mine with a challenge he was doing. Ocen I get the full challenge description I will update this inctroduction. 

#include <vector>
#include <iostream>

inline void check(std::vector<char>& mySequence, std::vector<char>& myFragment, const int &i, int& myCounter, int &indexStart, bool &bErrorUsed, bool &bChecking)
{
    if (mySequence[i] == myFragment[i - indexStart])
    {
        if ((myFragment.begin() + i - indexStart + 1) == myFragment.end())
        {
            myCounter++;
            indexStart = -1;
            bChecking = bErrorUsed = false;
        }
    }
    else if (!bErrorUsed)
    {
        if ((myFragment.begin() + i - indexStart + 1) == myFragment.end())
        {
            myCounter++;
            indexStart = -1;
            bChecking = bErrorUsed = false;
        }
        else
        {
            bErrorUsed = true;
        }
    }
}

inline int function(std::vector<char> &mySequence, std::vector<char> &myFragment)
{
    int myCounter = 0, indexStart = -1, indexStartSecond = 0;
    bool bChecking = false, bErrorUsed = false;
    std::vector<int> possibles;

    for (size_t i = 0; i < mySequence.size(); ++i)
    {
        if (bChecking)
        {
            check(mySequence, myFragment, i, myCounter, indexStart, bErrorUsed, bChecking);

            if (mySequence[i] == myFragment[0])
            {
                possibles.push_back(i);
            }
            else if (i > 0 && mySequence[i] == myFragment[1])
            {
                possibles.push_back(i-1);
            }
        }
        else if (!bChecking)
        {
            if (mySequence[i] == myFragment[0])
            {
                bChecking = true;
                indexStart = i;
            }
            else if (i > 0 && mySequence[i] == myFragment[1])
            {
                bChecking = bErrorUsed = true;
                indexStart = i - 1;
            }
        }
    }

    // Second iteration here to operate with the other possible sequence matches starting points, in case that the specifications require it.

    return myCounter;
}

int main()
{
    std::vector<char> mySequence = {'a', 'd', 'D', 'F', 'a', 'd', 'a', 'd', 'F', 'a', 'F'};
    std::vector<char> myFragment = {'a', 'd'};
    int result = function(mySequence, myFragment);

    std::cout << result << std::endl;
    std::cin >> result;
    return 0;
}
