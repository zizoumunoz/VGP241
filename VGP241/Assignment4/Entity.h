#pragma once
#include <Vector2.h>
#include <string>
namespace a4
{
	class Entity
	{
	public:
		void initialize(const std::string& textureFilePath);
	private:
		size_t m_textureId;
		Vector2 m_position;

		
	};
}
