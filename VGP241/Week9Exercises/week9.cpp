#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

struct Node
{
	int nodeIndex = -1;
	int weight = -1;
};

struct Edge
{
	int nodeIndex = -1;	// main node index
	int toIndex = -1;	// linked index
	int weight = -1;	// weight/cost/value ... of the edge
};


void DFS(const std::vector<std::vector<Node>>& graph, int startNode)
{
	int totalWeight = 0;

	// initializing a vector with an int called "Resize
	std::vector<bool> visited(graph.size(), false);
	std::vector<int> key(graph.size(), INT_MAX);

	std::cout << "DFS:\n";
	std::stack<int> process;
	key[startNode] = 0;
	process.push(startNode);
	while (!process.empty())
	{
		int nodeIndex = process.top();
		process.pop();
		if (!visited[nodeIndex])
		{
			visited[nodeIndex] = true;
			totalWeight += key[nodeIndex];
			std::cout << nodeIndex << " ";
			for (int i = 0; i < graph[nodeIndex].size(); ++i)
			{
				const Node& node = graph[nodeIndex][i];
				if (!visited[node.nodeIndex])
				{
					key[node.nodeIndex] = node.weight;
					process.push(node.nodeIndex);
				}
			}
		}
	}
	std::cout << "\n";
	std::cout << "Total Weight DFS: " << totalWeight << "\n";
}
void BFS(const std::vector<std::vector<Node>>& graph, int startNode)
{
	int totalWeight = 0;
	// initializing a vector with an int called "Resize
	std::vector<bool> visited(graph.size(), false);
	std::vector<int> key(graph.size(), INT_MAX);

	std::cout << "BFS:\n";
	std::queue<int> process;
	key[startNode] = 0;
	process.push(startNode);
	while (!process.empty())
	{
		int nodeIndex = process.front();
		process.pop();
		if (!visited[nodeIndex])
		{
			visited[nodeIndex] = true;
			std::cout << nodeIndex << " ";
			totalWeight += key[nodeIndex];
			for (int i = 0; i < graph[nodeIndex].size(); ++i)
			{
				const Node& node = graph[nodeIndex][i];
				if (!visited[node.nodeIndex])
				{
					key[node.nodeIndex] = node.weight;
					process.push(node.nodeIndex);
				}
			}
		}
	}

	std::cout << "\n";
	std::cout << "Total Weight BFS: " << totalWeight << "\n";

}

struct CompareWeight
{
	bool operator()(const Node& a, const Node& b)
	{
		return b.weight < a.weight;
	}
};

void PrimsAlgorithm(const std::vector<std::vector<Node>>& graph, int startIndex)
{
	int totalWeight = 0;
	std::vector<bool> visited(graph.size(), false);
	std::vector<int> key(graph.size(), INT_MAX);

	std::cout << "Prims algorithm:\n";
	// store in a priority queue based on the accumulated weight
	std::priority_queue<Node, std::vector<Node>, CompareWeight> process;

	// starting value is 0
	key[startIndex] = 0;
	process.push({ startIndex, 0 });
	while (!process.empty())
	{
		// same as BFS, using a queue to get the top
		// in this case the queue is prioritied by accumulated weight
		Node node = process.top();
		process.pop();
		if (!visited[node.nodeIndex])
		{
			visited[node.nodeIndex] = true;
			totalWeight += key[node.nodeIndex];
			std::cout << node.nodeIndex << " ";
			for (int i = 0; i < graph[node.nodeIndex].size(); ++i)
			{
				// go through all the neighbors
				// check to see if they are visited
				// AND if weight to this node is shorteter than current total weight
				const Node& neighbor = graph[node.nodeIndex][i];
				if (!visited[neighbor.nodeIndex] && neighbor.weight < key[neighbor.nodeIndex])
				{
					key[neighbor.nodeIndex] = neighbor.weight;
					process.push({ neighbor.nodeIndex, key[neighbor.nodeIndex] });
				}
			}
		}
	}
	std::cout << "\n";
	std::cout << "Total Tree Weight: " << totalWeight << "\n";
}

void AddLink(std::vector<Node>& neighbors, int linkedIndex, int weight)
{
	auto iter = std::find_if(neighbors.begin(), neighbors.end(),
		[linkedIndex](const Node& n)
		{
			return n.nodeIndex == linkedIndex;
		});
	if (iter == neighbors.end())
	{
		Node newNeighbor;
		newNeighbor.nodeIndex = linkedIndex;
		newNeighbor.weight = weight;
		neighbors.push_back(newNeighbor);
	}
}

void AddLinkedPair(std::vector<std::vector<Node>>& graph, int node, int linkedNeighbor, int weight = 0)
{
	AddLink(graph[node], linkedNeighbor, weight);
	AddLink(graph[linkedNeighbor], node, weight);
}


void Exercise1Review()
{
	// Rebuild DFS and BFS search algorithms
	// Build a simple adjacency graph (with KeyNode)
	// Use diagram as example
	std::cout << "Review DFS and BFS:\n";

	//a, b, c, d, e
	//0, 1, 2, 3, 4
	std::vector<std::vector<Node>> adjacencyList;
	adjacencyList.resize(5);
	AddLinkedPair(adjacencyList, 0, 1);	// a, b
	AddLinkedPair(adjacencyList, 0, 2);	// a, c
	AddLinkedPair(adjacencyList, 0, 3); // 
	AddLinkedPair(adjacencyList, 1, 3); // 
	AddLinkedPair(adjacencyList, 1, 4); // 
	AddLinkedPair(adjacencyList, 2, 3); // 
	AddLinkedPair(adjacencyList, 2, 4); // 
	AddLinkedPair(adjacencyList, 3, 4); // 

	int startNode = 0;
	DFS(adjacencyList, startNode);
	BFS(adjacencyList, startNode);
}

void Exercise2Review()
{
	std::vector<std::vector<Node>> adjacencyList;
	adjacencyList.resize(5);
	AddLinkedPair(adjacencyList, 0, 1, 9);	// a, b
	AddLinkedPair(adjacencyList, 0, 2, 5);	// a, c
	AddLinkedPair(adjacencyList, 0, 3, 2); // 
	AddLinkedPair(adjacencyList, 1, 3, 6); // 
	AddLinkedPair(adjacencyList, 1, 4, 5); // 
	AddLinkedPair(adjacencyList, 2, 3, 4); // 
	AddLinkedPair(adjacencyList, 2, 4, 5); // 
	AddLinkedPair(adjacencyList, 3, 4, 4); // 

	int startIndex = 4;
	PrimsAlgorithm(adjacencyList, startIndex);
	DFS(adjacencyList, startIndex);
	BFS(adjacencyList, startIndex);
}

void AddEdge(std::vector<Edge>& edges, int nodeIndex, int toIndex, int weight)
{
	Edge newEdge;
	newEdge.nodeIndex = nodeIndex;
	newEdge.toIndex = toIndex;
	newEdge.weight = weight;
	edges.push_back(newEdge);
}

// links the edges together for MST
class DisjointSetUnion
{
public:
	DisjointSetUnion(int numNodes)
	{
		m_parent.resize(numNodes);
		m_rank.resize(numNodes);
		for (int i = 0; i < numNodes; i++)
		{
			m_parent[i] = i;
		}
	}
	int FindParent(int nodeIndex)
	{
		if (m_parent[nodeIndex] != nodeIndex)
		{
			m_parent[nodeIndex] = FindParent(m_parent[nodeIndex]);
		}
		return m_parent[nodeIndex];
	}
	bool UniteEdge(int start, int end)
	{
		int rootStart = FindParent(start);
		int rootEnd = FindParent(end);
		if (rootStart == rootEnd)
		{
			return false; // already in same set
		}
		// union by rank
		if (m_rank[rootStart] < m_rank[rootEnd])
		{
			m_parent[rootStart] = rootEnd;
		}
		else if (m_rank[rootStart] > m_rank[rootEnd])
		{
			m_parent[rootEnd] = rootStart;
		}
		else
		{
			m_parent[rootEnd] = rootStart;
			++m_rank[rootStart];
		}
		return true;
	}

private:
	std::vector<int> m_parent;
	std::vector<int> m_rank;
};

std::vector<Edge> KruskalsAlgorithm(std::vector<Edge>& edges, int numNodes)
{
	std::cout << "Kruskals Algorithm:\n";
	int totalWeight = 0;
	std::vector<Edge> mst;
	DisjointSetUnion dsu(numNodes);

	// sort edges by weight
	std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {return a.weight < b.weight; });

	// unite the edges to build the Minimum Spanning Tree
	for (int i = 0; i < edges.size(); i++)
	{
		Edge& edge = edges[i];
		if (dsu.UniteEdge(edge.nodeIndex, edge.toIndex))
		{
			mst.push_back(edge);
			std::cout << edge.nodeIndex << "-" << edge.toIndex << " ";
			totalWeight += edge.weight;
			if (mst.size() == numNodes - 1)
			{
				// reusulting algirthm is numNodes - 1 (means it is a tree)
				// trees are nodes with edges euql to numNodes - 1
				break;
			}
		}
	}
	std::cout << "\n Total Tree Weight: " << totalWeight << "\n";
	return mst;
}

void Exercise3KruskalsAlgorithm()
{
	// Create Kruskals Algorithm
	std::cout << "Kruskals Algorithm\n";
	std::vector<Edge> edges;
	AddEdge(edges, 0, 1, 9);
	AddEdge(edges, 0, 2, 5);
	AddEdge(edges, 0, 3, 2);
	AddEdge(edges, 1, 3, 6);
	AddEdge(edges, 1, 4, 5);
	AddEdge(edges, 2, 3, 4);
	AddEdge(edges, 2, 4, 5);
	AddEdge(edges, 3, 4, 4);

	int numNodes = 5;
	std::vector<Edge> mst = KruskalsAlgorithm(edges, numNodes);
	std::vector<bool> isPrinted(numNodes, false);
	for (int i = 0; i < mst.size(); ++i)
	{
		Edge& edge = mst[i];
		if (!isPrinted[edge.nodeIndex])
		{
			std::cout << edge.nodeIndex << " ";
			isPrinted[edge.nodeIndex] = true;
		}
		if (!isPrinted[edge.toIndex])
		{
			std::cout << edge.toIndex << " ";
			isPrinted[edge.toIndex] = true;
		}
	}
	std::cout << "\n";
}

int main()
{
	std::cout << "MST:\n";
	//Exercise2Review();
	Exercise3KruskalsAlgorithm();
}