#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

struct Functor {
	bool operator()(std::string& str)
	{
		return str.size() == 3;
	}
} functor;

bool pFunction(std::string& str)
{
	return str.size() == 5;
}

bool run(std::function<bool(std::string&)> check)
{
	std::string test{ "TESTEDs" };
	return check(test);
}

int main()
{
	int count{ 0 };
	std::vector<std::string> texts{ "one",	"two",	  "three",  "four",
					"five", "eleven", "twelve", "thirteen" };
	std::cout << "Vector content:" << std::endl;
	for (std::string& s : texts)
		std::cout << s << " ";
	std::cout << "\n" << std::endl;

	count = std::count_if(texts.begin(), texts.end(), pFunction);
	std::cout << "count_if - Function pointer count (size = 5): " << count << std::endl;

	count = std::count_if(texts.begin(), texts.end(), functor);
	std::cout << "count_if - Functor count (size = 3): " << count << std::endl;

	auto lambda = [](std::string& str) { return str.size() == 7; };
	count = std::count_if(texts.begin(), texts.end(), lambda);
	std::cout << "count_if - Lambda count (size = 7): " << count << "\n" << std::endl;

	if (run(pFunction))
		std::cout << "Tested string has size 5" << std::endl;
	else if (run(functor))
		std::cout << "Tested string has size 3" << std::endl;
	else if (run(lambda))
		std::cout << "Tested string has size 7" << std::endl;

	std::function<int(int, int)> add = [](int a, int b) { return a + b; };
	std::cout << "Add Std Function result (2+5): " << add(2, 5) << std::endl;

	return 0;
}
