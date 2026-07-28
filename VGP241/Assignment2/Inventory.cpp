#include <cstdlib>
#include <ctime>
#include "Inventory.h"
#include "ItemType.h"
#include "Item.h"

void Inventory::Initialize()
{
	srand(time(NULL));
	auto randNum = [](int min, int max) -> int
		{
			return min + rand() % (max - min + 1);
		};

	for (size_t i = 0; i < 10; i++)
	{
		m_items.PushBack(Item(static_cast<ItemType>(randNum(0, 4)), randNum(10, 20)));
	}


}

void Inventory::AddItem(ItemType itemType)
{
	m_items.PushBack(Item(itemType, 1));
}

void Inventory::DisplayInventory()
{
	
}
