#pragma once

#include <utility>
#include <cassert>

template<typename T>

class Vector
{
public:

	Vector()
		: m_Values(nullptr),
		m_Capacity(0),
		m_Size(0)
	{

	}

	~Vector()
	{
		if (m_Values != nullptr)
		{
			delete[] m_Values;
			m_Values = nullptr;
		}

		m_Capacity = 0;
		m_Size = 0;
	}

	Vector(const Vector& other)
	{
		if (other.m_Capacity > 0)
		{
			m_Values = new T[other.m_Capacity];
			for (size_t i = 0; i < other.m_Capacity; i++)
			{
				m_Values[i] = other.m_Values[i];
			}
		}
		m_Capacity = other.m_Capacity;
		m_Size = other.m_Size;
	}
	Vector& operator=(const Vector& other)
	{
		if (m_Values != nullptr)
		{
			delete[] m_Values;
			m_Values = nullptr;
		}
		if (other.m_Capacity > 0)
		{
			m_Values = new T[other.m_Capacity];
			for (size_t i = 0; i < other.m_Capacity; i++)
			{
				m_Values[i] = other.m_Values[i];
			}
		}
		m_Capacity = other.m_Capacity;
		m_Size = other.m_Size;
		return *this;
	}

	Vector(Vector&& other)
	{
		m_Values = std::move(other.m_Values);
		m_Capacity = other.m_Capacity;
		m_Size = other.m_Size;

		other.m_Values = nullptr;
		other.m_Capacity = 0;
		other.m_Size = 0;
	}

	Vector& operator=(Vector&& other)
	{
		if (m_Values != nullptr)
		{
			delete[] m_Values;
			m_Values = nullptr;
		}

		m_Values = std::move(other.m_Values);
		m_Capacity = other.m_Capacity;
		m_Size = other.m_Size;

		other.m_Values = nullptr;
		other.m_Capacity = 0;
		other.m_Size = 0;
		return *this;

	}

	// reserve - preallocate a chunk of data as long as it is greater than the current capacity
	void Reserve(std::size_t capacity)
	{
		if (capacity > m_Capacity)
		{
			T* newValues = new T[capacity];
			if (m_Values != nullptr)
			{
				for (size_t i = 0; i < m_Size; i++)
				{
					newValues[i] = m_Values[i];
				}
			}

			delete[] m_Values;
			m_Values = std::move(newValues);
			m_Capacity = capacity;
		}
	}

	// Resize - it creates the container of data
	// can be larger/smaller than capacity
	// Sets capacity to resized value
	// removes/deletes items above new capacity
	void Resize(size_t size, const T& initialValue = T())
	{
		if (size == m_Size)
		{
			return;
		}

		if (size < m_Size)
		{
			// destroy elements above current size
			for (size_t i = 0; i < m_Size; i++)
			{
				// call destructor of unused elements
				m_Values[i].~T();
			}
		}
		else if (size > m_Size)
		{
			size_t newCapacity = std::max(size, m_Capacity * 2);
			Reserve(newCapacity);
			for (size_t i = 0; i < m_Size; i++)
			{
				m_Values[i] = initialValue;
			}
		}
		m_Size = size;
	}

	// clear
	void Clear()
	{
		Resize(0);
	}

	// get size
	size_t Size() const
	{
		return m_Size;
	}

	// get capacity
	size_t Capacity() const
	{
		return m_Capacity;
	}

	// add elements to the vector
	void PushBack(const T& value)
	{
		if (m_Size >= m_Capacity)
		{
			// if capacity is 0, set a default min capacity or double current 
			size_t newCapacity = (m_Capacity == 0) ? 10 : m_Capacity * 2;
			Reserve(newCapacity);
		}
		m_Values[m_Size] = value;
		++m_Size;
	}

	// remove element from the back
	void PopBack()
	{
		assert(m_Size > 0, "No elements in the vector");
		Resize(m_Size - 1);
	}

	// operator []
	T& operator[](std::size_t index)
	{
		assert(index < m_Size, "index out of range");
		return m_Values[index];
	}
	const T& operator[](std::size_t index) const
	{
		assert(index < m_Size, "index out of range");
		return m_Values[index];
	}

private:
	T* m_Values = nullptr;
	std::size_t m_Capacity = 0;	// maximum size of the container
	std::size_t m_Size = 0;		// maximum size of elements (< m_Capacity)
};

