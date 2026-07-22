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

// KDTree ================================================================================
struct Vector2
{
	int x = 0;
	int y = 0;
};

struct KDNode
{
	Vector2 data;
	KDNode* left = nullptr;
	KDNode* right = nullptr;
};

// print tree
void PrintDataAtHeightLevel(KDNode* node, int height, const std::string& side)
{
	if (node == nullptr)
	{
		return;
	}
	if (height == 0)
	{
		std::cout << side << " (" << node->data.x << ", " << node->data.y << ") ";
	}
	else
	{
		PrintDataAtHeightLevel(node->left, height - 1, "L");
		std::cout << "    ";
		PrintDataAtHeightLevel(node->right, height - 1, "R");
		if (height == 1)
		{
			std::cout << " ";
		}
	}
}

void PrintTree(KDNode* tree)
{
	std::cout << "\n\n\nPrinting Tree:\n";
	for (int i = 0; i < 30; ++i)
	{
		PrintDataAtHeightLevel(tree, i, "ROOT");
		std::cout << "\n";
	}
}

// Recursively remove all the nodes in the KD Tree
void DeleteKDTree(KDNode* node)
{
	if (node != nullptr)
	{
		DeleteKDTree(node->left);
		DeleteKDTree(node->right);
		delete node;
		node = nullptr;
	}
}

// dim is the level/current height we are at in the tree (start at 0, goes to number of k elements, then repeats)
KDNode* Insert(const Vector2& data, KDNode* prevNode, int dim)
{
	if (prevNode == nullptr)
	{
		KDNode* node = new KDNode();
		node->data = data;
		return node;
	}

	if (prevNode->data.x == data.x && prevNode->data.y == data.y)
	{
		std::cout << "ERROR: Node as already been added!!!\n";
	}

	const int maxDimensions = 2;	// "(x, y)"
	int nextDim = ((dim + 1) % maxDimensions);
	// compare based on current dimension
	if (dim == 0) // since we are vecor2, layer - compares the x value
	{
		// Compare new data with prevNode data, only compare the x
		// if the new data.x is less than prevNode->data.x, data
		// data is inserted to the left
		if (data.x < prevNode->data.x)
		{
			prevNode->left = Insert(data, prevNode->left, nextDim);
		}
		else
		{
			prevNode->right = Insert(data, prevNode->right, nextDim);
		}
	}
	else if (dim == 1)	// layer 1 compares the y value
	{
		if (data.y < prevNode->data.y)
		{
			prevNode->left = Insert(data, prevNode->left, nextDim);
		}
		else
		{
			prevNode->right = Insert(data, prevNode->right, nextDim);
		}
	}
	else
	{
		std::cout << "ERROR: dimension is not set";
	}
	return prevNode;

}
// deelte node
KDNode* Delete(const Vector2& data, KDNode* node, int dim)
{
	if (node == nullptr)
	{
		std::cout << "[ERROR] Node was not found with (" << data.x << ", " << data.y << ")\n";
		return;
	}

	// we found the node
	if (data.x == node->data.x && data.y == node->data.y)
	{
		node->data = ;
	}
}


// find min (dim = dimension we're looking for, cd = current dimension)

Vector2 Minimum(const Vector2& a, const Vector2& b, const Vector2& c, int dim)
{
	int aDimValue = (dim == 0) ? a.x : a.y;
	int bDimValue = (dim == 0) ? b.x : b.y;
	int cDimValue = (dim == 0) ? c.x : c.y;
	if (aDimValue < bDimValue && aDimValue < cDimValue)
	{
		return a;
	}
	if (bDimValue < aDimValue && bDimValue < cDimValue)
	{
		return b;
	}
	return c;
}

Vector2 FindMin(KDNode* node, int dim, int cd)
{
	if (node)
	{
		Vector2 invalid;
		invalid.x = INT_MAX;
		invalid.y = INT_MAX;
		std::cout << "[ERROR] invalid min value\n";
		return invalid;
	}
	int nextCD = (cd + 1) % 2;
	// if current dimensoin is dimension youre looking for
	if (cd = dim)
	{
		// if furthest left, we are smallest, return data
		if (node->left == nullptr)
		{
			return node->data;
		}
		// otherwise keep looking left
		return FindMin(node->left, dim, nextCD);
	}
	// if current dimension is not desired dimension, need to find smallest in both trees

}

// find range


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

	int maxNumbers = 20;
	int min = 1;
	int max = 100;
	KDNode* root = nullptr;
	Vector2 data;
	for (int i = 0; i < maxNumbers; ++i)
	{
		data.x = RandomNumber(min, max);
		data.y = RandomNumber(min, max);
		KDNode* newNode = Insert(data, root, 0);
		if (root == nullptr)
		{
			root = newNode;
		}
		std::cout << "(" << data.x << ", " << data.y << ") ";
	}

	std::cout << "\n\n\n";
	PrintTree(root);
}


int main()
{
	std::cout << "Hello World!\n";
	Exercise1LinkedLists();
	Exercise2KDTree();



}
