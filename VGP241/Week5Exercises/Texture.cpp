#include "Texture.h"

Texture::~Texture()
{
	if (m_pixelColors != nullptr)
	{
		delete[] m_pixelColors;
		m_pixelColors = nullptr;
	}
}

void Texture::Initialize(const std::string& filePath, int size)
{
	m_filePath = filePath;
	// (for visualization purpose only)
	// size is width and height, assuming square texture
	// 4 is number of floats (rgba)
	// size of texture is size * size * 4
	m_pixelColors = new float[size * size * 4];
}

const std::string& Texture::GetFilePath() const
{
	return m_filePath;
}