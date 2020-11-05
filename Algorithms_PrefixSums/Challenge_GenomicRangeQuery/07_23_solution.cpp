////////// SOLUTION

std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
    
    std::vector<int> result(P.size()), nucleiA(S.size()),  nucleiC(S.size()), nucleiG(S.size());

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
            result.emplace_back(4);
    }
    
    return result;
}

////////// CORRECT BEHAVIOUR
////////// TIME COMPLEXITY:
////////// MAX ~ 0(N)
