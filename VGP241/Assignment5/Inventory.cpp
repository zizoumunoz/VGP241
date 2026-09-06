#include "Inventory.h"

void Inventory::pickupKey(const std::string& keyName, int amount)
{
	// check if key in map
	bool isInMap = m_keys.Has(keyName);
	
	if (isInMap)
	{
		m_keys[keyName].add(amount);
	}
	else
	{
		m_keys.Insert(keyName, KeyItem{keyName});
	}

}

