#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Test
{
public:
    Test() : m_Id(0), m_Name("") {}
    Test(int id, std::string name) : m_Id(id), m_Name(name) {}

    friend std::ostream &operator<<(std::ostream &os, const Test &other)
    {
        os << other.m_Id << ": " << other.m_Name << std::flush;
        return os;
    }

    static bool comp(const Test &a, const Test &b)
    {
        return a.m_Name < b.m_Name;
    }

private:
    int m_Id;
    std::string m_Name;
};

int main()
{
    std::vector<Test> tests;
    tests.emplace_back(5, "Mike");
    tests.emplace_back(3, "John");
    tests.emplace_back(3, "Jane");
    tests.emplace_back(5, "Peter");
    
    for (Test &t : tests)
    {
        std::cout << t << std::endl;
    }
    std::cout << "\nSorted:" << std::endl;

    std::sort(tests.begin()+1, tests.end(), Test::comp);
    for (Test &t : tests)
    {
        std::cout << t << std::endl;
    }

    return 0;
}