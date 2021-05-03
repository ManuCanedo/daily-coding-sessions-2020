#include <iostream>
#include <string>

class Test {
public:
	void run()
	{
		int three{ 3 }, four{ 4 };
		auto pLambda = [three, this]() {
			std::cout << "Method local var: " << three << std::endl;
			std::cout << "Member var: " << one << std::endl;
		};
		pLambda();
	}

private:
	int one{ 1 }, two{ 2 };
};

int main()
{
	int one{ 1 }, two{ 2 }, three{ 3 };

	// Capture one and two by value
	[one, two]() { std::cout << one + two << std::endl; };

	// Capture one by value (modifiable)
	[one]() mutable {
		one = 99;
		std::cout << one << std::endl;
	};

	// Capture all by value and three by reference
	[=, &three]() {
		three = 10;
		std::cout << one + two - three << std::endl;
	};

	// Capture all by reference
	[&]() {
		two = 10;
		std::cout << two << std::endl;
	};

	Test test;
	test.run();

	return 0;
}
