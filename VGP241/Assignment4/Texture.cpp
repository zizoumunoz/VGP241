#include "Texture.h"
#include <iostream>

a4::Texture::Texture()
{

}

a4::Texture::Texture(const std::string& filePath)
{
}

void a4::Texture::Print()
{
	std::cout << "Rendering: <" << m_filePath << ">:\n";	
}
