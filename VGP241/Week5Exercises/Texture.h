#pragma once
#include <string>
class Texture
{
public:
	Texture() : m_pixelColors(nullptr) {}
	~Texture();

	// Simulation loading in a texture
	void Initialize(const std::string& filePath, int size);

	const std::string& GetFilePath() const;

private:
	std::string m_filePath;
	float* m_pixelColors = nullptr;
};

