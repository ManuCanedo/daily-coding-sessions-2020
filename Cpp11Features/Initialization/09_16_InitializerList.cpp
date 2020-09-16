#include <iostream>
#include <initializer_list>
#include <vector>
#include <string>

std::ostream &operator<<(std::ostream &os, std::initializer_list<std::string> &texts);

class Test
{
public:
    Test(std::initializer_list<std::string> texts)
        : m_Texts(texts)
    {
        std::cout << texts << std::endl;
    }

private:
    std::vector<std::string> m_Texts;
};

int main()
{
    Test test{{"Hello"}, {"world"}, {"and"}, {"hello"}, {"mars!"}};
    
    return 0;
}

std::ostream &operator<<(std::ostream &os, std::initializer_list<std::string> &texts)
{
    for (auto &t : texts)
        os << t << " ";
    return os;
}
