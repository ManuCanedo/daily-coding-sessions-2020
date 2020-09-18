#include <iostream>
#include <memory>
#include <string>

template <typename T>
class Test
{
public:
    Test(int size = 1)
        : m_Size(size), m_pData(new T[size]{}) {}

    ~Test()
    {
        /* instead of manually deleting memory, m_pData will handle it
        because it is a smart pointer */

        // delete [] m_pData;
        // m_pData = nullptr;
    }

    Test(const Test<T> &other)
    {
        m_pData(new T[m_Size]);
        *this = other;
    }

    Test &operator=(const Test<T> &other)
    {
        memcpy(m_pData, other.m_pData, sizeof(T) * m_Size);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Test<T> &other);

private:
    const size_t m_Size;
    std::unique_ptr<T[]> m_pData;
    // T *m_pData{nullptr};
};

std::ostream &operator<<(std::ostream &os, const Test<int> &other)
{
    for (size_t i = 0; i < other.m_Size; ++i)
        os << other.m_pData[i];
    return os;
}

int main()
{
    Test<int> test(5);
    std::cout << test << std::endl;
    
    return 0;
}
