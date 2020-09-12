#include <iostream>

class Animal
{
public:
    virtual void speak() = 0;
    virtual void run() = 0;
};

class Dog : public Animal
{
public:
    void speak()
    {
        std::cout << "woof!" << std::endl;
    }
};

class Sheppard : public Dog
{
public:
    Sheppard() = default;

    void run()
    {
        std::cout << "Here I go!" << std::endl; 
    }
};

int main()
{
    Sheppard moi;
    moi.speak();
    moi.run();

    Animal *animals[10];
    animals[0] = &moi;
    animals[0]->run();

    return 0;
}
