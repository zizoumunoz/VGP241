#pragma once
#include <string>

namespace a4
{
	class Texture
	{
	public:
		Texture();
		Texture(const std::string& filePath);
		void Print();
	private:
		std::string m_filePath;


	};
}

