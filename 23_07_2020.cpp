// A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

// The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

// For example, consider string S = CAGCCTA and arrays P, Q such that:

//     P[0] = 2    Q[0] = 4
//     P[1] = 5    Q[1] = 5
//     P[2] = 0    Q[2] = 6
// The answers to these M = 3 queries are as follows:

// The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
// The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
// The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.
// Write a function:

// vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

// that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M integers specifying the consecutive answers to all queries.

// Result array should be returned as a vector of integers.

// For example, given the string S = CAGCCTA and arrays P, Q such that:

//     P[0] = 2    Q[0] = 4
//     P[1] = 5    Q[1] = 5
//     P[2] = 0    Q[2] = 6
// the function should return the values [2, 4, 1], as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// M is an integer within the range [1..50,000];
// each element of arrays P, Q is an integer within the range [0..N − 1];
// P[K] ≤ Q[K], where 0 ≤ K < M;
// string S consists only of upper-case English letters A, C, G, T.


// CODE THAT FAILED THE PERFORMANCE TEST 1

#include <vector>
#include <string>

std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
    
    std::vector<int> result;
    result.reserve(P.size());
    std::string mySubString = "";

    for (unsigned int i = 0; i < P.size(); ++i)
    {
        mySubString = S.substr(P[i], Q[i]-P[i]+1);
        if (mySubString.find('A') != std::string::npos)
        {
            result.push_back(1);
        }
        else if (mySubString.find('C') != std::string::npos)
        {
            result.push_back(2);
        }
        else if (mySubString.find('G') != std::string::npos)
        {
            result.push_back(3);
        }
        else
        {
            result.push_back(4);
        }
    }
    return result;
}

// CODE THAT FAILED THE PERFORMANCE TEST 2

std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
    
    std::vector<int> result;
    result.reserve(P.size());
    std::string mySubString = "";

    for (unsigned int i = 0; i < P.size(); ++i)
    {
        mySubString = S.substr(P[i], Q[i]-P[i]+1);
        bool bA = false, bC = false, bG = false, bT = false;
        
        for (unsigned int i = 0; i < mySubString.size(); ++i)
        {
            if (mySubString[i] == 'A')
            {
                bA = true;
                break;
            }
            switch ((int)mySubString[i])
            {
                case 'C':
                    bC = true;
                    break;
                case 'G':
                    bG = true;
                    break;
                case 'T':
                    bT = true;
                    break;
            }
        }
        
        if (bA)
        {
            result.push_back(1); 
        }
        else if (bC)
        {
            result.push_back(2); 
        }
        else if (bG)
        {
            result.push_back(3);
        }
        else if (bT)
        {
            result.push_back(4);
        }
        else {
            result.push_back(-1);
        }
    }
    return result;
}


// CODE THAT FAILED THE PERFORMANCE TEST BY A FEW MS

#include <vector>
#include <string>
#include <iostream>

std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
    
    std::vector<int> result;
    result.reserve(P.size());
    std::vector<int> nucleiA;
    nucleiA.reserve(S.size());
    std::vector<int> nucleiC;
    nucleiC.reserve(S.size());
    std::vector<int> nucleiG;
    nucleiA.reserve(S.size());

    for (unsigned int i = 0; i < S.size(); ++i)
    {
        switch ((int)S[i])
        {
            case 'A':
                nucleiA.push_back(i);
                break;
            case 'C':
                nucleiC.push_back(i);
                break;
            case 'G':
                nucleiG.push_back(i);
                break;
        }
    }
    
    bool bFound = false;
    for (unsigned int i = 0; i < P.size(); ++i)
    {
        bFound = false;
        for (unsigned int j = 0; j < nucleiA.size(); ++j)
        {
            if (nucleiA[j] > Q[i])
                break;
            if (((unsigned)nucleiA[j]-(unsigned)P[i]) <= ((unsigned)Q[i]-(unsigned)P[i]))
            {
                result.push_back(1);
                bFound = true;
                break;
            }
        }
        
        for (unsigned int j = 0; j < nucleiC.size() && !bFound; ++j)
        {
            if (nucleiC[j] > Q[i])
                break;
            if ((unsigned)(nucleiC[j]-(unsigned)P[i]) <= ((unsigned)Q[i]-(unsigned)P[i]))
            {
                result.push_back(2);
                bFound = true;
                break;
            }
        }
        
        for (unsigned int j = 0; j < nucleiG.size() && !bFound; ++j)
        {
            if (nucleiG[j] > Q[i])
                break;
            if (((unsigned)nucleiG[j]-(unsigned)P[i]) <= ((unsigned)Q[i]-(unsigned)P[i]))
            {
                result.push_back(3);
                bFound = true;
                break;
            }
        }
        
        if (!bFound) 
        {
            result.push_back(4);
        }
    }
    return result;
}


// CODE THAT PASSED THE PERFORMANCE TEST

std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
    
    std::vector<int> result;
    result.reserve(P.size());
    std::vector<int> nucleiA;
    nucleiA.reserve(S.size());
    std::vector<int> nucleiC;
    nucleiC.reserve(S.size());
    std::vector<int> nucleiG;
    nucleiA.reserve(S.size());

    for (unsigned int i = 0; i < S.size(); ++i)
    {
        switch ((int)S[i])
        {
            case 'A':
                nucleiA.emplace_back(i);
                break;
            case 'C':
                nucleiC.emplace_back(i);
                break;
            case 'G':
                nucleiG.emplace_back(i);
                break;
        }
    }
    
    bool bFound = false;
    for (unsigned int i = 0; i < P.size(); ++i)
    {
        bFound = false;
        for (unsigned int j = 0; j < nucleiA.size(); j+=2)
        {
            if (nucleiA[j] > Q[i])
                break;
            if (((unsigned)nucleiA[j]-(unsigned)P[i]) <= ((unsigned)Q[i]-(unsigned)P[i]))
            {
                result.emplace_back(1);
                bFound = true;
                break;
            }
        }
        
        for (unsigned int j = 1; j < nucleiA.size() && !bFound; j+=2)
        {
            if (nucleiA[j] > Q[i])
                break;
            if (((unsigned)nucleiA[j]-(unsigned)P[i]) <= ((unsigned)Q[i]-(unsigned)P[i]))
            {
                result.emplace_back(1);
                bFound = true;
                break;
            }
        }
        
        for (unsigned int j = 0; j < nucleiC.size() && !bFound; j+=2)
        {
            if (nucleiC[j] > Q[i])
                break;
            if ((unsigned)(nucleiC[j]-(unsigned)P[i]) <= ((unsigned)Q[i]-(unsigned)P[i]))
            {
                result.emplace_back(2);
                bFound = true;
                break;
            }
        }
        
        for (unsigned int j = 1; j < nucleiC.size() && !bFound; j+=2)
        {
            if (nucleiC[j] > Q[i])
                break;
            if ((unsigned)(nucleiC[j]-(unsigned)P[i]) <= ((unsigned)Q[i]-(unsigned)P[i]))
            {
                result.emplace_back(2);
                bFound = true;
                break;
            }
        }
        
        for (unsigned int j = 0; j < nucleiG.size() && !bFound; j+=2)
        {
            if (nucleiG[j] > Q[i])
                break;
            if (((unsigned)nucleiG[j]-(unsigned)P[i]) <= ((unsigned)Q[i]-(unsigned)P[i]))
            {
                result.emplace_back(3);
                bFound = true;
                break;
            }
        }
        
        for (unsigned int j = 1; j < nucleiG.size() && !bFound; j+=2)
        {
            if (nucleiG[j] > Q[i])
                break;
            if (((unsigned)nucleiG[j]-(unsigned)P[i]) <= ((unsigned)Q[i]-(unsigned)P[i]))
            {
                result.emplace_back(3);
                bFound = true;
                break;
            }
        }
        
        if (!bFound) 
        {
            result.emplace_back(4);
        }
    }
    return result;
}
