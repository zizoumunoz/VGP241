#pragma once

#include "PriorityQueue.h"
#include <limits>

template<typename T, typename W>
class WeightedGraph
{
private:
	struct Edge
	{
		int nodeIndex = -1;
		W weight;

		bool operator>(const Edge& rhs) const { return weight > rhs.weight; }
		bool operator>=(const Edge& rhs) const { return weight>= rhs.weight; }
		bool operator==(const Edge& rhs) const { return weight== rhs.weight; }
		bool operator<(const Edge& rhs) const { return weight<= rhs.weight; }
		bool operator<=(const Edge& rhs) const { return weight < rhs.weight; }
	};

	struct Node
	{
		const T* data = nullptr;
		Vector<Edge> edges;
		// parent node for back tracking when finding a path
		Node* parent = nullptr;
		// total weight for tracking when thepath is found
		W totalWeight;
	};

public:
	WeightedGraph()
	{

	}
	~WeightedGraph()
	{
		Terminate();
	}
	int AddItem(const T* data)
	{
		Node* node = new Node();
		node->data = data;
		m_nodes.PushBack(node);
		return m_nodes.Size() - 1;
	}
	void AddEdge(int a, int b, W weight)
	{
		if (a >= m_nodes.Size() || b >= m_nodes.Size())
		{
			return;
		}

		Edge edgeA = { b, weight };
		Edge edgeB = { a, weight };
		m_nodes[a]->edges.PushBack(edgeA);
		m_nodes[b]->edges.PushBack(edgeB);
	}

	W GetPath(int start, int end, Vector<const T*>& pathOutput)
	{
		Reset();

		PriorityQueue<Edge, std::greater<Edge>> process;
		m_nodes[start]->totalWeight = 0;
		process.Push({ start, 0 });
		while (!process.Empty())
		{
			Edge edge = process.Top();
			process.Pop();
			Node* node = m_nodes[edge.nodeIndex];
			if (edge.weight > node->totalWeight)
			{
				continue;
			}
			if (edge.nodeIndex == end)
			{
				// we found the end of the path, break
				break;
			}
			for (size_t i = 0; i < node->edges.Size(); i++)
			{
				const Edge& toEdge = node->edges[i];
				Node* toNode = m_nodes[toEdge.nodeIndex];
				// check if edge was process or if it is a better path, then add to the list
				if (node->totalWeight < std::numeric_limits<W>::max() && node->totalWeight + toEdge.weight < toNode->totalWeight)
				{
					toNode->totalWeight = node->totalWeight + toEdge.weight;
					toNode->parent = node;
					process.Push(toEdge);
				}
			}
		}

		pathOutput.Clear();
		Node* node = m_nodes[end];
		W totalWeight = node->totalWeight;
		while (node != nullptr)
		{
			pathOutput.PushBack(node->data);
			node = node->parent;
		}
		std::reverse(pathOutput.Begin(), pathOutput.End());
		return totalWeight;
	}

private:

	void Terminate()
	{
		for (size_t i = 0; i < m_nodes.Size(); i++)
		{
			delete m_nodes[i];
			m_nodes[i] = nullptr;
		}
		m_nodes.Clear();
	}

	void Reset()
	{
		for (size_t i = 0; i < m_nodes.Size(); i++)
		{
			m_nodes[i]->parent = nullptr;
			m_nodes[i]->totalWeight = std::numeric_limits<W>::max();
		}
	}

	Vector<Node*> m_nodes;
};