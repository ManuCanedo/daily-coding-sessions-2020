#include <iostream>
#include <string>

struct Test {
	virtual bool operator()(std::string& text) = 0;
	virtual ~Test()
	{
	}
};

struct Tester : public Test {
	virtual bool operator()(std::string& text)
	{
		return text == "lion";
	}
};

void check(std::string text, Tester& tester)
{
	if (tester(text))
		std::cout << "Text matches" << std::endl;
	else
		std::cout << "Text does not match" << std::endl;
}

int main()
{
	Tester pred;
	std::string value = "lion";

	check("lion", pred);

	return 0;
}