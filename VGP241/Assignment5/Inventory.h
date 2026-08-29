#pragma once
#include <Map.h>
#include "KeyItem.h"
class Inventory
{
public:
	static Inventory& Instance()
	{
		static Inventory instance; 
		return instance;
	}

	// singleton stuff
	Inventory() = default;
	~Inventory() = default;
	Inventory(const Inventory&) = delete;
	Inventory& operator=(const Inventory&) = delete;

	/// <summary>
	/// 1. Checks to see if key is in map.
	/// 2. If not on map, creates a new key and adds it to the map
	/// 3. Increments the count by the amount.
	/// </summary>
	void pickupKey(const std::string& keyName, int amount);


private:
	Map<std::string, KeyItem> m_keys;

};

