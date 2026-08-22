#include "Entity.h"
#include "TextureManager.h"
#include <iostream>


void a4::Entity::initialize(const std::string& textureFilePath)
{
	m_textureId = TextureManager::Instance().LoadTexture(textureFilePath);
	m_position.x = rand() % (200 - (-200) + 1) - 200;
	m_position.y = rand() % (200 - (-200) + 1) - 200;
}

void a4::Entity::update()
{
	m_position.x = rand() % (200 - (-200) + 1) - 200;
	m_position.y = rand() % (200 - (-200) + 1) - 200;
}

void a4::Entity::render()
{
	TextureManager::Instance().GetTexture(m_textureId);
	std::cout << "Position: " << m_position.x << ", " << m_position.y << "\n";
}

size_t a4::Entity::getTexture()
{
	return m_textureId;
}
