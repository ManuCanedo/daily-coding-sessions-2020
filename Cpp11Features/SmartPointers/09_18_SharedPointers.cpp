#include <iostream>
#include <memory>
#include <vector>

struct Test {
	Test(std::string name = "test") : testName(name)
	{
		std::cout << "Created" << std::endl;
	}

	~Test()
	{
		std::cout << "Destroyed" << std::endl;
	}

	Test(const Test& other) = default;

	void greet()
	{
		std::cout << "Hello, my name is " << testName << std::endl;
	}

	std::string testName;
};

int main()
{
	std::shared_ptr<Test> pTest1(std::make_shared<Test>("Peter"));
	pTest1->greet();

	return 0;
}
