#include <iostream>
#include <Vector.h>
#include "Inventory.h"

int main()
{
	srand(time(NULL));

	Inventory inv;

	Vector<std::string> keyNames;

	// 20 random keynames 
	keyNames.PushBack("Pigs");
	keyNames.PushBack("Dogs");
	keyNames.PushBack("Cat");
	keyNames.PushBack("Mint");
	keyNames.PushBack("Cookie");
	keyNames.PushBack("Pie");
	keyNames.PushBack("Teeth");
	keyNames.PushBack("Rat");
	keyNames.PushBack("Mouse");
	keyNames.PushBack("Band");
	keyNames.PushBack("Girl");
	keyNames.PushBack("Boy");
	keyNames.PushBack("Letter");
	keyNames.PushBack("Word");
	keyNames.PushBack("Music");
	keyNames.PushBack("Plays");
	keyNames.PushBack("Thread");
	keyNames.PushBack("Jog");
	keyNames.PushBack("Runner");
	keyNames.PushBack("Nasty");

	for (size_t i = 0; i < 100; i++)
	{
		int randNum = rand() % 20;
		inv.pickupKey(keyNames[randNum], 0);
	}

	Vector<std::string> allKeys;
	inv.m_keys.ObtainKeys(allKeys);
	// 3d. obtain all keys and print
	for (size_t i = 0; i < allKeys.Size(); i++)
	{
		std::cout << allKeys[i] << "\n";
	}

	std::cout << "Sample Loop:\n\n";
	std::string input;
	while (true)
	{
		std::cout << "Options:\n"
			<< "(1) Open door\n"
			<< "(2) Obtain Key\n"
			<< "(3) Exit\n"
			<< "Enter selection: ";
		std::cin >> input;
		std::system("cls");

		if (input == "1")
		{
			std::string neededKey = keyNames[rand() % keyNames.Size()];
			std::cout << "You arrive at a door and need a " << neededKey<< "\n";

			if (inv.m_keys[neededKey].getCount() > 0)
			{
				std::cout << "You have the key! The door opens.\n";
				inv.useKey(neededKey, 1);
				std::cout << "You now have " << inv.m_keys[neededKey].getCount() << " " << neededKey
					<< "\n";
			}
			else
			{
				std::cout << "You do not have the key. The door remains locked\n";
			}
		}
		else if (input == "2")
		{
			std::string pickedKey = keyNames[rand() % keyNames.Size()];
			inv.pickupKey(pickedKey, 1);
			std::cout << "You pick up key " << pickedKey << ". New count: \n" 
				<< inv.m_keys[pickedKey].getCount() << "\n";
		}
		else if (input == "3")
		{
			Vector<std::string> invKeys;
			inv.m_keys.ObtainKeys(invKeys);
			std::cout << "All keys in inventory:\n";
			for (size_t i = 0; i < invKeys.Size(); i++)
			{
				std::cout << invKeys[i] << " ";
			}
			std::cout << "\n";
			break;
		}

	}
	std::cout << "Exiting program...\n";

	return 0;
}

