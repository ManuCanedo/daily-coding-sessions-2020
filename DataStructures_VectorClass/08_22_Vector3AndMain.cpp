////////// DATA STRUCTURES PRACTICE

// Implementing my own version of the std::vector data structure.
// In this file I define struct Vector3 and some functions to test the functionality of Vectors and Vector3s.

#include <iostream>
#include "08_22_Vector.h"

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
        // std::cout << "Destroyed\n";
        delete[] m_MemoryBlock;
    }

    Vector3 &operator=(const Vector3 &other)
    {
        // std::cout << "Copied\n";
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
    Vector3 &operator=(Vector3 &&other)
    {
        // std::cout << "Moved\n";
        m_MemoryBlock = other.m_MemoryBlock;
        other.m_MemoryBlock = nullptr;
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
};

template <typename T>
void PrintVector(const Vector<T> &vector)
{
    for (size_t i = 0; i < vector.Size(); ++i)
        std::cout << vector[i] << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
}

template <>
void PrintVector(const Vector<Vector3> &vector)
{
    for (size_t i = 0; i < vector.Size(); ++i)
        std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
}

int main()
{
    Vector<Vector3> vector;
    vector.PushBack(Vector3(1.0f));
    vector.EmplaceBack(2, 3, 4);
    PrintVector(vector);
    vector.PopBack();
    PrintVector(vector);
    vector.PushBack(Vector3(0.2f, 0.4f, 0.8f));
    vector.Clear();
    PrintVector(vector);

    std::cin.get();
}
