#pragma once

#include "Vector.h"

template<typename T>
// Encapsulation of vector that limits user to very specific controls
class Stack
{
public:
	// only 4 main funcs, push, pop, top, empty
	void Push(const T& value)
	{
		m_values.PushBack(value);
	}
	void Pop()
	{
		assert(!Empty(), "[Error] Tring to pop and empty stack!");
		m_values.PopBack();
	}
	const T& Top()
	{
		assert(!Empty(), "[Error] Trying to view an epty stack!");	
		return m_values[Size() - 1];
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
	Vector<T>  m_values;
};