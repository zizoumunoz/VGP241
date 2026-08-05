#include <iostream>
#include <vector>
#include <functional>
#include <queue>

void Exercise1()
{
	// Create a function of complexity
	// O(1)
	//std::cout << sum(1, 2);

	// O(n)


	// O(log n)
}

// O(1) 
int sum(int x, int y)
{
	return x + y;
}

// O(n)
void plusOneArr(std::vector<int>& nums)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		++nums[i];
	}
}

// O(log n)
float normalizeOne(float x)
{
	if (x > 1)
	{
		return x;
	}

	while (x < 1)
	{
		x *= 2;
	}

	return x;

}



void vecIndexing(std::vector<int>& nums)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << "\n";
}

void vecIter(std::vector<int>& nums)
{
	for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

void vecRecurs(std::vector<int>& nums, int index = 0)
{
	if (index < nums.size())
	{
		std::cout << nums[index] << " ";
		vecRecurs(nums, index + 1);
	}
}

void Exercise2()
{
	// Create a vector ints
	// Add 10 random numbers
	std::vector<int> numbers;

	for (size_t i = 0; i < 10; i++)
	{
		numbers.push_back(rand());
	}

	// Create func that prints the values indexing through thte vector

	// Create a func that prints the values iterating through the vector

	// Create ae function that prints the values using a recursive function
	vecRecurs(numbers, 0);
}


class House
{
public:
	int price = 0;
	int squareFoot = 0;
	int rooms = 0;
	int distance = 0;



	House(int price, int squareFoot, int rooms, int distance)
		: price(price), squareFoot(squareFoot), rooms(rooms), distance(distance)
	{
	}

	void print() const
	{
		std::cout << "$" << price << "\n"
			<< squareFoot << "ft\n"
			<< "Rooms: " << rooms << "\n"
			<< "Distance: " << distance << "\n";
	}
};

using SortCallback = std::function<bool(const House&, const House&)>;
class HouseListings
{
public:
	void listHouse(const House& house)
	{
		m_houses.push_back(house);
	}
	void printWithCriteria(SortCallback comp) const
	{
		std::priority_queue<House, std::vector<House>, SortCallback> pq(comp);

		for (const auto& house : m_houses)
		{
			pq.push(house);
		}

		while (!pq.empty())
		{
			pq.top().print();
			pq.pop();

		}
	}

private:
	std::vector<House> m_houses;

};

void Exercise3()
{
	/*
	Create a class called house
		int price
		int square foot
		int rooms
		int distance
	Create a class HouseListings
		std::vector<house> mHouses;
		void listHouse(const house & house)
		void printWithCriteria(sortCallbackFunction()
			Prints the houses in the order stated by the callback
			adds houses to a prio queue and prints the list
		Add 20 houses sort price square foot distance


		*/

	HouseListings listings;

	listings.listHouse(House(350000, 1500, 3, 12));
	listings.listHouse(House(500000, 2200, 4, 5));
	listings.listHouse(House(250000, 1100, 2, 25));
	listings.listHouse(House(750000, 3100, 5, 2));
	listings.listHouse(House(420000, 1800, 3, 15));

	std::cout << "\nSorted by price:\n";

	listings.printWithCriteria([](const House& a, const House& b) {	return a.price > b.price; });

	std::cout << "\nSorted by footage:\n";

	listings.printWithCriteria([](const House& a, const House& b) {	return a.squareFoot > b.squareFoot; });

	std::cout << "\nSorted by distance:\n";

	listings.printWithCriteria([](const House& a, const House& b) {	return a.distance > b.distance; });

	std::cout << "\nSorted by rooms:\n";

	listings.printWithCriteria([](const House& a, const House& b) {	return a.rooms > b.rooms; });
}

struct Node
{
	std::string data;
	bool visited = false;
	const Node* fromNode = nullptr;
	std::vector<Node*> edges;
};

class Graph
{
public:
	void CreateGraph(int width, int height)
	{

	}

	void PrintPathDFS(int startIndex, int endIndex) {}
	void PrintPathBFS(int startIndex, int endIndex) {}
	void Reset() {}
};



void Exercise4()
{
	// Create a simple console app that asks a user to input a width and height
	// Create a "Node" struct that has a string data value and a vector of nodes called "edges"
	// Create a "Graph" class that contains a vector of Nodes
	// Build the Graph with the width and height given
	// All nodes will have their neighbors as the index next to them
	//	Tip if you add link for index + 1, also add the current node as a neighbor to the next node
	// Pick two locations within the grid
	// Print the BFS path and print the DFS path
}

int main()
{
	Exercise3();
}