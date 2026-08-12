// Week6Exercises 

#include <iostream>
#include <vector>
#include <string>
#include "Texture.h"
#include "TextureCache.h"


void Exercise1()
{
	// Create a class called Texture
	// Have an array of floats for pixel colors
	// Create it with size, initializie array with size* size * 4
	//	Width, Height, and RGBA
	// Create a has table array that will store the textures
	// Create 100 of textures and add them to the has

	TextureCache myTextureCache;
	std::vector<std::string> directories = {
		"/Models/Texturess",
		"/UI/Textures",
		"/GamePlay/Textures",
		"/Environment/Textures"
	};

	int maxTextures = 100;
	for (int i = 0; i < maxTextures; i++)
	{
		int dirIndex = rand() % directories.size();
		std::string fullPath = directories[dirIndex] + "TextureName_" + std::to_string(i);
		myTextureCache.InsertTexture(fullPath);
	}

	myTextureCache.PrintTable();

	std::cout << "==================================\n";
	std::cout << "==================================\n";
	std::string findTexture = "/UI/Textures/TextureName_6";
	std::cout << "Find Texture: " << findTexture;
}

// Using bubble sort
template <typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
void BubbleSort(std::vector<T>& values)
{
	int size = values.size();
	// [][][][][][]
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (values[j + 1] < values[j])
			{
				Swap(values[j + 1], values[j]);
			}
		}
	}
}

void Exercise4()
{
	// Create class city
	// String m_name
	// print()
	// std::cout << m_name << " i "
}

void Exercise2()
{
	// Create a vector with 20 random numbers
	// Print numbers
	// Use a bubble sort to sort them from lowest to highest
	// Print numbers
	std::cout << "Bubble Sort:\n";
	std::vector<int> numbers;
	int maxNumbers = 20;
	for (int i = 0; i < maxNumbers; i++)
	{
		int value = rand() % 100;
		numbers.push_back(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	BubbleSort(numbers);
	std::cout << "\n";
	for (int i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << "\n";
}

int main()
{
	std::cout << "HashTables and Simple Sorting\n";
	// Exercise1();
	Exercise2();

}
