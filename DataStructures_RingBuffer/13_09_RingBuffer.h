#ifndef RING_H
#define RING_H

#include <cstdlib>

template <typename Ring> class RingIterator {
public:
	using ValueType = typename Ring::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	RingIterator(PointerType ptr) : m_Ptr(ptr)
	{
	}

	RingIterator& operator++()
	{
		++m_Ptr;
		return *this;
	}

	RingIterator& operator++(int)
	{
		RingIterator it = *this;
		++(*this);
		return *it;
	}

	RingIterator& operator--()
	{
		--m_Ptr;
		return *this;
	}

	RingIterator& operator--(int)
	{
		RingIterator it = *this;
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

	bool operator==(const RingIterator& other) const
	{
		return m_Ptr == other.m_Ptr;
	}

	bool operator!=(const RingIterator& other) const
	{
		return !(*this == other);
	}

private:
	PointerType m_Ptr;
};

template <typename T> class Ring {
public:
	using Iterator = RingIterator<Ring<T> >;
	using ValueType = T;

public:
	Ring(int ringSize)
	{
		ReAlloc(ringSize);
		m_Size = ringSize;
		Init(0);
	}

	~Ring()
	{
		clear();

		::operator delete(m_Data, m_Size * sizeof(T));
		m_Size = 0;
		m_Data = nullptr;
	}

	Ring(Ring& other)
	{
		*this = other;
	}

	template <typename... Args> void emplace(Args&&... args)
	{
		new (&m_Data[m_BufferIndex++]) T(std::forward<Args>(args)...);
		if (m_BufferIndex >= m_Size)
			m_BufferIndex = 0;
	}

	void resize(size_t size)
	{
		size_t initIndex = m_Size;
		ReAlloc(size);
		if (initIndex < m_Size)
			Init(initIndex);
	}

	Iterator begin()
	{
		return Iterator(m_Data);
	}

	Iterator end()
	{
		return Iterator(m_Data + m_Size);
	}

	Ring& operator=(Ring& other)
	{
		m_Size = other.size();
	}

	size_t size()
	{
		return m_Size;
	}
	T& operator[](size_t index)
	{
		return m_Data[index];
	}

private:
	void clear()
	{
		for (size_t i = 0; i < m_Size; ++i)
			m_Data[i].~T();
	}

	void ReAlloc(size_t size)
	{
		T* newBlock = (T*)::operator new(size * sizeof(T));

		if (size < m_Size) {
			m_Size = size;
			if (m_BufferIndex >= m_Size)
				m_BufferIndex = m_Size - 1;
		}

		for (size_t i = 0; i < m_Size; ++i)
			newBlock[i] = std::move(m_Data[i]);

		clear();
		::operator delete(m_Data, m_Size * sizeof(T));
		m_Data = newBlock;
	}

	void Init(size_t startIndex)
	{
		for (size_t i = startIndex; i < m_Size; ++i)
			new (&m_Data[i]) T();
	}

private:
	T* m_Data = nullptr;
	size_t m_Size = 0;
	size_t m_BufferIndex = 0;
};

#endif /* RING_H */
