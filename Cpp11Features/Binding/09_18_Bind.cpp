#include <iostream>
#include <functional>

using namespace std::placeholders;

class Math
{
public:
    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};

void printFunction(std::function<int(int, int)> func)
{
    std::cout << func(50, 200) << std::endl;
}

int main()
{
    Math calculator;
    auto calculate = std::bind(&Math::add, calculator, _1, 100, _2);
    printFunction(calculate);

    return 0;
}
