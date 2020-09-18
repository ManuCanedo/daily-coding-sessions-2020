#include <iostream>

class Test
{
};

template <typename T>
void call(T &&arg)
{
    std::cout << "* no cast: ";
    check(arg);
    std::cout << "* static_cast<T>(arg): ";
    check(static_cast<T>(arg));
    std::cout << "* std::forward<T>(arg): ";
    check(std::forward<T>(arg));
}

void check(Test &lval)
{
    std::cout << "lvalue" << std::endl;
}

void check(Test &&rval)
{
    std::cout << "rvalue" << std::endl;
}

int main()
{
    std::cout << " - Function called with an rvalue - " << std::endl;
    call(Test());

    return 0;
}