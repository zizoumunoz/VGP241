#pragma once
#include <Vector2.h>
#include <string>
namespace a4
{
	class Entity
	{
	public:
		Entity();
		~Entity() = default;
		void initialize(const std::string& textureFilePath);
		void update();
		void render();
	private:
		size_t m_textureId;
		Vector2 m_position;
	};
}
