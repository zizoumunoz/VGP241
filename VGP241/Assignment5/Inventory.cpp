#include "Inventory.h"

void Inventory::pickupKey(const std::string& keyName, int amount)
{
	if (m_keys.Has(keyName))
	{
		m_keys[keyName].add(amount);
	}
	else
	{
		// create new key and insert
		KeyItem newKey(keyName);
		m_keys.Insert(keyName, newKey);
	}
}

void Inventory::useKey(const std::string& keyName, int amount)
{
	m_keys[keyName].consume(amount);
	if (m_keys[keyName].getCount() <= 0)
	{
		m_keys.Remove(keyName);
	}
}
