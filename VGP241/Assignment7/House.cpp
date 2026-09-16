#include "House.h"

a7::House::House(std::string name, Vector2 position)
	: m_name(name), m_position(position)
{}

std::string a7::House::getName() const
{
	return m_name;
}

Vector2 a7::House::getPos() const
{
	return Vector2();
}

bool a7::House::operator==(const House& other) const
{
	return m_name == other.getName() &&
		other.getPos().x == m_position.x &&
		other.getPos().y == m_position.y;
}
