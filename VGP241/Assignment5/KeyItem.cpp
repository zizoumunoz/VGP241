#include <iostream>
#include "KeyItem.h"

KeyItem::KeyItem()
	: m_name("Default"), m_count(0)
{}

KeyItem::KeyItem(std::string name)
	: m_name(name), m_count(0)
{}

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
