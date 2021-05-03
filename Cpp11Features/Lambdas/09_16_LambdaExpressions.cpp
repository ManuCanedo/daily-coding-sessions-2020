#include <iostream>
#include <string>

void test(void (*pFunc)())
{
	pFunc();
}

void testGreet(void (*pGreet)(std::string))
{
	pGreet("Bob");
}

void runDivide(double (*pDivide)(double a, double b))
{
	auto rval = pDivide(9, 3.2);
	std::cout << rval << std::endl;
}

int main()
{
	test([]() { std::cout << "Hello!" << std::endl; });

	auto pGreet = [](std::string name) { std::cout << "Hello " << name << "!" << std::endl; };
	testGreet(pGreet);

	auto divide = [](double a, double b) -> double { return a / b; };
	runDivide(divide);

	return 0;
}
