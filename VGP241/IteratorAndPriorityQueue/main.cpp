#include <iostream>
#include <Vector.h>
#include <Array.h>
#include <ContainerIterator.h>

int main()
{
	std::cout << "Hello World!\n";

	Array<int, 20> arrayNumbers;
	Vector<int> vectorNumbers;

	for (size_t i = 0; i < 20; i++)
	{
		arrayNumbers[i] = (rand() % 100) + 1;
		vectorNumbers.PushBack((rand() % 100) + 1);
	}

	std::cout << "Iterate through Array:\n";
	for (Array<int, 20>::Iterator it = arrayNumbers.Begin(); it!= arrayNumbers.End(); ++it)
	{
		std::cout << (*it) << " ";
	}

	std::cout << "\n\n";
	std::cout << "Iterate through Vector:\n";
	for (Vector<int>::Iterator it = vectorNumbers.Begin(); it != vectorNumbers.End(); ++it)
	{
		std::cout << (*it) << " ";
	}
	std::cout << "\n";


	return 0;
}