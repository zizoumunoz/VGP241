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

	for (size_t i = 0; i < 4; i++)
	{
		AddItem(static_cast<ItemType>(i));
	}
}

void Inventory::AddItem(ItemType itemType)
{
	for (size_t i = 0; i < m_items.Size(); i++)
	{
		if (m_items[i].GetType() == itemType)
		{
			m_items[i].AddItem();   // increments count
			return;
		}
	}
	// If not found, create a new one
	m_items.PushBack(Item(itemType, 1));

}



void Inventory::DisplayInventory()
{
	PriorityQueue<Item> dispQueue;

	for (size_t i = 0; i < m_items.Size(); i++)
		dispQueue.Push(m_items[i]);

	while (!dispQueue.Empty())
	{
		std::cout << dispQueue.Top().GetName() << ": " << dispQueue.Top().GetCount() << "\n";
		dispQueue.Pop();
	}
}
