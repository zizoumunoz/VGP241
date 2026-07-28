#include <cstdlib>
#include <ctime>
#include <PriorityQueue.h>
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
		m_items.PushBack(Item(static_cast<ItemType>(randNum(0, 3)), randNum(10, 20)));
	}


}

void Inventory::AddItem(ItemType itemType)
{
	m_items.PushBack(Item(itemType, 1));
}

void Inventory::DisplayInventory()
{
	PriorityQueue<Item> dispQueue;
	for (size_t i = 0; i < m_items.Size(); i++)
	{
		dispQueue.Push(m_items[i]);
	}

	for (size_t i = 0; i < dispQueue.Size(); i++)
	{
		std::cout << dispQueue.Top().GetName() << ": " << dispQueue.Top().GetCount() << "\n";
		dispQueue.Pop();
	}
}
