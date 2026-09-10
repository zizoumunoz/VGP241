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


	return 0;
}

