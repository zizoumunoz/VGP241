#include <iostream>
#include "Item.h"
#include "ItemType.h"

Item::Item(ItemType itemType, int value)
	: m_type(itemType), m_value(value), m_count(1)
{
	switch (m_type)
	{
	case SmallHealth:
		m_name = "Small Health Potion";
		break;
	case MedHealth:
		m_name = "Medium Health Potion";
		break;
	case LightningSpell:
		m_name = "Lightning Spell";
		break;
	case Grenade:
		m_name = "Grenade";
		break;
	default:
		m_name = "Error: No name";
		break;
	}
}

void Item::ConsumeItem()
{
	if (m_count > 0)
	{
		--m_count;
		std::cout << m_name << ": " << m_value << "\n";

	}
	else
	{
		std::cout << "The item does not have any to consume.\n";
	}

}

void Item::AddItem()
{
	++m_count;
	std::cout << m_name << ": " << m_count << "\n";
}

int Item::GetCount() const
{
	return m_count;
}

std::string Item::GetName() const
{
	return m_name;
}

ItemType Item::GetType() const
{
	return m_type;
}

bool Item::operator<(const Item& other) const
{
	return m_count < other.m_count;
}
