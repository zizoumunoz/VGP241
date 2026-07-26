#pragma once

// Gives accessibility to iterator functions
// can be tied into and used with std::sorting functions (std::sort, priorityqueue...)
// Iterate over containers instead of indexing through them

#include <algorithm>
#include <iterator>
#include <cstddef>

template <typename T>

class ContainerIterator
{
public:
	// define ids/names for stl use (std::sort, std::find, std::find_if)
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using pointer = T*;
	using reference = T&;

public:

	ContainerIterator(T* ptr) : m_ptr(ptr) {}

	T& operator*()	// star operator to get the address of something
	{
		return *m_ptr;
	}

	T* operator->()	// dereference operator to get the value of something a pointer points at
	{
		return m_ptr;
	}

	// ++iter
	ContainerIterator& operator++()
	{
		++m_ptr;
		return *this;
	}

	// --iter
	ContainerIterator& operator--()
	{
		--m_ptr;
		return *this;
	}

	// post increments
	ContainerIterator operator++(int)
	{
		ContainerIterator tmp = *this;
		++(*this);
		return tmp;
	}

	ContainerIterator operator--(int)
	{
		ContainerIterator tmp = *this;
		--(*this);
		return tmp;
	}

	// (+ and -) does not modify the object
	ContainerIterator operator+(difference_type n) const { return ContainerIterator(m_ptr + n); }
	ContainerIterator operator-(difference_type n) const { return ContainerIterator(m_ptr - n); }

	// (+= and -=) modifies the object and returns a reference
	ContainerIterator& operator+=(difference_type n) { m_ptr += n; return *this; }
	ContainerIterator& operator-=(difference_type n) { m_ptr -= n; return *this; }

	difference_type operator-(const ContainerIterator& rhs) const { return m_ptr - rhs.m_ptr; }

	// comparisons
	bool operator==(const ContainerIterator& rhs) const { return m_ptr == rhs.m_ptr; }
	bool operator!=(const ContainerIterator& rhs) const { return m_ptr != rhs.m_ptr; }
	bool operator<(const ContainerIterator& rhs) const { return m_ptr < rhs.m_ptr; }
	bool operator>(const ContainerIterator& rhs) const { return m_ptr > rhs.m_ptr; }
	bool operator<=(const ContainerIterator& rhs) const { return m_ptr <= rhs.m_ptr; }
	bool operator>=(const ContainerIterator& rhs) const { return m_ptr >= rhs.m_ptr; }

private:
	T* m_ptr = nullptr;

};
