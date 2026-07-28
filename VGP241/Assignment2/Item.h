#pragma once
#include <string>

// forward declaring enum
enum ItemType : int;


class Item
{
public:
	Item(ItemType itemType, int value);

	void ConsumeItem();
	void AddItem();
private:
	ItemType m_type;
	std::string m_name;
	int m_value;
	int m_count;


};

