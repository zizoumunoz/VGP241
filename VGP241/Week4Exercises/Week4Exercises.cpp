/*
	Createa  console application
		- Ask the user to input the number of vertices to use
		- Ask user to loop edges until they choose done
			- User picks starting index
			- Then user picks connecting index for the edge to link
			- Make sure not linking to itself
		- When done, ask user to pick a starting indices
		- Run both DFS and BFS algorithms and print the nodes the order the nodes were processed
		- Try iterative and recursive versions
		- Confirm if a node is reachable from another node
			- Ask user to input a start node
			- Ask user to input an end node
			- Print the path if reachable
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

void DepthFirstSearch(const std::vector<std::vector<int>>& graph, int startVertex)
{
	std::vector<bool> visited;
	visited.resize(graph.size(), false);

	std::cout << "DFS Print All:\n";
	// dfs uses a stack LIFO
	std::stack<int> process;
	process.push(startVertex);
	while (!process.empty())
	{
		int vertex = process.top();
		process.pop();
		if (!visited[vertex])
		{
			visited[vertex] = true;
			std::cout << vertex << " ";


			for (int i = 0; i < graph[vertex].size(); ++i)
			{
				if (!visited[graph[vertex][i]])
				{
					process.push(graph[vertex][i]);
				}
			}



		}
	}
	std::cout << "\n";
}

void BreadthFirstSearch(const std::vector<std::vector<int>>& graph, int startVertex)
{
	std::vector<bool> visited;
	visited.resize(graph.size(), false);

	std::cout << "BFS Print All:\n";

	// breadth first is a queue, FIFO
	std::queue<int> process;
	process.push(startVertex);
	while (!process.empty())
	{
		int vertex = process.front();
		process.pop();
		if (!visited[vertex])
		{
			visited[vertex] = true;
			std::cout << vertex << " ";
			for (int i = 0; i < graph[vertex].size(); ++i)
			{
				if (!visited[graph[vertex][i]])
				{
					process.push(graph[vertex][i]);
				}
			}
		}
	}
	std::cout << "\n";
}

int main()
{
	std::cout << "Graph Traversal\n";

	int numVertices = 0;
	std::cout << "Number of vertices:\n";
	std::cin >> numVertices;

	// create adjacency matrix
	std::vector<std::vector<int>> adjacencyList;
	adjacencyList.resize(numVertices);

	// target start/end indices
	int inputStart = 0;
	int inputEnd = 0;
	std::cout << "Building Graph: (Connecting Vertices)\n";
	while (true)
	{
		// note for improvement, do while until valid index
		std::cout << "Enter Start Vertex Index:\n";
		std::cin >> inputStart;
		if (inputStart < 0 || inputStart >= numVertices)
		{
			std::cout << "Invalid index [" << inputStart << "] end graph creation\n";
			break;
		}

		std::cout << "Enter End Vertex:\n";
		std::cin >> inputEnd;
		if (inputEnd < 0 || inputEnd >= numVertices)
		{
			std::cout << "Invalid index [" << inputEnd << "] end graph creation\n";
			break;
		}

		// building adjacency list
		// see if start index already connected to end index
		auto iter = std::find(adjacencyList[inputStart].begin(), adjacencyList[inputStart].end(), inputEnd);
		if (iter == adjacencyList[inputStart].end())
		{
			adjacencyList[inputStart].push_back(inputEnd);
		}

		// if one directional graph, exclude the next part, testing with two way graph
		iter = std::find(adjacencyList[inputEnd].begin(), adjacencyList[inputEnd].end(), inputStart);
		if (iter == adjacencyList[inputEnd].end())
		{
			adjacencyList[inputEnd].push_back(inputStart);
		}
	}

	system("cls");
	std::cout << "Print Out Adjacent List:\n";
	for (int v = 0; v < numVertices; ++v)
	{
		std::cout << v << ": { ";
		for (int e = 0; e < adjacencyList[v].size(); ++e)
		{
			std::cout << adjacencyList[v][e] << " ";
		}
		std::cout << "}\n";
	}

	int startVertex = 0;
	std::cout << "Enter a Vertex to Start:\n";
	std::cin >> startVertex;
	DepthFirstSearch(adjacencyList, startVertex);
	BreadthFirstSearch(adjacencyList, startVertex);



	return 0;
}
