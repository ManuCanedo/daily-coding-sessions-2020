#include <iostream>

template <typename T> void print(T obj)
{
	std::cout << "Template version: " << obj << std::endl;
}

void print(int num)
{
	std::cout << "Non Template version: " << num << std::endl;
}

template <typename T, typename K> void show(K obj)
{
	std::cout << T(obj) << std::endl;
}

int main()
{
	int myInt = 1;

	print(myInt);
	print<>(myInt);
	show<double>(myInt);

	return 0;
}
