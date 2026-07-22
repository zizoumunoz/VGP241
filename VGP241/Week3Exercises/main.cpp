#include <iostream>

int RandomNumber(int min, int max)
{
	return min + rand() % (max - min + 1);
}

struct Node
{
	int data = 0;
	Node* next = nullptr;
};

Node* ListAdd(Node* prevNode, int value)
{
	Node* node = new Node();
	node->data = value;

	if (prevNode != nullptr)
	{
		prevNode->next = node;
	}

	return node;
}

void DeleteList(Node* node)
{
	if (node != nullptr)
	{
		DeleteList(node->next);
		delete node;
		node = nullptr;
	}
}

void Exercise1LinkedLists()
{
	std::srand(std::time(0));

	/*
	Create a simple linked list
		Node
			Data
			Next
	Create a couple dozen nodes (20 random numbers 1-100 as nodes, link together)
	How many elements do you have to search to find the target?

	Bonus:
		Randomly link a node to a child and a parent (as long as it doesn't already have one)
		How can you test to see if the linked list has any cyclical loops?
	*/

	int maxNumbers = 20;
	int min = 1;
	int max = 100;

	Node* root = nullptr;
	Node* prevNode = nullptr;

	for (int i = 0; i < maxNumbers; ++i)
	{
		prevNode = ListAdd(prevNode, RandomNumber(min, max));
		if (root == nullptr)
		{
			root = prevNode;
		}
	}
	Node* tmp = root;
	while (tmp != nullptr)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}

	std::cout << "\n\n";
}

int main()
{
	std::cout << "Hello World!\n";
	Exercise1LinkedLists();



}
