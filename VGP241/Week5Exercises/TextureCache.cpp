#include "TextureCache.h"
#include <iostream>

int TextureCache::HashFunction(const std::string& key)
{
	int hashValue = 0;
	for (int i = 0; i < key.size(); ++i)
	{
		int value = (int)key[i];
		hashValue = (hashValue * 256 + value) % MAX_HASH_SIZE;
	}

	return hashValue;
}

void TextureCache::InsertTexture(const std::string& filePath)
{
	int arrayIndex = HashFunction(filePath);
	Node* tmp = m_hashTable[arrayIndex];
	while (tmp != nullptr)
	{
		if (tmp->data->GetFilePath() == filePath)
		{
			std::cout << "Texture " << filePath << " is already added.\n";
			return;
		}
		tmp = tmp->next;
	}
	Texture* newTexture = new Texture();
	newTexture->Initialize(filePath, 100 + (rand() % 157));
	Node* newNode = new Node();
	newNode->data = newTexture;
	newNode->next = m_hashTable[arrayIndex];
	m_hashTable[arrayIndex] = newNode;
}

const Texture* TextureCache::FindTexture(const std::string& filePath)
{
	int arrayIndex = HashFunction(filePath);
	Node* foundNode = m_hashTable[arrayIndex];
	while (foundNode != nullptr)
	{
		if (foundNode->data->GetFilePath() == filePath)
		{
			return foundNode->data;
		}
		foundNode = foundNode->next;
	}
	return nullptr;
}

void TextureCache::DeleteTexture(const std::string& filePath)
{
	int arrayIndex = HashFunction(filePath);
	Node* node = m_hashTable[arrayIndex];
	Node* prev = nullptr;
	while (node != nullptr)
	{
		if (node->data->GetFilePath() == filePath)
		{
			prev->next = node->next;
		}
		else
		{
			m_hashTable[arrayIndex] = node->next;
		}
		std::cout << "Texture " << filePath << " was deleted.\n";
		delete node->data;
		node->data = nullptr;
		delete node;
		node = nullptr;
		break;

		prev = node;
		node = node->next;
	}
}

void TextureCache::PrintTable()
{
	for (int i = 0; i < MAX_HASH_SIZE; ++i)
	{
		Node* node = m_hashTable[i];
		while (node != nullptr)
		{
			std::cout << i << ") " << node->data->GetFilePath() << "\n";
			node = node->next;
		}
	}
}
