#include <iostream>

class Parent
{
public:
    Parent(int val = 0)
        : m_ParentValue(val) {}

    Parent(const Parent &other)
    {
        std::cout << "Parent copy constructor called" << std::endl;
    }
    virtual void printMethod()
    {
        std::cout << "Parent print method called" << std::endl;
    }

private:
    int m_ParentValue;
};

class Child : public Parent
{
public:
    Child(int val = 0)
        : m_ChildValue(val) {}

    virtual void printMethod()
    {
        std::cout << "Child print method called" << std::endl;
    }

private:
    int m_ChildValue;
};

int main()
{
    Child c1;
    Parent &p1 = c1;
    p1.printMethod();

    Parent p2 = Child(); // Copy initialization so calls implicit copy const in Parent
    p2.printMethod();

    return 0;
}