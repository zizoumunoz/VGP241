#pragma once
#include <string>
#include <Vector2.h>
namespace a7
{
	class House
	{
	public:
		House() = default;
		House(std::string name, Vector2 position);
		std::string getName() const;
		Vector2 getPos() const;

		bool operator==(const House& other) const;
	private:
		std::string m_name;
		Vector2 m_position;
	};
}

