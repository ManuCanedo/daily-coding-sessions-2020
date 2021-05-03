#include <iostream>

template <typename T, typename K> auto test(T value1, K value2) -> decltype(value1 + value2)
{
	return value1 + value2;
}

int get()
{
	return 12;
}

auto test2() -> decltype(get())
{
	return get();
}

int main()
{
	// typeid and name mangling test
	std::string value;
	std::cout << "Type ID information: " << typeid(value).name() << std::endl;

	// decltype test
	decltype(value) name = "bob";
	std::cout << name << std::endl;

	// auto test
	std::cout << test(5, 6.0f) << std::endl;
	std::cout << test2() << std::endl;

	return 0;
}
