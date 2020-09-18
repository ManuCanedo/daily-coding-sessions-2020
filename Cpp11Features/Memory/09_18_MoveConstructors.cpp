#include <iostream>
#include <vector>

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

    Test(Test &&other)
        : Test()
    {
        m_pBuffer = other.m_pBuffer;
        other.m_pBuffer = nullptr;
    }

    Test &operator=(const Test &other)
    {
        memcpy(m_pBuffer, other.m_pBuffer, sizeof(int) * Test::SIZE);
        return *this;
    }

    Test &operator=(Test &&other)
    {
        delete[] m_pBuffer;
        m_pBuffer = other.m_pBuffer;
        other.m_pBuffer = nullptr;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Test &other);

private:
    static const int SIZE{100};
    int *m_pBuffer{nullptr};
};

std::ostream &operator<<(std::ostream &os, const Test &other)
{
    for (int i = 0; i < Test::SIZE; ++i)
        os << *(other.m_pBuffer);
    return os;
}

int main()
{
    std::vector<Test> vec1{4, 2, 3};
    std::vector<Test> vec2(5, 1);
    vec1.push_back(Test());
    vec2[0] = Test();
    std::cout << vec2[0] << std::endl;

    return 0;
}