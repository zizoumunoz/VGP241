#include <iostream>
#include <assert.h>
#include <vector>

struct Node
{
	int data = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

// create node
Node* CreateNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	return newNode;
}

// connect nodes
Node* Insert(Node* node, int data)
{
	if (node == nullptr)
	{
		return CreateNode(data);
	}
	if (data < node->data)
	{
		node->left = Insert(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = Insert(node->right, data);
	}
	else
	{
		assert(false, "Data must be unique.");
	}
	return node;
}

bool Search(Node* node, int data)
{
	if (node == nullptr)
	{
		return false;
	}
	if (node->data == data)
	{
		return true;
	}
	if (data < node->data)
	{
		return Search(node->right, data);
	}
	return Search(node->right, data);
}

Node* GetMinNode(Node* node)
{
	Node* minNode = node;
	while (minNode != nullptr && minNode->left != nullptr)
	{
		minNode = minNode->left;
	}
	return minNode;
}

// get the max node
Node* GetMaxNode(Node* node)
{
	Node* maxNode = node;
	while (maxNode != nullptr && maxNode->right != nullptr)
	{
		maxNode = maxNode->right;
	}
	return maxNode;
}

Node* Delete(Node* node, int data)
{
	if (node == nullptr)
	{
		return node;
	}
	if (data < node->data)
	{
		node->left = Delete(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = Delete(node->right, data);
	}
	// else data == node->data, so delete
	else
	{
		// check to see if the node has any children
		if (node->left == nullptr)
		{
			Node* tmp = node->right;
			delete node;
			node = nullptr;
			return tmp;
		}
		if (node->right == nullptr)
		{
			Node* tmp = node->left;
			delete node;
			node = nullptr;
			return tmp;
		}
		Node* tmp = GetMinNode(node->right);
		node->data = tmp->data;
		node->right = Delete(node->right, tmp->data);
	}
}

// print in order
void PrintInOrder(Node* node)
{
	if (node != nullptr)
	{
		PrintInOrder(node->left);
		std::cout << node->data << " ";
		PrintInOrder(node->right);
	}
}

// print in reverse
void PrintInReverseOrder(Node* node)
{
	if (node != nullptr)
	{
		PrintInReverseOrder(node->right);
		std::cout << node->data << " ";
		PrintInReverseOrder(node->left);
	}
}

int GenerateIPAddress()
{
	int address = 0;
	for (int i = 0; i < 7; i++)
	{
		address = address * 10 + (rand() % 10);
	}
	return address;
}

void Exercise1BST()
{
	// build a binary serarch tree
	// Pass in 100 random 8 digit numbers(e.g. ip address)
	// Add them to the bst
	//  Print them all in order lowest to highest
	// rint them all in reverse order
	// Remove 20
	// print in order and ensure they are all correctdly removed

	std::vector<int> removeDataValues;

	Node* bstRoot = nullptr;
	int maxNumbers = 20;
	for (int i = 0; i < maxNumbers; ++i)
	{
		int  address = GenerateIPAddress();
		bstRoot = Insert(bstRoot, address);
		std::cout << address << " ";
		if (removeDataValues.size() < 5 && rand() % 2 == 0)
		{
			removeDataValues.push_back(address);
		}
	}
	std::cout << "\n\n";
	std::cout << "Print in order:\n";
	PrintInOrder(bstRoot);
	std::cout << "\n\n";
	std::cout << "Print in reverse order:\n";
	PrintInReverseOrder(bstRoot);
	std::cout << "\n\n";
	Node* minNode = GetMinNode(bstRoot);
	Node* maxNode = GetMaxNode(bstRoot);
	std::cout << "Min node value:" << minNode->data << "\n";
	std::cout << "Max node value:" << maxNode->data << "\n";
	std::cout << "\n\n";
	std::cout << "Remove values:\n";
	for (int i = 0; i < removeDataValues.size(); i++)
	{
		int address = removeDataValues[i];
		std::cout << address << "\n";
		bstRoot = Delete(bstRoot, address);
	}
	std::cout << "\n\n";
	std::cout << "Print in order (after delete):\n";
	PrintInOrder(bstRoot);
}


class IPAddress
{
public:
	IPAddress()
	{
		for (int i = 0; i < 4; i++)
		{
			m_address[i] = rand() % 1000;
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const IPAddress& a)
	{
		os << a.m_address[0] << "." << a.m_address[1] << "." << a.m_address[2] << "." << a.m_address[3];
		return os;
	}

	bool operator<(const IPAddress& rhs) const
	{
		for (int i = 0; i < 4; i++)
		{
			if (m_address[i] != rhs.m_address[i])
			{
				return m_address[i] < rhs.m_address[i];
			}
		}
		return false;
	}

	bool operator<=(const IPAddress& rhs) const
	{
		for (int i = 0; i < 4; i++)
		{
			if (m_address[i] != rhs.m_address[i])
			{
				return m_address[i] < rhs.m_address[i];
			}
		}
		return true;
	}

	bool operator==(const IPAddress& rhs) const
	{
		for (int i = 0; i < 4; i++)
		{
			if (m_address[i] != rhs.m_address[i])
			{
				return m_address[i] == rhs.m_address[i];
			}
		}
	}

	bool operator>(const IPAddress& rhs) const
	{
		for (int i = 0; i < 4; i++)
		{
			if (m_address[i] != rhs.m_address[i])
			{
				return m_address[i] > rhs.m_address[i];
			}
		}
		return false;
	}

	bool operator>=(const IPAddress& rhs) const
	{
		for (int i = 0; i < 4; i++)
		{
			if (m_address[i] != rhs.m_address[i])
			{
				return m_address[i] > rhs.m_address[i];
			}
		}
		return true;
	}
private:
	int m_address[4];
};

struct AVLNode
{
	IPAddress data;
	AVLNode* left = nullptr;
	AVLNode* right = nullptr;
	int height = 0;	// height balance tree in the tree
};

AVLNode* CreateAVLNode(const IPAddress& data)
{
	AVLNode* node = new AVLNode();
	node->data = data;
	return node;
}

void PrintInOrder(AVLNode* node)
{
	if (node != nullptr)
	{
		PrintInOrder(node->left);
		std::cout << node->data << "\n";
		PrintInOrder(node->right);

	}
}

void PrintInReverseOrder(AVLNode* node)
{
	if (node != nullptr)
	{
		PrintInReverseOrder(node->right);
		std::cout << node->data << "\n";
		PrintInReverseOrder(node->left);
	}
}

bool Search(AVLNode* node, const IPAddress& data)
{
	if (node == nullptr)
	{
		return false;
	}
	if (node->data == data)
	{
		return true;
	}
	if (data < node->data)
	{
		return Search(node->left, data);
	}
	return Search(node->right, data);
}

AVLNode* GetMinNode(AVLNode* node)
{
	AVLNode* minNode = node;
	while (minNode != nullptr && minNode->left != nullptr)
	{
		minNode = minNode->left;
	}
	return minNode;
}

AVLNode* GetMaxNode(AVLNode* node)
{
	AVLNode* maxNode = node;
	while (maxNode != nullptr && maxNode->right != nullptr)
	{
		maxNode = maxNode->right;
	}
	return maxNode;
}

int NodeHeight(AVLNode* node)
{
	if (node != nullptr)
	{
		return node->height;
	}

	return 0;
}

// balance factor
// the biggest difference in the tree height between both child nodes
// if > 1, the tree needs to be rebalanced
int BalanceFactor(AVLNode* node)
{
	if (node != nullptr)
	{
		// this can be no more than 1 or less than -1
		return NodeHeight(node->left) - NodeHeight(node->right);
	}
	return 0;
}

// rotations
// rotate right
AVLNode* RotateRight(AVLNode* node)
{
	AVLNode* l = node->left;
	AVLNode* tmp = l->right;
	l->right = node;
	node->left = tmp;
	node->height = std::max(NodeHeight(node->left), NodeHeight(node->right)) + 1;
	l->height = std::max(NodeHeight(l->left), NodeHeight(l->right)) + 1;
	return l;
}

// rotate left
AVLNode* RotateLeft(AVLNode* node)
{
	AVLNode* r = node->right;
	AVLNode* tmp = r->left;
	r->left = node;
	node->right = tmp;
	node->height = std::max(NodeHeight(node->left), NodeHeight(node->right)) + 1;
	r->height = std::max(NodeHeight(r->left), NodeHeight(r->right)) + 1;
	return r;
}

AVLNode* Insert(AVLNode* node, const IPAddress& data)
{
	if (node == nullptr)
	{
		return CreateAVLNode(data);
	}
	if (data < node->data)
	{
		node->left = Insert(node->left, data);
	}
	else if (data > node->left->data)
	{
		node->right = Insert(node->right, data);
	}
	else
	{
		assert(false, "Data must be unique");
	}
	// validate balance and rotate if needed
	node->height = std::max(NodeHeight(node->left), NodeHeight(node->right)) + 1;
	int balanceFactor = BalanceFactor(node);
	// Case 1: left is too long
	if (balanceFactor > 1 && data < node->left->data)
	{
		return RotateRight(node);
	}

	// Case 4: right is too long
	if (balanceFactor < -1 && data > node->right->data)
	{
		return RotateLeft(node);
	}
	// next two are double rotations
	// Case 2: right arm of the left side is too long 
	if (balanceFactor > 1 && data > node->left->data)
	{
		// rotate left first
		node->left = RotateLeft(node->left);
		return RotateRight(node);
	}
	// Case 3: left arm of the right side is too long
	if (balanceFactor< -1 && data < node->right->data)
	{
		// rotate right first
		node->right = RotateRight(node->right);
		return RotateLeft(node);
	}
}

AVLNode* Delete(AVLNode* node, const IPAddress& data)
{
	if (node == nullptr)
	{
		return node;
	}
	if (data < node->data)
	{
		node->left = Delete(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = Delete(node->right, data);
	}
	else
	{
		if (node->left == nullptr)
		{
			AVLNode* tmp = node->right;
			delete node;
			node = nullptr;
			return tmp;
		}
		AVLNode* tmp = GetMinNode(node->right);
		node->data = tmp->data;
		node->right = Delete(node->right, node->data);

		// rebalance AVL tree
		node->height = std::max(NodeHeight(node->left), NodeHeight(node->right)) + 1;
		int balanceFactor = BalanceFactor(node);

		if (balanceFactor > 1 && BalanceFactor(node->left) >= 0)
		{
			return RotateRight(node);
		}
		if (balanceFactor < -1 && BalanceFactor(node->right) <= 0)
		{
			return RotateLeft(node);
		}
		if (balanceFactor > 1 && BalanceFactor(node->left) < 0)
		{
			node->left = RotateLeft(node->left);
			return RotateRight(node);
		}
		if (balanceFactor < -1 && BalanceFactor(node->right) > 0)
		{
			node->right = RotateRight(node->right);
			return RotateLeft(node);
		}
	}
}

void Exercise2AVLTree()
{
	// Modify the binary search tree to self - balance itself
	//	Making it an AVL tree
	// Create a class for "Ip address"
	// store an array of 4 ints
	//		Each int can be 0 - 999
	//		Needs compare operators for <, <=, ==, >, and >=
	//		Needs a print to pritn the array "array[0].array[1].array[2].array[3]"
	// Pass in 20 random ip addresses
	//		Throw an error if there are duplicates
	// Add them to the AVL
	// Print them all in order lowest to highest
	// Print them in reverse order
	// Remove 5
	// Print in order and ensure they are all correctdly removed

	std::cout << "AVL Tree:\n";
	std::vector<IPAddress> addresses;
	AVLNode* avlTree = nullptr;
	int maxAddresses = 20;
	for (int i = 0; i < maxAddresses; ++i)
	{
		IPAddress newAddress;
		addresses.push_back(newAddress);
		avlTree = Insert(avlTree, newAddress);
		std::cout << newAddress << "\n";
	}
	std::cout << "\n";
	std::cout << "Print in order:\n";
	PrintInOrder(avlTree);
	std::cout << "\n\n";
	std::cout << "Print in reverse order\n";
	PrintInReverseOrder(avlTree);
	std::cout << "\n\n";

	AVLNode* minNode = GetMinNode(avlTree);
	AVLNode* maxNode = GetMaxNode(avlTree);
	std::cout << "Min node: " << minNode->data << "\n";
	std::cout << "Max Node: " << maxNode->data << "\n";
	std::cout << "\n\n";

	std::cout << "Remove values:\n";
	for (int i = 0; i < 5; ++i)
	{
		int index = rand() & addresses.size();
		avlTree = Delete(avlTree, addresses[index]);
		std::cout << "Deleted: " << addresses[index] << "\n";
		addresses.erase(addresses.begin() + index);
	}
	std::cout << "\n\n";
	PrintInOrder(avlTree);
	std::cout << "\n\n";
}

int main()
{
	std::cout << "Hello World!\n";
	Exercise2AVLTree();
}