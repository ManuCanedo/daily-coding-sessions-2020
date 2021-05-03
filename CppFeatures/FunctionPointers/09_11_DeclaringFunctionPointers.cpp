#include <iostream>

void test()
{
	std::cout << "Hello World" << std::endl;
}

inline void callFunction(void (*pTest)())
{
	// Pointer deferenced to call the function
	pTest();
}

int main()
{
	// Direct call to test()
	test();

	// Pointer to function with no params that returs void called pTest
	// Initialized with the address of test()
	void (*pTest)() = &test;
	// This can be simplified to: void (*pTest)() = test;

	// Pointer deferenced to call the function
	(*pTest)();
	// This can be simplified to: pTest();

	// Pointer as parameter. Function accepts type pointer to no params void function
	callFunction(pTest);

	return 0;
}
