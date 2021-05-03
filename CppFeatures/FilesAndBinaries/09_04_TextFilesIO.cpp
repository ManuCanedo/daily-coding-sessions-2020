#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::fstream outFile, inFile;
	std::string outputFileName = "CppFeatures/FilesAndBinaries/text.txt";
	std::string inputFileName = "CppFeatures/FilesAndBinaries/text.txt";

	outFile.open(outputFileName, std::ios::out);
	if (outFile.is_open()) {
		outFile << "Hello World!\n";
		outFile << 123 << std::endl;
		outFile.close();
	} else {
		std::cout << "Could not create file " << outputFileName << std::endl;
	}

	inFile.open(inputFileName, std::ios::in);
	if (inFile.is_open()) {
		std::string line;
		while (inFile) {
			std::getline(inFile, line);
			std::cout << line << std::endl;
		}
		inFile.close();
	} else {
		std::cout << "Could not open file " << outputFileName << std::endl;
	}

	return 0;
}