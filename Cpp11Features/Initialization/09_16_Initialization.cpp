#include <iostream>
#include <string>
#include <vector>

struct C {
	std::string text;
	int id;
};

std::ostream& operator<<(std::ostream& os, C& c);

int main()
{
	C c1 = { "Hello", 10 };
	std::cout << "Class C value is: " << c1 << std::endl;

	int value{ 5 };
	std::string text{ "Hello" };
	int numbers[]{ 1, 2, 3 };
	int* pInt = new int[3]{ 1, 2, 3 };
	int* pNewInt{ nullptr };

	std::cout << "Int value is: " << value << "\nString value is: " << text
		  << "\nInt array value 2 is: " << numbers[1]
		  << "\nInt pointer array value 3 is: " << *(pInt + 2)
		  << "\nLet's better not deference pNewInt..." << std::endl;

	struct B {
		std::string name;
		int id;
	} b1{ "Agent", 700 };
	std::cout << "Struct contains " << b1.name << " " << b1.id << std::endl;

	std::vector<C> myCs{ { "Manuel", 1 }, { "Diego", 2 }, { "Susie", 3 } };
	std::cout << std::endl;
	for (C& c : myCs)
		std::cout << c << std::endl;

	return 0;
}

std::ostream& operator<<(std::ostream& os, C& c)
{
	os << c.text << ":" << c.id;
	return os;
}
