#include "TextureManager.h"
#include <Global.h>

size_t a4::TextureManager::LoadTexture(const std::string& filePath)
{
	size_t uniqueId = Global::HashFunction(filePath);
	m_textures.Insert(uniqueId, filePath);
	return uniqueId;
}

a4::Texture& a4::TextureManager::GetTexture(size_t id)
{
	return m_textures[id];
}


