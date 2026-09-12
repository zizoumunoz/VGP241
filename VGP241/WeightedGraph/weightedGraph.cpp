
#include <iostream>
#include <WeightedGraph.h>

int GetIndex(const Vector<std::string>& nodes, const std::string& input)
{
	for (size_t i = 0; i < nodes.Size(); i++)
	{
		if (nodes[i] == input)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	std::cout << "Custom Weighted Graph\n";

	Vector<std::string> nodes;
	nodes.PushBack("A");
	nodes.PushBack("B");
	nodes.PushBack("C");
	nodes.PushBack("D");
	nodes.PushBack("E");

	WeightedGraph<std::string, int> nodeGraph;
	for (size_t i = 0; i < nodes.Size(); i++)
	{
		nodeGraph.AddItem(&nodes[i]);
	}

	nodeGraph.AddEdge(0, 1, 9);	// A - B
	nodeGraph.AddEdge(0, 2, 5);	// A - C
	nodeGraph.AddEdge(0, 3, 2);	// A - D
	nodeGraph.AddEdge(1, 3, 6);	// B - D
	nodeGraph.AddEdge(1, 4, 5);	// B - E
	nodeGraph.AddEdge(2, 3, 4); // C - D
	nodeGraph.AddEdge(2, 4, 5); // C - E
	nodeGraph.AddEdge(3, 4, 4); // D - E

	std::string input;
	int startIndex = -1;
	int endIndex = -1;
	bool done = false;
	while (!done)
	{
		system("cls");
		std::cout << "Enter start point (A-E): ";
		std::cin >> input;
		startIndex = GetIndex(nodes, input);
		if (startIndex < 0)
		{
			done = input == "done";
			std::cout << "Invalid Input [" << input << "]\n";
			std::cout << "Try again\n";
			system("pause");
			continue;
		}
		std::cout << "Enter end point (A-E): ";
		std::cin >> input;
		endIndex = GetIndex(nodes, input);
		if (endIndex < 0 || endIndex == startIndex)
		{
			done = input == "done";
			std::cout << "Invalid input [" << input << "]\n";
			std::cout << "Try again\n";
			system("pause");
			continue;
		}

		Vector<const std::string*> path;
		int totalWeight = nodeGraph.GetPath(startIndex, endIndex, path);
		if (path.Size() == 0)
		{
			std::cout << "No path was found from [" << nodes[startIndex] << "-" << nodes[endIndex] << "]\n";
			system("pause");
			continue;
		}
		std::cout << "Path from [" << nodes[startIndex] << "-" << nodes[endIndex] << "]\n";
		for (size_t i = 0; i < path.Size(); i++)
		{
			std::cout << (*path[i]) << " ";
		}
		std::cout << "\n";
		std::cout << "Total weight: " << totalWeight << "\n";
		system("pause");

	}
}