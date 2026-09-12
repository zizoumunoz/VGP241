#include "City.h"

a8::City::City(std::string name, Vector2 position)
	: m_name(name), m_position(position)
{
}

std::string a8::City::getName()
{
	return m_name;
}

Vector2 a8::City::getPosition()
{
	return m_position;
}
