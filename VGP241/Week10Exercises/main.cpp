// Week 10 Exercises
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <queue>

std::chrono::system_clock::time_point gStartTime;
void StartAlgorithm()
{
	gStartTime = std::chrono::system_clock::now();
}

void PrintDuration()
{
	auto endTime = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - gStartTime).count();
	std::cout << "Duration (nano): " << duration << "\n";
}

int GetIndexLinearSearch(const std::vector<int>& numbers, int target)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (numbers[i] == target)
		{
			return i;
		}
	}
	return -1;
}

int GetIndexBinarySearch(const std::vector<int>& numbers, int target)
{
	// range of numbers
	int low = 0;
	int high = numbers.size() - 1;
	// while within range, find the numbjr
	while (low <= high)
	{
		int mid = low + ((high - low) / 2);
		// if the middle number is the target, return the index
		if (numbers[mid] == target)
		{
			return mid;
		}
		// if mid is less, target is on the right
		if (numbers[mid < target])
		{
			low = mid + 1;
		}
		// otherwise target is on the left
		else
		{
			high = mid - 1;
		}
		// remaining area is shrunk to find the target
	}
	// did not find target, return -1
	return -1;
}

void Exercise1Comparison()
{
	int maxNumbers = 50;
	int min = -100;
	int max = 100;
	std::vector<int> numbers;
	for (int i = 0; i < maxNumbers; i++)
	{
		int value = min + (rand() % ((max + 1) - 1));
		std::cout << value << " ";
		numbers.push_back(value);
	}
	std::cout << "\n";
	std::sort(numbers.begin(), numbers.end());

	int numberToFind = 45;
	std::cout << "Number " << numberToFind << " is at index:\n";
	std::cout << "Linear Search:\n";
	StartAlgorithm();
	int indexLinear = GetIndexLinearSearch(numbers, numberToFind);
	PrintDuration();
	std::cout << "Index: " << indexLinear << "\n";
	std::cout << "Binary Search:\n";
	StartAlgorithm();
	int indexBinary = GetIndexBinarySearch(numbers, numberToFind);
	PrintDuration();
	std::cout << "Index: " << indexBinary << "\n";
	// Linear Best Case: target is index 0
	// Binary Best Case: target is in middle index

	// Linear Worst Case: target is in last index
	// Binary Worst Case: Target is in index 0 or last index
}

int MinLinear(const std::vector<int>& numbers)
{
	int minValue = INT_MAX;
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (numbers[i] < minValue)
		{
			minValue = std::min(minValue, numbers[i]);
		}
		return minValue;
	}
}

// 3 steps for Divide and Conquer
// 1) Divide - split the problem up
// 2) Conquer  - solve the problem in small forms
// 3) Combine - merge the solutinos together for the end result
int MinDivideAndConquer(const std::vector<int>& numbers, int left, int right)
{
	if (left = right)
	{
		return numbers[left];
	}
	// check if only 2 are left
	if (left + 1 == right)
	{
		return std::min(numbers[left], numbers[right]);
	}
	int mid = left + ((right - left) / 2);
	int minLeft = MinDivideAndConquer(numbers, left, mid);
	int minRight = MinDivideAndConquer(numbers, mid + 1, right);
	return std::min(minLeft, minRight);
}

void Exercise2DivideAndConquer()
{
	// Divide and Conquer
	// Create a vector of 20 random numbers between 1 - 100
	// Using a divide and conquer method, find the smallest number
	int maxNumbers = 20;
	int min = 1;
	int max = 100;
	std::vector<int> numbers;
	for (int i = 0; i < maxNumbers; ++i)
	{
		int value = min + (rand() % ((max + 1) - min));
		numbers.push_back(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	std::cout << "Min value is\n";
	std::cout << "Linear:\n";
	StartAlgorithm();
	int minLinear = MinLinear(numbers);
	PrintDuration();
	std::cout << "Min: " << minLinear << "\n";
	std::cout << "Divide and Conquer:\n";
	StartAlgorithm();
	int minDC = MinDivideAndConquer(numbers, 0, numbers.size() - 1);
	PrintDuration();
	std::cout << "Min : " << minDC << "\n";
}


struct Vector2
{
	float x = 0.0f;
	float y = 0.0f;

	static float Distance(const Vector2& a, const Vector2& b)
	{
		Vector2 dist = { a.x - b.x, a.y - b.y };
		return std::sqrt((dist.x * dist.x) + (dist.y * dist.y));
	}
};

struct Node
{
	std::string name;
	Vector2 position;
	void Print()
	{
		std::cout << name << " (" << position.x << ", " << position.y << ")\n";
	}
};

struct Edge
{
	int toIndex = -1;
	float weight = 0.0f;

	bool operator<(const Edge& rhs) const { return weight < rhs.weight; }
	bool operator<=(const Edge& rhs) const { return weight <= rhs.weight; }
	bool operator==(const Edge& rhs) const { return weight == rhs.weight; }
	bool operator>(const Edge& rhs) const { return weight > rhs.weight; }
	bool operator>=(const Edge& rhs) const { return weight >= rhs.weight; }
};


// add node to a vector (clean way for the example)
void AddNode(std::vector<Node>& nodes, const std::string& name, const Vector2& pos)
{
	Node node = { name, pos };
	nodes.push_back(node);
}

void AddEdge(std::vector<std::vector<Edge>>& graph, const std::vector<Node>& nodes, int a, int b)
{
	const Node& aNode = nodes[a];
	const Node& bNode = nodes[b];

	// dinstance as the weight
	float distance = Vector2::Distance(aNode.position, bNode.position);

	// store edges in the graph
	graph[a].push_back({ b, distance });
	graph[b].push_back({ a, distance });

}

// using a starting nodes, get the shrotes
std::vector<float> Dijkstra(const std::vector<std::vector<Edge>>& graph, int startNode, std::vector<int>& parent)
{
	std::vector<float> distances;
	distances.resize(graph.size(), FLT_MAX);
	parent.resize(graph.size(), -1);
	std::priority_queue<Edge, std::vector<Edge>, std::greater<>> process;
	distances[startNode] = 0.0f;
	parent[startNode] = -1;
	process.push({ startNode, 0.0f });
	while (!process.empty())
	{
		Edge edge = process.top();
		process.pop();
		int index = edge.toIndex;
		//if weight is further than current index, ignore
		if (edge.weight > distances[index])
		{
			continue;
		}
		for (int i = 0; i < graph[index].size(); ++i)
		{
			const Edge& toEdge = graph[index][i];
			int toIndex = toEdge.toIndex;
			int toWeight = toEdge.weight;
			// if the current index has alerady been added (total weight < FLT_MAX)
			// and the weight to add is less than the current weight at the locaiton
			// then add to the list
			if (distances[toIndex] < FLT_MAX && distances[index] + toWeight < distances[toIndex])
			{
				distances[toIndex] = distances[index] + toWeight;
				parent[toIndex] = index;
				process.push({ toIndex, distances[toIndex] });
			}
		}
	}
	return distances;
}

void PrintPath(const std::vector<Node>& nodes, const std::vector<std::vector<Edge>>& graph, int from, int to)
{
	std::cout << "Path from " << nodes[from].name << " to " << nodes[to].name << ":\n";
	std::vector<int> parent;
	std::vector<float> distances = Dijkstra(graph, from, parent);

}

void Exercise3Dijkstra()
{

	std::cout << "Dijkstra's Algorithm:\n";
	std::vector<Node> nodes;
	std::vector<std::vector<Edge>> graph;
	AddNode(nodes, "A", { 20, 40 });
	AddNode(nodes, "B", { 50, 20 });
	AddNode(nodes, "C", { 90, 40 });
	AddNode(nodes, "D", { 60, 80 });
	AddNode(nodes, "E", { 30, 120 });
	AddNode(nodes, "F", { 100, 110 });
	AddNode(nodes, "G", { 150, 130 });
	AddNode(nodes, "H", { 160, 90 });
	AddNode(nodes, "I", { 140, 60 });
	AddNode(nodes, "J", { 180, 30 });
	AddNode(nodes, "K", { 200, 120 });
	AddNode(nodes, "L", { 220, 70 });
	AddNode(nodes, "M", { 240, 50 });

	// need to make sure the graph is the same size as the nodes
	graph.resize(nodes.size());
	for (int i = 0; i < nodes.size(); ++i)
	{
		for (int j = 0; j < nodes.size(); j++)
		{
			if (Vector2::Distance(nodes[i].position, nodes[j].position) < 80.0f)
			{
				AddEdge(graph, nodes, i, j);
			}
		}
	}
}


void Backtracking(int maxNumber, int maxCombinations, int startValue, std::vector<int>& combination, std::vector<std::vector<int>>& allCombos)
{
	if (combination.size() == maxCombinations)
	{
		allCombos.push_back(combination);
		return;
	}
	for (int i = startValue; i <= maxNumber; ++i)
	{
		combination.push_back(i);
		Backtracking(maxNumber, maxCombinations, i + 1, combination, allCombos);
		combination.pop_back();
	}
}

void Exercise4Backtracking()
{
	// Create a program that generates
	// Unique combinations of 3 numbers
	// numbers range from 1 - 5
	// (basically the dice exercise fromthe first week)
	int maxNumber = 5;
	int minNumber = 1;
	int maxCombos = 3;
	std::vector<std::vector<int>> allCombos;
	std::vector<int> combination;
	Backtracking(maxNumber, maxCombos, minNumber, combination, allCombos);
	for (int i = 0; i < allCombos.size(); ++i)
	{
		for (int j = 0; j < allCombos[i].size(); j++)
		{
			std::cout << allCombos[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void Exercise5Stochastic()
{
	// Using a stochastic algorithm(SGD)
	// find the best = fit line for a dataset
	// 1. Define data (Linear regression problem)
	std::vector<double> x = { 0, 1, 2, 3,4,5 };
	std::vector<double> y = { 0, 1.1, 1.9, 3, 4.2, 5.2 };
	double m = 0.0;	// initial slope
	double b = 0.0; // initial y-intercept
	double learningRate = 0.01;
	const int epochs = 100;
	int numSample = x.size();

	// 2. SGD algorithm
	for (int epoch = 0; epoch < epochs; ++epoch)
	{
		double totalError = 0.0;
		for (int i = 0; i < numSample; ++i)
		{
			// select random data point index
			int randIndex = rand() % x.size();
			double xVal = x[randIndex];
			double yVal = y[randIndex];

			// calculate prediciton and error
			double yPrediction = m * xVal + b;
			double error = yPrediction - yVal;
			totalError += error;

			// update parameters using the gradient from the single random point
			m -= learningRate * (2.0 * error * xVal);
			b -= learningRate * (2.0 * error);
		}
		std::cout << "Epoch " << epochs + 1 << ", Average Error: " << totalError / numSample << "\n";
		// 3. print results
	}

	std::cout << "Optimized Intercept (b): " << b << "\n";
	std::cout << "Optimized Slope (m): " << m << "\n";
	// print average error for monitoring convergence
}

int main()
{
	srand(time(0));
	// Exercise1Comparison();
	//Exercise2DivideAndConquer();
	//Exercise3Dijkstra();
	//Exercise4Backtracking();
	Exercise5Stochastic();
}
