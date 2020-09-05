#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::fstream outFile, inFile;
    std::string inputFileName = "CppFeatures/FilesAndBinaries/inputText.txt";

    inFile.open(inputFileName, std::ios::in);

    if (!inFile.is_open())
    {
        std::cout << "Could not open file " << inputFileName << std::endl;
        return 1;
    }

    while (inFile)
    {
        std::string line;
        int population = 0;

        std::getline(inFile, line, ':');
        inFile >> population;
        inFile >> std::ws;
        
        if (!inFile)
            break;

        std::cout << "'" << line << "'" << "--- '" << population << "'" << std::endl;
        std::cout << "Extracted population value: " << population << std::endl;
        
    }
    inFile.close();

    return 0;
}