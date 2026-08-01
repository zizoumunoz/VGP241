#include <iostream>
#include <Graph.h>

int main()
{
	std::cout << "Hello World!\n";

	Graph<int> myGraph;
	// create data for the graph
	Vector<int> graphData;
	for (int i = 0; i < 10; i++)
	{
		graphData.PushBack(i);
	}
	// add data to the graph
	for (int i = 0; i < graphData.Size(); i++)
	{
		myGraph.AddItem(&graphData[i]);
	}
	// link data together
	myGraph.AddLink(0, 1);
	myGraph.AddLink(0, 2);
	myGraph.AddLink(1, 3);
	myGraph.AddLink(1, 4);
	myGraph.AddLink(2, 5);
	myGraph.AddLink(2, 6);
	myGraph.AddLink(3, 7);
	myGraph.AddLink(4, 8);
	myGraph.AddLink(4, 7);
	myGraph.AddLink(5, 9);
	myGraph.AddLink(0, 9);
	myGraph.PrintGraph();

	Vector<const int*> dfsConnections;
	Vector<const int*> bfsConnections;
	myGraph.GetAllConnectionsBFS(0, bfsConnections);
	myGraph.GetAllConnectionsDFS(0, dfsConnections);

	std::cout << "Connections (DFS):\n";
	for (size_t i = 0; i < dfsConnections.Size(); i++)
	{
		std::cout << (*dfsConnections[i]) << " ";
	}
	std::cout << "\n";
	std::cout << "Connections (BFS):\n";
	for (size_t i = 0; i < bfsConnections.Size(); i++)
	{
		std::cout << (*bfsConnections[i]) << " ";
	}
	std::cout << "\n\n";

}
