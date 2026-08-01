#pragma once
#include <iostream>

#include "Stack.h"
#include "Queue.h"

template<typename T>
class Graph
{
private:
	struct Node
	{
		// data stored on a graph node
		const T* data = nullptr;
		// use flag for if it is visited
		bool isVisited = false;
		// for obtaining path
		Node* fromNode = nullptr;
		// connected edges
		Vector<int> edges;

	};

public:
	Graph()
	{

	}

	~Graph()
	{
		Terminate();
	}

	// Adds item, returns index of added item
	int AddItem(const T* data)
	{
		Node* newNode = new Node();
		newNode->data = data;
		m_nodes.PushBack(newNode);
		return m_nodes.Size() - 1;
	}
	// Add link between node indices
	// size_t is + so can't be < 0
	void AddLink(int a, int b, bool bothWays = true)
	{
		if (a >= m_nodes.Size() || b >= m_nodes.Size())
		{
			return;
		}
		m_nodes[a]->edges.PushBack(b);
		if (bothWays)
		{
			m_nodes[b]->edges.PushBack(a);
		}
	}

	// Get connections DFS
	void GetAllConnectionsDFS(int startIndex, Vector<const T*>& connections)
	{
		// LIFO
		Reset();

		Stack<Node*> stack;
		stack.Push(m_nodes[startIndex]);
		while (!stack.Empty())
		{
			Node* node = stack.Top();
			stack.Pop();
			if (!node->isVisited)
			{
				node->isVisited = true;
				connections.PushBack(node->data);
				for (size_t i = 0; i < node->edges.Size(); ++i)
				{
					int edgeIndex = node->edges[i];
					Node* edgeNode = m_nodes[edgeIndex];
					if (!edgeNode->isVisited)
					{
						stack.Push(edgeNode);
					}
				}
			}
		}

	}

	void GetAllConnectionsBFS(int startIndex, Vector<const T*>& connections)
	{
		// FIFO
		Reset();

		Queue<Node*> queue;
		queue.Enqueue(m_nodes[startIndex]);
		while (!queue.Empty())
		{
			Node* node = queue.Front();
			queue.Dequeue();
			if (!node->isVisited)
			{
				node->isVisited = true;
				connections.PushBack(node->data);
				for (size_t i = 0; i < node->edges.Size(); ++i)
				{
					int edgeIndex = node->edges[i];
					Node* edgeNode = m_nodes[edgeIndex];
					if (!edgeNode->isVisited)
					{
						queue.Enqueue(edgeNode);
					}
				}
			}
		}

	}

	// print all the graph data
	void PrintGraph()
	{
		std::cout << "Print Graph:\n";
		for (size_t i = 0; i < m_nodes.Size(); ++i)
		{
			// prints the "data" value (if using a class, may need to override ostream& operator<<(ostream& s)
			std::cout << (*m_nodes[i]->data) << ": ";
			for (size_t e = 0; e < m_nodes[i]->edges.Size(); ++e)
			{
				int edgeNodeIndex = m_nodes[i]->edges[e];
				std::cout << (*m_nodes[edgeNodeIndex]->data) << " ";
			}
			std::cout << "\n";
		}
	}

	void Terminate()
	{
		for (size_t i = 0; i < m_nodes.Size(); i++)
		{
			delete m_nodes[i];
			m_nodes[i] = nullptr;
		}
		m_nodes.Clear();

	}


private:
	void Reset()
	{
		for (size_t i = 0; i < m_nodes.Size(); i++)
		{
			m_nodes[i]->isVisited = false;
			m_nodes[i]->fromNode = nullptr;
		}
	}
	Vector<Node*> m_nodes;
};