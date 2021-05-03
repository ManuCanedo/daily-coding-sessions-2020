#include <iostream>
#include <string>

class Test {
public:
	// Test()
	//     : m_Id(0), m_Name("") {}

	Test(int id = 0, std::string name = "") : m_Id(id), m_Name(name)
	{
	}

	~Test()
	{
	}

	Test(const Test& other)
	{
		*this = other;
	}

	const Test& operator=(const Test& other)
	{
		m_Id = other.m_Id;
		m_Name = other.m_Name;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Test& other)
	{
		os << other.m_Id << ": " << other.m_Name;
		return os;
	}

private:
	int m_Id;
	std::string m_Name;
};

int main()
{
	Test test1;
	Test test2(1, "Paco");

	std::cout << test1 << " -- " << test2 << std::endl;

	return 0;
}
