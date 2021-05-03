////////// DATA STRUCTURES PRACTICE

// Implementing my own version of the std::vector data structure.
// In this file I define the Vector class.
#ifndef VECTOR_H
#define VECTOR_h

#include <utility>
#include <cstddef>

template <typename Vector> class VectorIterator {
public:
	using ValueType = typename Vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	VectorIterator(PointerType ptr) : m_Ptr(ptr)
	{
	}

	VectorIterator& operator++()
	{
		++m_Ptr;
		return *this;
	}

	VectorIterator& operator++(int)
	{
		VectorIterator it = *this;
		++(*this);
		return *it;
	}

	VectorIterator& operator--()
	{
		--m_Ptr;
		return *this;
	}

	VectorIterator& operator--(int)
	{
		VectorIterator it = *this;
		--(*this);
		return *it;
	}

	ReferenceType operator[](const int index)
	{
		return *(m_Ptr + index);
	}
	ReferenceType operator*()
	{
		return *m_Ptr;
	}
	PointerType operator->()
	{
		return m_Ptr;
	}

	bool operator==(const VectorIterator& other) const
	{
		return m_Ptr == other.m_Ptr;
	}

	bool operator!=(const VectorIterator& other) const
	{
		return !(*this == other);
	}

private:
	PointerType m_Ptr;
};

template <typename T> class Vector {
public:
	using ValueType = T;
	using Iterator = VectorIterator<Vector<T> >;

public:
	Vector()
	{
		ReAlloc(2);
	}

	~Vector()
	{
		Clear();
		::operator delete(m_Data, m_Capacity * sizeof(T));
	}

	void PopBack()
	{
		if (m_Size > 0)
			m_Data[--m_Size].~T();
	}

	void Clear()
	{
		for (size_t i = 0; i < m_Size; ++i)
			m_Data[i].~T();

		m_Size = 0;
	}

	T PushBack(const T& value)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);

		m_Data[m_Size++] = value;
		return value;
	}

	T PushBack(T&& value)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);

		m_Data[m_Size++] = std::move(value);
		return value;
	}

	template <typename... Args> T& EmplaceBack(Args&&... args)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);

		new (&m_Data[m_Size]) T(std::forward<Args>(args)...);
		return m_Data[m_Size++];
	}

	Iterator begin()
	{
		return Iterator(m_Data);
	}

	Iterator end()
	{
		return Iterator(m_Data + m_Size);
	}

	const T& operator[](size_t index) const
	{
		return m_Data[index];
	}
	T& operator[](size_t index)
	{
		return m_Data[index];
	}
	size_t Size() const
	{
		return m_Size;
	}

private:
	void ReAlloc(size_t newCapacity)
	{
		T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

		if (newCapacity < m_Size)
			m_Size = newCapacity;

		for (size_t i = 0; i < m_Size; ++i)
			new (&newBlock[i]) T(std::move(m_Data[i]));

		for (size_t i = 0; i < m_Size; ++i)
			m_Data[i].~T();

		::operator delete(m_Data, m_Capacity * sizeof(T));
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

private:
	T* m_Data = nullptr;
	size_t m_Size = 0;
	size_t m_Capacity = 0;
};

#endif