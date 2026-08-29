#pragma once

#include <string>
#include <functional>
#include "Vector.h"

namespace Global
{
	// hash function
	inline std::size_t HashFunction(const std::string& str)
	{
		std::size_t hash = 0;
		for (size_t i = 0; i < str.size(); ++i)
		{
			hash = (~hash << i) + (std::size_t)(str[i]);
		}
		return hash;
	}

	// swap 
	template<typename T>
	void Swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	// bubble sort
	template<typename T, typename Compare = std::less<T>>
	void BubbleSort(Vector<T>& values, Compare sortFunc = Compare{})
	{
		std::size_t size = values.Size();
		for (size_t i = 0; i < size - 1; ++i)
		{
			for (size_t j = 0; j < size - i - 1; ++j)
			{
				if (sortFunc(values[j + 1], values[j]))
				{
					Swap(values[j + 1], values[j]);
				}
			}
		}
	}
	// overloaded bubblesort with suport for std::vector
	template<typename T, typename Compare = std::less<T>>
	void BubbleSort(std::vector<T>& values, Compare sortFunc = Compare{})
	{
		std::size_t size = values.size();
		for (size_t i = 0; i < size - 1; ++i)
		{
			for (size_t j = 0; j < size - i - 1; ++j)
			{
				if (sortFunc(values[j + 1], values[j]))
				{
					Swap(values[j + 1], values[j]);
				}
			}
		}
	}


	// Selection sort
	template<typename T, typename Compare = std::less<T>>
	void SelectionSort(Vector<T>& values, Compare sortFunc = Compare{})
	{
		std::size_t size = values.Size();
		for (size_t i = 0; i < size - 1; i++)
		{
			std::size_t minIndex = i;
			for (size_t j = i + 1; j < size; j++)
			{
				if (sortFunc(values[j], values[minIndex]))
				{
					minIndex = j;
				}
			}
			if (i != minIndex)
			{
				Swap(values[i], values[minIndex]);
			}
		}
	}

	template<typename T, typename Compare = std::less<typename std::iterator_traits<ContainerIterator<T>>::value_type>>
	void InsertionSort(ContainerIterator<T> begin, ContainerIterator<T> end, Compare comp = Compare())
	{
		if (begin == end)
		{
			return;
		}
		for (ContainerIterator<T> iter = begin + 1; iter != end; ++iter)
		{
			T key = *iter;
			ContainerIterator<T> j = iter;
			while (j > begin)
			{
				if (comp(key, *(j - 1)))
				{
					*j = *(j - 1);
					--j;
				}
				else
				{
					break;
				}
			}
			*j = key;
		}
	}

	// merge sort
	namespace MergeSortHelpers
	{
		template<typename T, typename Compare>
		void Merge(ContainerIterator<T> left, ContainerIterator<T> mid, ContainerIterator<T> right, Compare comp)
		{
			// create temp versions
			Vector<T> temp;
			temp.Reserve(right - left);
			// left half (left to mid)
			ContainerIterator<T> tempLeft = left;
			// right half(mid to right)
			ContainerIterator<T> tempRight = mid;
			while (tempLeft != mid && tempRight != right)
			{
				if (comp(*tempLeft, *tempRight))
				{
					temp.PushBack(*tempLeft);
					++tempLeft;
				}
				else
				{
					temp.PushBack(*tempRight);
					++tempRight;
				}
			}
			while (tempLeft != mid)
			{
				temp.PushBack(*tempLeft);
				++tempLeft;
			}
			while (tempRight != right)
			{
				temp.PushBack(*tempRight);
				++tempRight;
			}
			for (size_t i = 0; i < temp.Size(); ++i)
			{
				*(left + i) = temp[i];
			}
		}
	}

	template<typename T, typename Compare = std::less<T>>
	void MergeSort(ContainerIterator<T> begin, ContainerIterator<T> end, Compare comp = Compare())
	{
		size_t size = end - begin;
		if (size > 1)
		{
			size_t half = size / 2;
			ContainerIterator<T> mid = begin + half;
			// split the data
			MergeSort(begin, mid, comp);
			MergeSort(mid, end, comp);
			//merge resuts
			MergeSortHelpers::Merge(begin, mid, end, comp);
		}
	}


	// quick sort

	namespace QuickSortHelpers
	{
		template<typename T, typename Compare>
		ContainerIterator<T> Partition(ContainerIterator<T> begin, ContainerIterator<T> end, Compare comp)
		{
			ContainerIterator<T> pivot = end - 1;
			ContainerIterator<T> i = begin;
			for (ContainerIterator<T> j = begin; j != pivot; ++j)
			{
				if (comp(*j, *pivot))
				{
					Swap(*i, *j);
					++i;
				}
			}
			Swap(*i, *pivot);
			return i;
		}
	}

	template<typename T, typename Compare = std::less<T>>
	void QuickSort(ContainerIterator<T> begin, ContainerIterator<T> end, Compare comp = Compare())
	{
		if ((end - begin) > 1)
		{
			ContainerIterator<T> p = QuickSortHelpers::Partition(begin, end, comp);
			QuickSort(begin, p, comp);
			QuickSort(p + 1, end, comp);
		}
	}

	// bucket sort
	template<typename T>
	void BucketSort(ContainerIterator<T> begin, ContainerIterator<T> end)
	{
		// onlyl works with classes that have a '<'
		// onlyl works with classes that also have a '/'
		// usees algorithm to sort

		// find the max value
		ContainerIterator<T> maxValue = begin;
		for (ContainerIterator<T> iter = begin + 1; iter != end; ++iter)
		{
			if (*maxValue < *iter)
			{
				maxValue = iter;
			}
		}

		size_t size = (end - begin);
		Vector<Vector<T>> buckets;
		buckets.Resize(size);
		for (ContainerIterator<T> iter = begin; iter != end; ++iter)
		{
			size_t bucketIndex = ((size - 1) * (*iter)) / (*maxValue);
			buckets[bucketIndex].PushBack(*iter);
		}
		// sort each bucket
		for (size_t i = 0; i < size; i++)
		{
			InsertionSort(buckets[i].Begin(), buckets[i].End());
		}
		// Combine all the buckets
		ContainerIterator<T> iter = begin;
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < buckets[i].Size(); j++)
			{
				(*iter) = buckets[i][j];
				++iter;
			}
		}
	}


	// heap sort
	namespace HeapSortHelpers
	{
		template<typename T, typename Compare>
		void Heapify(ContainerIterator<T> begin, ContainerIterator<T> root, size_t count, Compare comp)
		{
			ContainerIterator<T> largest = root;
			ContainerIterator<T> i = begin + (2 * (root - begin) + 1);
			ContainerIterator<T> j = begin + (2 * (root - begin) + 2);
			// make sure the value is within the container, then compare
			if (i < begin + count && comp(*largest, *i))
			{
				largest = i;
			}
			if (j < begin + count && comp(*largest, *j))
			{
				largest = j;
			}
			if (largest != root)
			{
				Swap(*root, *largest);
				Heapify(begin, largest, count, comp);
			}
		}
	}

	template<typename T, typename Compare = std::less<T>>
	void HeapSort(ContainerIterator<T> begin, ContainerIterator<T> end, Compare comp = Compare())
	{
		int count = (end - begin);
		if (count <= 1)
		{
			return;
		}

		// build the max heahp
		for (ContainerIterator<T> iter = begin + (count / 2) - 1; iter >= begin; --iter)
		{
			HeapSortHelpers::Heapify(begin, iter, count, comp);
		}
		// extract the elements from the heap
		for (ContainerIterator<T> iter = end - 1; iter > begin; --iter)
		{
			Swap(*begin, *iter);
			HeapSortHelpers::Heapify(begin, begin, iter - begin, comp);
		}
	}

	// intro sort (std::sort)
	namespace IntroSortHelpers
	{
		template<typename T, typename Compare>
		void IntroSortUtil(ContainerIterator<T> begin, ContainerIterator<T> end, int depthLimit, Compare comp)
		{
			// if less than 16 elements ues insertion sort
			size_t count = end - begin;
			if (count < 16)
			{
				InsertionSort(begin, end, comp);
				return;
			}
			// if depth limit is reached due to recursion, use heap sort
			if (depthLimit <= 0)
			{
				HeapSort(begin, end, comp);
				return;
			}
			// function as a quick sort
			ContainerIterator<T> p = QuickSortHelpers::Partition(begin, end, comp);
			IntroSortUtil(begin, p, depthLimit - 1, comp);
			IntroSortUtil(p + 1, end, depthLimit - 1, comp);
		}
	}

	template<typename T, typename Compare = std::less<T>>
	void IntroSort(ContainerIterator<T> begin, ContainerIterator<T> end, Compare comp = Compare())
	{
		// use 3 different types of sorting
		// if less than 16 elements, use insertion sort
		// if the recursive depth > some value we set, we use heap sort
		// otherwise use quicksort
		size_t count = end - begin;
		if (count > 1)
		{
			int depthLimit = 2 * std::log2(count);
		}
	}
}
