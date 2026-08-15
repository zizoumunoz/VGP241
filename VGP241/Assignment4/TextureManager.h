#pragma once
#include <string>

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
	private:
		TextureManager() = default;
		TextureManager(const TextureManager&) = delete;
		TextureManager& operator=(const TextureManager&) = delete;
	};
}

