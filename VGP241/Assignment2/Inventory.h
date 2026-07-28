#pragma once
#include <Vector.h>

class Item;
enum ItemType : int;

class Inventory
{
public:
	void Initialize();
	void AddItem(ItemType itemType);
	void DisplayInventory();


private:
	Vector<Item> m_items;


};

