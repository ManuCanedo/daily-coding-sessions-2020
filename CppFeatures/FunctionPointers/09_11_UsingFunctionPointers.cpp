#include <iostream>
#include <vector>
#include <algorithm>

bool match(std::string test)
{
	return test.size() == 3;
}

int count_if(std::vector<std::string>::iterator beg, const std::vector<std::string>::iterator& end,
	     bool (*match)(std::string test))
{
	int count = 0;
	while (beg != end) {
		count += match(*beg);
		++beg;
	}
	return count;
}

int main()
{
	std::vector<std::string> texts;
	texts.emplace_back("One");
	texts.emplace_back("Two");
	texts.emplace_back("Three");
	texts.emplace_back("Four");
	texts.emplace_back("Five");
	texts.emplace_back("Six");
	texts.emplace_back("Seven");
	texts.emplace_back("Eight");
	texts.emplace_back("Nine");

	std::cout << "Local version: " << count_if(texts.begin(), texts.end(), match) << std::endl;
	std::cout << "STL version: " << std::count_if(texts.begin(), texts.end(), match)
		  << std::endl;

	return 0;
}
