#include <iostream>

class Test
{
public:
    Test(int value = 0)
    {
        // m_pBuffer = (int *)::operator new(size * sizeof(int)); // Raw memory allocation
        m_pBuffer = new int[SIZE]{value}; // The curly brackets with initialize the array ints to 0
        // memset(m_pBuffer, 0, sizeof(int)*SIZE) // Initialize each byte to 0s alternative way
    }

    // Same constructor, manual memory allocation

    // Test(int value = 0)
    // {
    //     m_pBuffer = (int *) ::operator new(sizeof(int)*SIZE);
    //     for (int i = 0; i < SIZE; ++i)
    //         new (&m_pBuffer[i]) int(value);
    // }

    Test(const Test &other)
        : Test()
    {
        *this = other;
    }

    ~Test()
    {
        delete[] m_pBuffer;
        // ::operator delete(m_pBuffer, sizeof(int)*SIZE);
        m_pBuffer = nullptr; // avoid dangling pointer
    }

    Test &operator=(const Test &other)
    {
        memcpy(m_pBuffer, other.m_pBuffer, sizeof(int) * Test::SIZE);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Test &other);

private:
    static const int SIZE = 100;
    int *m_pBuffer;
};

std::ostream &operator<<(std::ostream &os, const Test &other)
{
    for (int i = 0; i < Test::SIZE; ++i)
        os << *(other.m_pBuffer);
    return os;
}

int main()
{
    Test test1(1);
    Test test2;
    test1 = test2;
    std::cout << test1 << std::endl;

    return 0;
}
