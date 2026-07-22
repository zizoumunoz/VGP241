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

bool IsLinkedListClyclical(Node* root)
{
	Node* slowNode = nullptr;
	Node* fastNode = nullptr;

	while (slowNode != nullptr && fastNode != nullptr && fastNode->next != nullptr)
	{
		slowNode = slowNode->next;
		fastNode = fastNode->next->next;
		if (slowNode == fastNode)
		{
			return true; // this is cyclical
		}
	}
	return false;

	// if at any point both nodes equal each other then we know it's cyclical
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

	// print list

	Node* tmp = root;
	while (tmp != nullptr)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}

	std::cout << "\n\n";

	// print cyclical
	std::cout << "Is list cyclical: " << IsLinkedListClyclical(root) << "\n";

	DeleteList(root);
}

void Exercise2KDTree()
{
	/*
	Try building the example with a 2 dimensional array(x, y)
	Create random 20 positions between 0 and 100
	Print the numbers as they are added
	Print the height of the tree
	Print the items in the range of (20, 20) - (60, 60)
	Find the closes neighbor to (37, 65)
	Bonus make a 3 dimensional array (x, y, z)
		Find items in range (20, 20, 20) - (60, 60, 20)
		Find the closes neighbor to 37, 65, 43)
	*/
}


int main()
{
	std::cout << "Hello World!\n";
	Exercise1LinkedLists();



}
