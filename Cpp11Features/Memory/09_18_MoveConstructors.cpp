#include <iostream>

class Test
{
public:
    Test(int value = 0)
    {
        m_pBuffer = new int[SIZE]{value};
    }

    Test(const Test &other)
        : Test()
    {
        *this = other;
    }

    ~Test()
    {
        delete[] m_pBuffer;
        m_pBuffer = nullptr;
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
    std::cout << test1 << std::endl;

    return 0;
}