#pragma once

#include "Vector.h"
template<typename T>
class Queue
{
public:
	void Enqueue(const T& value)
	{
		m_values.PushBack(value);
	}
	void Dequeue()
	{
		assert(!Empty());
		m_values.PopFront();
	}
	const T& Front() const
	{
		assert(!Empty());
		return m_values[0];
	}


	size_t Size() const
	{
		return m_values.Size();
	}

	bool Empty() const
	{
		return m_values.Size() == 0;
	}
private:
	Vector<T> m_values;
};