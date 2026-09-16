#include <iostream>
#include <array>
#include <string>
#include <vector>

int HashValue(const std::string& key)
{
	// Just create the function to find the hash value

	int hash{};

	for (size_t i = 0; i < key.length(); i++)
	{
		hash += static_cast<int>(key[i]) * (i * 10 + 1);
	}

	return hash;
}

void AddItem(const std::string& key, int value, std::array<int, 20>& hashTable)
{
	// function to find the table index
	int index = HashValue(key) % hashTable.size();
	std::cout << key << " hash index is: " << index << "\n";
	hashTable[index] = value;
}

void PrintValue(std::string& key, const std::array<int, 20>& hashTable)
{
	int tableIndex = HashValue(key) % hashTable.size();
	std::cout << key << " : " << hashTable[tableIndex] << "\n";
}

void Exercise1HashTable()
{
	// Createa  simple hash function that convert a string to an int
	// Use the int to find the index in an array to place a value
	// Just create a the fucntion

	std::array<int, 20> hashTable = { 0 };

	AddItem("cat", rand() % 101, hashTable);
	AddItem("dog", rand() % 101, hashTable);
	AddItem("tac", rand() % 101, hashTable);


}

void InsertionSort(std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		int target = vec[i];
		int prevIndex = i - 1;

		// while our prev index is greater than zero (to not access negative indices)
		// and while target is less than whatever is in the previous index
		while (prevIndex > 0 && target < vec[prevIndex])
		{
			// set the spot after prevIndex to our value
			vec[prevIndex + 1] = vec[prevIndex];
			prevIndex = prevIndex - 1;	// set prev index to one lower
		}

		vec[prevIndex + 1] = target;

	}
}

void Merge(std::vector<int>& numbers, int start, int mid, int end)
{
	int leftSize = mid - start + 1;
	int rightSize = end - mid;
	std::vector<int> tmpLeft(leftSize);
	std::vector<int> tmpRight(rightSize);

	for (int i = 0; i < leftSize; i++)
	{
		tmpLeft[i] = numbers[start + i];
	}for (int i = 0; i < rightSize; i++)
	{
		tmpRight[i] = numbers[mid + 1 + i];
	}

	int left = 0;
	int right = 0;
	int i = start;

	while (left < leftSize && right < rightSize)
	{
		if (tmpLeft[left] < tmpRight[right])
		{
			numbers[i]
		}
	}
}

void PrintVec(std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

void Exercise2Sorting()
{
	// Create an insertion sorth algorithm
	// Create a merge sort algo
	// crate a vector of 100 random numbres between 1 - 1000
	// sort them with eaach function

	int maxNumbers = 20;
	int min = 1;
	int max = 1000;
	std::vector<int> insertionVec;
	std::vector<int> mergeVec;
	for (int i = 0; i < maxNumbers; i++)
	{
		int value = min + (rand() % ((max + 1) - min));
		insertionVec.push_back(value);
		mergeVec.push_back(value);
	}

	PrintVec(insertionVec);
	// sort with insertion sort
	InsertionSort(insertionVec);
	PrintVec(insertionVec);

	// sort with merge sort
}

int main()
{

	std::cout << "Final Review!\n";
	Exercise1HashTable();
	Exercise2Sorting();
	return 0;
}