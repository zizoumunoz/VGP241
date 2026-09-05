#pragma once

// regular node tree that uses Prisms Algorithm
#include "PriorityQueue.h"

template<typename T, typename W = int>
class MSTGraph
{
private:
	struct Neighbor
	{
		int index = -1;
		W weight;

		bool operator<(const Neighbor& rhs) const { return weight < rhs.weight; }
		bool operator<=(const Neighbor& rhs) const { return weight <= rhs.weight; }
		bool operator==(const Neighbor& rhs) const { return weight == rhs.weight; }
		bool operator>=(const Neighbor& rhs) const { return weight >= rhs.weight; }
		bool operator>(const Neighbor& rhs) const { return weight > rhs.weight; }
	};

	struct Node
	{
		const T* data = nullptr;
		Vector<Neighbor> neighbors;
		W bestWeight;
		bool isVisited = false;	// is visited for searching
		bool isAdded = false;	// is added for MST graph
	};

public:
	MSTGraph()
	{

	}
	~MSTGraph()
	{
		Terminate();
	}

	size_t AddItem(const T* data)
	{
		Node* newNode = new Node();
		newNode->data = data;
		m_nodes.PushBack(newNode);
		return m_nodes.Size() - 1;
	}
	void AddLink(size_t from, int to, W weight, bool biDirectional = true)
	{
		if (from >= m_nodes.Size() || to >= m_nodes.Size())
		{
			return;
		}
		Neighbor neighbor = { to, weight };
		m_nodes[from]->neighbors.PushBack(neighbor);
		// go in both directions (same weight, swap indices)
		if (biDirectional)
		{
			neighbor.index = from;
			m_nodes[to]->neighbors.PushBack(neighbor);
		}
	}

	void ObtainMST(int start, Vector<const T*>& mst, Vector<const T*>& links, W& totalWeight)
	{
		// start: starting node index
		// mst: resulting mst added to list
		// links: resulting parenting hierarchy from the mst
		Reset();

		links.Resize(m_nodes.Size(), nullptr);
		PriorityQueue<Neighbor, std::greater<Neighbor>> process;
		process.Push({ start, 0 });
		while (!process.Empty())
		{
			Neighbor neighbor = process.Top();
			process.Pop();
			Node* node = m_nodes[neighbor.index];
			if (!node->isVisited)
			{
				node->isVisited = true;
				totalWeight += neighbor.weight;
				mst.PushBack(node->data);
				for (size_t i = 0; i < node->neighbors.Size(); i++)
				{
					const Neighbor& toNeighbor = node->neighbors[i];
					Node* toNode = m_nodes[toNeighbor.index];
					if (!toNode->isVisited && (!toNode->isAdded || toNeighbor.weight < toNode->bestWeight))
					{
						links[toNeighbor.index] = node->data;
						toNode->isAdded = true;
						toNode->bestWeight = toNeighbor.weight;

						process.Push(toNeighbor);
					}
				}
			}
		}
	}

	void Terminate()
	{
		for (size_t i = 0; i < m_nodes.Size(); i++)
		{
			delete m_nodes[i];
			m_nodes[i] = nullptr;
		}
		m_nodes.Resize(0);
	}
private:
	void Reset()
	{
		for (size_t i = 0; i < m_nodes.Size(); ++i)
		{
			m_nodes[i]->isVisited = false;
			m_nodes[i]->isAdded = false;
		}
	}
	Vector<Node*> m_nodes;
};