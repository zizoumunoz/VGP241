#include <iostream>
#include <vector>
#include <chrono>

std::chrono::steady_clock::time_point gStartTime;
void StartAlgorithm()
{
	gStartTime = std::chrono::steady_clock::now();
}

void PrintDuration()
{
	auto endTime = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - gStartTime);
	std::cout << "Time (mc)" << duration.count() << "\n";
}

void InsertionSort(std::vector<int>& vec)
{
	// splits the container (vector/array) into a sorted sectdion and a unsorted section
	// unlike selection sort, we just grab the next in the unsorted secion and add it into the sorted section
	for (int i = 1; i < vec.size(); ++i)
	{
		// get the next value in the unsorted sectdion to compare with the sorted sectdion
		int key = vec[i];
		// j is the back of the sorted section
		// traverse backwards until its spot is found
		int j = i - 1;
		while (j >= 0)
		{
			if (vec[j] > key)
			{
				vec[j + 1] = vec[j];
				--j;
			}
			else { break; }
		}
		vec[j + 1] = key;
	}
}

void Exercise1InsertionSort()
{
	// Create Insertion Sort functionality
	// Create a ector of 2- random umbers from 1 - 100
	// Print the numbers when added
	// Run through the sort algorithm and ensure the numbers are sorted
	std::cout << "Insertion Sort:\n";
	std::vector<int> vec;
	for (int i = 0; i < 20; ++i)
	{
		int value = 1 + (rand() % 100);
		vec.push_back(value);
		std::cout << value << " ";
	}

	std::cout << "\n";
	InsertionSort(vec);
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

void Merge(std::vector<int>& vec, int left, int midPoint, int right)
{
	// get the sie of each section
	int leftSize = (midPoint - left) + 1;
	int rightSize = (right - midPoint);

	// create temp versions of each side
	std::vector<int> tempLeft(leftSize);	// initializing a vector with a value calls "resize"
	std::vector<int> tempRight(rightSize);

	// copy all the values from the left side of the vec (they should be sorted at this pont)
	for (int i = 0; i < leftSize; ++i)
	{
		tempLeft[i] = vec[left + i];
	}

	// copoy all the values from the right sede of the vec (they should be sorted at this pont)
	for (int i = 0; i < rightSize; ++i)
	{
		tempRight[i] = vec[midPoint + i + 1];
	}

	// swap the values using the temp values and adding them back into the vec
	int leftIndex = 0; // current index of the left side
	int rightIndex = 0; // current index of the right side
	int vecIndex = left; // current index of the whole vector
	while (leftIndex < leftSize && rightIndex < rightSize)
	{
		// if tempLeft < tempRight, use the left value and increment index
		if (tempLeft[leftIndex] < tempRight[rightIndex])
		{
			vec[vecIndex] = tempLeft[leftIndex];
			++leftIndex;
		}
		// otherwise take from the temp right
		else
		{
			vec[vecIndex] = tempRight[rightIndex];
			++rightIndex;
		}
		// either way increment the vec Index
		++vecIndex;
	}

	// add any remaining values that have not been transferred yet (eg: odd number or one whole side is smaller than the othere)
	// start with left as it should already be smallest
	while (leftIndex < leftSize)
	{
		vec[vecIndex] = tempLeft[leftIndex];
		++leftIndex;
		++vecIndex;
	}
	// then any remaining on the right
	while (rightIndex < rightSize)
	{
		++rightIndex;
		++vecIndex;
	}
}

void MergeSort(std::vector<int>& vec, int left, int right)
{
	if (left < right)
	{
		int midPoint = left + ((right - left) / 2);
		// split the vector

		MergeSort(vec, left, midPoint);
		MergeSort(vec, midPoint + 1, right);

		Merge(vec, left, midPoint, right);
	}
}

void Exerise2MergeSort()
{
	// Create Merge Sort functionality
	// Create a ector of 2- random umbers from 1 - 100
	// Print the numbers when added
	// Run through the sort algorithm and ensure the numbers are sorted
	std::cout << "Merge Sort:\n";
	std::vector<int> vec;
	for (int i = 0; i < 20; ++i)
	{
		int value = 1 + (rand() % 100);
		vec.push_back(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	std::cout << "Sorted:\n";
	MergeSort(vec, 0, vec.size() - 1);
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

// need a swap for Quick Sort
void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
	// a = b + a;
	// b = a - b;
	// a = a - b;
}

// partition to get the pivot point and move elements on either side
int Partition(std::vector<int>& vec, int left, int right)
{
	// choose last element as the pivot (does not really matter, some instances rand is faster, some its the middle)
	// if picking a set value, reduces calculations to find a specific index
	int pivot = vec[right];
	int i = left - 1;
	for (int j = left; j < right; ++j)
	{
		if (vec[j] < pivot)
		{
			++i;
			Swap(vec[i], vec[j]);
		}
	}
	// swpa pivot to location in vec where it is in the middle of the values
	Swap(vec[i + 1], vec[right]);
	// this will be our left
	return i + 1;
}

void QuickSort(std::vector<int>& vec, int left, int right)
{
	if (left < right)
	{
		int p = Partition(vec, left, right);
		QuickSort(vec, left, p - 1);
		QuickSort(vec, p + 1, right);
	}
}

void Exercise3QuickSort()
{
	std::cout << "Quick Sort:\n";
	std::vector<int> vec;
	for (int i = 0; i < 20; ++i)
	{
		int value = 1 + (rand() % 100);
		vec.push_back(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	std::cout << "Sorted:\n";
	QuickSort(vec, 0, vec.size() - 1);
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

void BucketSort(std::vector<int>& vec)
{
	const int size = vec.size();
	int maxValue = 0;
	for (int i = 0; i < size; ++i)
	{
		maxValue = std::max(maxValue, vec[i]);
	}
	// take the max value, add 1, this will prevent 0-1, because arrays is 0-(size-1)
	++maxValue;
	// create buckets/tables of elements
	// bucket size can be any value that fits the number of elements
	const int bucketSize = size / 2;
	std::vector<std::vector<int>> buckets(size);
	// add elements to the respective buckets
	for (int i = 0; i < size; ++i)
	{
		int bucketIndex = ((size * vec[i]) / maxValue);
		buckets[bucketIndex].push_back(vec[i]);
	}
	// sort each bucket ( user insertion sort)
	int vecIndex = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < buckets[i].size(); ++j)
		{
			vec[vecIndex] = buckets[i][j];
			++vecIndex;
		}
	}
}

void Exercise4BucketSort()
{
	std::cout << "Bucket Sort:\n";
	std::vector<int> vec;
	for (int i = 0; i < 20; ++i)
	{
		int value = 1 + (rand() % 100);
		vec.push_back(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	std::cout << "Sorted:\n";
	BucketSort(vec);
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";

	}
	std::cout << "\n";
}

void CountinSort(std::vector<int>& vec, int exp)
{
	std::vector<int> output(vec.size());
	int count[10] = { 0 };

	for (int i = 0; i < vec.size(); i++)
	{
		int index = (vec[i] / exp) % 10;
		++count[index];
	}

	for (int i = 1; i < 10; ++i)
	{
		count[i] += count[i - 1];
	}

	for (int i = vec.size() - 1; i >= 0; --i)
	{
		int index = (vec[i] / exp) % 10;
		output[count[index] - 1] = vec[i];
		--count[index];
	}

	for (int i = 0; i < vec.size(); ++i)
	{
		vec[i] = output[i];
	}
}
void PrintVec(const std::vector<int>& vec)
{
	for (const auto& num : vec)
	{
		std::cout << num << " ";
	}
	std::cout << "\n";
}
void RadixSort(std::vector<int>& vec)
{
	// only works for numberic values or fixed sized strings *eg: no long sentences), possible for floats, but need fixed digits
	int maxValue = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		maxValue = std::max(maxValue, vec[i]);
	}
	// each division of 10, we can isolate the individual digit
	// 123 (at exp = 1, we can get 12[3], at exp 10 we can get 1[2]3, etc.
	for (int exp = 1; maxValue / exp > 0; exp *= 10)
	{
		// we need another sorting method that uses an algorithm(counting sort)
		CountinSort(vec, exp);
		PrintVec(vec);
	}
}
void Exercise5RadixSort()
{
	// Creaate radix sort functionality
	// Create a vector of 20 random numbers from 1 - 100
	// Print the numbers when added
	// Run thrugh the sort algorithm and ensure the numbers are sorted
	std::cout << "Radix Sort:\n";
	std::vector<int> vec;
	for (int i = 0; i < 20; ++i)
	{
		int value = 1 + (rand() % 1000);
		vec.push_back(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	std::cout << "Sorted:\n";
	RadixSort(vec);
	PrintVec(vec);
}

void IntroSort()
{
	if (left < right)
	{
		// if less than 20 elements, just intro sort
		if (right - left < 20)
		{
			// this is intro sort , but only going between left and right
			for (int i = left + 1; i < right; ++i)
			{
				// get the next value in the unsorted section to compare with the sorted section
				int key = vec[i];
				// j is the back of the sorted section 
				// traverse backwards until its spot is found
				int j = i - 1;
				while (j >= 0)
				{
					if (vec[j] > key)
					{
						vec[j + 1] = vec[j];
						--j;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
}

void Exercise6IntroSort()
{
	// Create intro sort functionality
	// Create a vector of 20 random numbers from 1 - 100
	// Print the numbers when added
	// Run through the sort algorithm and ensure the numbers are sorted

	std::cout << "Intro Sort:\n";
	std::vector<int> vec;
	for (int i = 0; i < 35; ++i)
	{
		int value = 1 + (rand() % 1000);
		vec.push_back(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	std::cout << "Sorted:\n";
	IntroSort(vec, vec.size() - 1);
	PrintVec(vec);
}


void RaceNumbers(int maxNumbers)
{
	std::vector<int> vecInsert;
	std::vector<int> vecMerge;
	std::vector<int> vecQuick;
	std::vector<int> vecBucket;
	std::vector<int> vecRadix;
	std::vector<int> vecIntro;

	for (size_t i = 0; i < maxNumbers; i++)
	{
		int value = 1 + (rand() % 10000);
		vecInsert.push_back(value);
		vecMerge.push_back(value);
		vecQuick.push_back(value);
		vecBucket.push_back(value);
		vecRadix.push_back(value);
		vecIntro.push_back(value); 
	}

	std::cout << "Insertion Sort:\n";
	StartAlgorithm();
	InsertionSort(vecInsert);
	PrintDuration();
	std::cout << "\n";
}

void Exercise7SortRace()
{

}

int main()
{
	std::cout << "Advanced Sorting:\n";
	//Exercise1InsertionSort();
	//Exerise2MergeSort();
	//Exercise3QuickSort();
	//Exercise4BucketSort();

	Exercise5RadixSort();

}