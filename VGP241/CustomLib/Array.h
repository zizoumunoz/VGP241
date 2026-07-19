#pragma once

#include <cstddef>
#include <utility>

template<typename T, std::size_t N>

class Array
{
public:
	// base constructor, always called by default
	Array()
	{
		// will generate a dimension by default
		static_assert(N > 0, "Array must be at least 1.");	// will throw error at compile time

		// allocate memory
		// size required is size of T, which is the type of the object
		// times the number of items, which is N
		m_Values = new T[N];

	}

	Array(T initialValue)
	{
		static_assert(N > 0, "Array must be at least 1.");
		m_Values = new T[N];
		for (size_t i = 0; i < N; ++i)
		{
			m_Values[i] = initialValue;
		}
	}

	// copy constructor (called on creation)
	// copies the information of another same sized array
	Array(const Array& other)
	{
		m_Values = new T[N];
		for (size_t i = 0; i < N; i++)
		{
			m_Values[i] = other.m_Values[i];
		}
	}

	// copy operator (after creation, so may have data)
	Array& operator=(const Array& other)
	{
		// if you have an array of objects that have pointers or data, that data needs to be released or memory leak
		// so empty the new array before you assign the new values from the new array.
		if (m_Values != nullptr)
		{
			delete[] m_Values;
		}
		m_Values = new T[N];
		for (size_t i = 0; i < N; i++)
		{
			m_Values[i] = other.m_Values[i];
		}
		return *this;
	}

	// move constructor 
	Array(Array&& other)
	{
		// not deleting the data, just changing ownership (data stays same place, just ownership changes, faster than copy)
		m_Values = std::remove_const(other.m_Values);
		// clearing the info
		other.m_Values = nullptr;
	}

	// move operator
	Array& operator=(Array&& other)
	{
		// make sure the array we are gonna move into is empty
		if (m_Values != nullptr)
		{
			delete[] m_Values;
		}

		m_Values = std::move(other.m_Values);
		other.m_Values = nullptr;
		return *this;
	}

	// destructor
	~Array()
	{
		if (m_Values != nullptr)
		{
			delete[] m_Values;
			m_Values = nullptr;
		}
	}


	// some helper functions

	/// <summary>
	/// Get number of elements. It is const after the funcion so it can be called if an array is const.
	/// </summary>
	/// <returns>size_t N: number of elements</returns>
	const size_t Size() const
	{
		return N;
	}

	/// <summary>
	/// Get stored data
	/// </summary>
	/// <returns></returns>
	T* Data()
	{
		return m_Values;
	}


	// operator overload[]
	T& operator[](size_t index)
	{
		// can throw assert if out of range
		return m_Values[index];
	}

	const T& operator[](size_t index) const
	{
		return m_Values[index];
	}


private:
	// T is the type we declare
	// pointer to a section of memory where the array is built
	T* m_Values = nullptr;

};