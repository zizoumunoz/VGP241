#include <iostream>
#include "KeyItem.h"

void KeyItem::add(int amount)
{
	++m_count;
}

void KeyItem::consume(int amount)
{
	--m_count;
}

int KeyItem::getCount()
{
	return m_count;
}

void KeyItem::print()
{
	std::cout << m_name << ": " << m_count;
}
