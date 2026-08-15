#pragma once
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
	private:
		TextureManager() = default;
		TextureManager(const TextureManager&) = delete;
		TextureManager& operator=(const TextureManager&) = delete;
	};
}

