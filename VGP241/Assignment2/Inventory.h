#pragma once
#include <Vector.h>
#include "Item.h"
#include "ItemType.h"

class Inventory
{
public:
	void Initialize();
	void AddItem(ItemType itemType);
	void DisplayInventory();


private:
	Vector<Item> m_items;


};

