////////// DATA STRUCTURES PRACTICE

// Implementing my own version of std::vector
// In this file I define struct Vector3 and the corresponding templated functions to print Vectors and Vector3s.

#include <iostream>
#include "08_19_Vector3AndMain.h"

struct Vector3
{
    float x = 0.0f, y = 0.0f, z = 0.0f;

    Vector3() {}
    Vector3(float scalar)
        : x(scalar), y(scalar), z(scalar) {}
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z) {}
    
    Vector3(const Vector3& other)
        : x(other.x), y(other.y), z(other.z)
    {
        // std::cout << "Copied\n";
    }
    ~Vector3()
    {
        // std::cout << "Destroyed\n";
    }

    Vector3& operator=(const Vector3& other)
    {
        // std::cout << "Copied\n";
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
    Vector3& operator=(const Vector3&& other)
    {
        // std::cout << "Moved\n";
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
};

template<typename T>
void PrintVector(const Vector<T>& vector)
{
    for (size_t i = 0; i < vector.Size(); ++i)
        std::cout << vector[i] << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
}

template<>
void PrintVector(const Vector<Vector3>& vector)
{
    for (size_t i = 0; i < vector.Size(); ++i)
        std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
}

int main()
{
    Vector<Vector3> vector;
    vector.PushBack(Vector3(1.0f));
    vector.PushBack(Vector3());
    vector.PushBack(Vector3(0.2f, 0.4f, 0.8f));

    PrintVector(vector);
    std::cin.get();
}



