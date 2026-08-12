#pragma once
#include <array>
#include "Texture.h"

// Has table array that will store the textures
class TextureCache
{
public:

	int HashFunction(const std::string& key);
	void InsertTexture(const std::string& filePath);
	const Texture* FindTexture(const std::string& filePath);
	void DeleteTexture(const std::string& filePath);
	void PrintTable();

// Declaring private data that functions would use later (if we use a cpp file, can move everything to bottom
private:
	static const int MAX_HASH_SIZE = 1000;	// max elements in hash table
	struct Node
	{
		Texture* data = nullptr;
		Node* next = nullptr;	// This is used to help with collisions
	};
	std::array<Node*, MAX_HASH_SIZE> m_hashTable = { nullptr };

};

