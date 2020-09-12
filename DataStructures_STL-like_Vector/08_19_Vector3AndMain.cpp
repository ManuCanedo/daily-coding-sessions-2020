////////// DATA STRUCTURES PRACTICE

// Implementing my own version of the std::vector data structure.
// In this file I define struct Vector3 and some functions to test the functionality of Vectors and Vector3s.

#include <iostream>
#include <string>
#include "09_12_Vector.h"

struct Vector3
{
    float x = 0.0f, y = 0.0f, z = 0.0f;
    int *m_MemoryBlock = nullptr;

    Vector3() {}
    Vector3(float scalar)
        : x(scalar), y(scalar), z(scalar)
    {
        m_MemoryBlock = new int[3];
    }

    Vector3(float x, float y, float z)
        : x(x), y(y), z(z)
    {
        m_MemoryBlock = new int[3];
    }

    Vector3(const Vector3 &other)
        : x(other.x), y(other.y), z(other.z)
    {
        if (other.m_MemoryBlock != nullptr)
        {
            m_MemoryBlock = new int[3];
            std::copy(other.m_MemoryBlock, other.m_MemoryBlock + 3, m_MemoryBlock);
        }
    }

    Vector3(Vector3 &&other)
        : x(other.x), y(other.y), z(other.z)
    {
        m_MemoryBlock = other.m_MemoryBlock;
        other.m_MemoryBlock = nullptr;
    }

    ~Vector3()
    {
        delete[] m_MemoryBlock;
    }

    Vector3 &operator=(const Vector3 &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
    Vector3 &operator=(Vector3 &&other)
    {
        m_MemoryBlock = other.m_MemoryBlock;
        other.m_MemoryBlock = nullptr;
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, Vector3 &other)
    {
        os << "(" << other.x << "," << other.y << "," << other.z << ")";
        return os;
    }
};

template <typename T>
void PrintVector(const Vector<T> &vector)
{
    for (size_t i = 0; i < vector.Size(); ++i)
        std::cout << vector[i] << std::endl;
    std::cout << std::endl;
}

template <>
void PrintVector(const Vector<Vector3> &vector)
{
    for (size_t i = 0; i < vector.Size(); ++i)
        std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
    std::cout << std::endl;
}

int main()
{
    // Testing Vector<std::string> type
    Vector<std::string> vector;
    vector.EmplaceBack("Hello");
    vector.EmplaceBack("Hello1");
    vector.EmplaceBack("Hello12");
    vector.EmplaceBack("Hello123");
    vector.PopBack();
    vector.PushBack("test1");

    PrintVector(vector);

    std::cout << "Range for loop" << std::endl;
    for (auto &v : vector)
        std::cout << v << std::endl;

    std::cout << std::endl;
    std::cout << "Iterators for loop" << std::endl;
    for (auto it = vector.begin(); it != vector.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;

    // Testing iterators on a Vector<Vector3> type
    Vector<Vector3> vector3;
    vector3.EmplaceBack(1, 2, 3);
    vector3.EmplaceBack(2, 3, 4);
    vector3.EmplaceBack(3, 4, 5);
    vector3.EmplaceBack(4, 5, 6);

    PrintVector(vector3);

    std::cout << "Range for loop" << std::endl;
    for (auto &v : vector3)
        std::cout << v << std::endl;

    std::cout << std::endl;
    std::cout << "Iterators for loop" << std::endl;
    for (auto it = vector3.begin(); it != vector3.end(); ++it)
        std::cout << *it << std::endl;

    std::cin.get();
}
