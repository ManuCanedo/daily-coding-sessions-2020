#include <iostream>
#include <string>
#include <map>

template <class T, class K>
class Test
{
public:
    Test(T key, K obj)
    {
        this->key = key;
        this->obj = obj;
    }

    void print()
    {
        std::cout << obj << std::endl;
    }

private:
    T key;
    K obj;
};

int main()
{
    Test<int, std::string> test1(0, "Hello");
    Test<int, std::string> test2(1, "World");
    Test<int, double> test3(0, 0.1);

    return 0;
}
