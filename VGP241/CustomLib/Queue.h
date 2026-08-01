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
		assert(!Empty(), "[Error] trying to dequeue an empty queue!");
		m_values.PopFront();
	}
	const T& Front() const
	{
		assert(!Empty(), "[Error] trying to view the front of an empty queue!");
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