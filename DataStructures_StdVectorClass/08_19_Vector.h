////////// DATA STRUCTURES PRACTICE

// Implementing my own version of std::vector
// In this file I define the Vector class.

template<typename T>
class Vector 
{
public:
    Vector()
    {
        // Allocate initial memory
        ReAlloc(2);
    }

    T PushBack(const T& value)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity/2);

        m_Data[m_Size++] = value;
        return value;
    }

    const T& operator[](size_t index) const { return m_Data[index]; }
    T& operator[](size_t index) { return m_Data[index]; }
    size_t Size() const { return m_Size; }

private:
    void ReAlloc(size_t newCapacity)
    {
        T* newBlock = new T[newCapacity];

        if (newCapacity < m_Size)
            m_Size = newCapacity;
            
        for (size_t i = 0; i < m_Size; ++i)
            newBlock[i] = m_Data[i];

        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }

private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};
