#pragma once
#include <string>

// forward declaring enum
enum ItemType : int;


class Item
{
public:
	Item() = default;
	Item(ItemType itemType, int value);
	void ConsumeItem();
	void AddItem();

	int GetCount() const;
	std::string GetName() const;
	ItemType GetType() const;

	bool operator<(const Item& other) const;
private:
	ItemType m_type;
	std::string m_name;
	int m_value;
	int m_count;


};

