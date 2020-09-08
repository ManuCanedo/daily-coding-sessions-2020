#include <iostream>
#include <stack>
#include <queue>

class Test
{
public:
    Test(std::string name) : m_Name(name) {}

    ~Test()
    {
        std::cout << "\t~destroyed" << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const Test &other)
    {
        os << other.m_Name << std::flush;
        return os;
    }

private:
    std::string m_Name;
};

int main()
{
    std::stack<Test> testStack;
    std::queue<Test> testQueue;

    testStack.emplace("Cinema");
    testStack.emplace("Movie");
    testStack.emplace("Sports");

    /* 
    testStack.push(Test("Cinema"));
    testStack.push(Test("Movie"));
    testStack.push(Test("Sports"));
    std::cout << "------------" << std::endl; Shallow copy
    */

    /*     Test test1 = testStack.top();
    std::cout << test1 << std::endl;
    testStack.pop();
    std::cout << testStack.top() << std::endl;  Segmentation fault code     
    */

    std::cout << "Printing Stack:"
              << std::endl;

    while (testStack.size())
    {
        Test &test = testStack.top();
        std::cout << test << std::endl;
        testStack.pop();
    }
    std::cout << "\n"
              << std::endl;

    std::cout << "Printing queue:"
              << std::endl;

    testQueue.emplace("Cinema");
    testQueue.emplace("Sports");
    testQueue.emplace("Movie");

    while (testQueue.size())
    {
        Test &test = testQueue.front();
        std::cout << test << std::endl;
        testQueue.pop();
    }

    return 0;
}
