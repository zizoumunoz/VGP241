#pragma once

#include <iostream>
#include "Vector.h"

template<typename T, typename Compare = std::less<typename T>>

class PriorityQueue
{
public:
	PriorityQueue() {}

	bool Empty() const
	{
		return m_values.Size() == 0;
	}

	const std::size_t Size()
	{
		return m_values.Size();
	}

	void Push(const T& value)
	{
		m_values.PushBack(value);
		HeapifyUp(Size() - 1);
	}

	const T& Top() const
	{
		return m_values[0];
	}

	void Pop()
	{
		if (Empty())
		{
			assert(false, "Tried to pop an empty PriorityQueue!");
			return;
		}

		m_values[0] = m_values[Size() - 1];
		m_values.Resize(Size() - 1);
		HeapifyDown(0);
	}

private:
	void Swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	// maintain max-heap property
	void HeapifyUp(int index)
	{
		int parent = (index - 1) / 2;
		while (index > 0 && m_compare(m_values[parent], m_values[parent]))
		{
			Swap(m_values[index], m_values[parent]);
			index = parent;
			parent = (index - 1) / 2;
		}
	}

	void HeapifyDown(int index)
	{
		int largest = index;
		int leftChild = 2 * index + 1;
		int rightChild = 2 * index + 2;
		if (leftChild < Size() && m_compare(m_values[leftChild], m_values[largest]))
		{
			largest = leftChild;
		}
		if (rightChild < Size() && m_compare(m_values[rightChild], m_values[largest]))
		{
			largest = rightChild;
		}
		if (largest != index)
		{
			Swap(m_values[index], m_values[largest]);
			HeapifyDown(largest);
		}
	}

	Compare m_compare;
	Vector<T> m_values;
};
