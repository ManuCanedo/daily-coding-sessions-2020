#include <iostream>
#include <set>
#include <string>

class Test {
public:
	Test() : m_Id(0), m_Name("")
	{
	}
	Test(int id, std::string name) : m_Id(id), m_Name(name)
	{
	}

	friend std::ostream& operator<<(std::ostream& os, const Test& other)
	{
		os << other.m_Id << ": " << other.m_Name << std::flush;
		return os;
	}

	bool operator<(const Test& other) const
	{
		if (m_Name == other.m_Name)
			return m_Id < other.m_Id;
		else
			return m_Name < other.m_Name;
	}

private:
	int m_Id;
	std::string m_Name;
};

int main()
{
	std::set<Test> tests;

	tests.emplace(14, "Paco");
	for (std::set<Test>::iterator it = tests.begin(); it != tests.end(); ++it)
		std::cout << *it << std::endl;

	return 0;
}
