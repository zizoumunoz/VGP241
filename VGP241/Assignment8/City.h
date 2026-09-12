#pragma once
#include <string>
#include <Vector2.h>
namespace a8
{
	class City
	{
	public:
		City()  = default;
		City(std::string name, Vector2 position);
		std::string getName();
		Vector2 getPosition();

	private:
		std::string m_name;
		Vector2 m_position;
	};
}

