#pragma once
#include <string>
#include <UnorderedMap.h>
#include "Texture.h"

namespace a4
{
	class TextureManager
	{
	public:
		static TextureManager& Instance()
		{
			static TextureManager instance;
			return instance;
		}

		size_t LoadTexture(const std::string& filePath);
		Texture& GetTexture(size_t id);

	private:
		// Singleton stuff
		TextureManager() = default;
		TextureManager(const TextureManager&) = delete;
		TextureManager& operator=(const TextureManager&) = delete;

		// members
		UnorderedMap<size_t, Texture> m_textures;
	};
}
