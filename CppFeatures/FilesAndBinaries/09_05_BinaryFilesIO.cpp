#include <iostream>
#include <fstream>
#include <string>

#pragma pack(push, 1)
struct Person {
	char name[50];
	int age;
	double height;
};
#pragma pack(pop)

Person readBinary(std::string fileName);

int main()
{
	Person someone = { "Frodo", 220, 0.8 };
	std::string fileName = "CppFeatures/FilesAndBinaries/test.bin";
	std::fstream outputFile;

	outputFile.open(fileName, std::ios::binary | std::ios::out);
	if (outputFile.is_open()) {
		outputFile.write(reinterpret_cast<char*>(&someone), sizeof(Person));
		outputFile.close();
	} else
		std::cout << "Could not create file " << fileName;

	Person someoneElse = readBinary(fileName);
	std::cout << "Name, age and height: " << someoneElse.name << ", " << someoneElse.age << ", "
		  << someoneElse.height << std::endl;
}

Person readBinary(std::string fileName)
{
	Person thisPerson = {};
	std::fstream inputStream;

	inputStream.open(fileName, std::ios::binary | std::ios::in);
	if (inputStream.is_open()) {
		inputStream.read(reinterpret_cast<char*>(&thisPerson), sizeof(Person));
		inputStream.close();
	} else
		std::cout << "Could not create file " << fileName;

	return thisPerson;
}
