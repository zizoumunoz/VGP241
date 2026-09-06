#pragma once

#include "Vector.h"
#include "Global.h"

class DisjointSetUnion
{
public:
	DisjointSetUnion(size_t numNodes)
	{
		m_parent.Resize(numNodes);
		m_rank.Resize(numNodes, 0);
		for (size_t i = 0; i < numNodes; i++)
		{
			m_parent[i];
		}
	}
	size_t FindParentIndex(size_t index)
	{
		if (m_parent[index] != index)
		{
			m_parent[index] = FindParentIndex(index);
		}
		return m_parent[index];
	}

	bool UniteEdges(size_t from, size_t to)
	{
		size_t rootFrom = FindParentIndex(from);
		size_t rootTo = FindParentIndex(to);
		if (rootFrom == rootTo)
		{
			// already in the same set
			return false;
		}
		if (m_rank[rootFrom] < m_rank[rootTo])
		{
			m_parent[rootFrom] = rootTo;
		}
		else if (m_rank[rootFrom] > m_rank[rootTo])
		{
			m_parent[rootTo] = rootFrom;
		}
		else
		{
			m_parent[rootTo] = rootFrom;
			++m_rank[rootFrom];
		}
		return true;
	}
private:
	Vector<int> m_parent;
	Vector<int> m_rank;
};

template<typename T, typename W = int>
class MSTGraphK
{
private:
	struct Edge
	{
		int from = -1;
		int to = -1;
		W weight;
	};

	struct Node
	{
		const T* data = nullptr;
	};

public:

	MSTGraphK()
	{

	}

	~MSTGraphK()
	{
		Terminate();
	}

	void AddItem(const T* data)
	{
		Node* newNode = new Node();
		newNode->data = data;
		m_nodes.PushBack(newNode);
	}

	void AddEdge(size_t from, size_t to, W weight)
	{
		Edge newEdge = { from, to, weight };
		m_edges.PushBack(newEdge);
	}

	void ObtainMST(Vector<const T*>& mst, Vector<const T*> &links, W& totalWeight)
	{
		size_t numNodes = m_nodes.Size();
		DisjointSetUnion dsu(numNodes);
		Global::IntroSort(m_edges.Begin(), m_edges.End(),
			[](const Edge& a, const Edge& b)
			{
				return a.weight < b.weight;
			});
		for (size_t i = 0; i < m_edges.Size(); i++)
		{
			Edge& edge = m_edges[i];
			if (dsu.UniteEdges(edge.from, edge.to))
			{
				mst.PushBack(m_nodes[edge.from]);
				links[edge.from] = m_nodes[edge.to];
				if (mst.Size() == numNodes - 1)
				{
					mst.PushBack(m_nodes[edge.to]->data);
					break;
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
		m_nodes.Clear();
		m_edges.Clear();
	}
private:
	Vector<Node*> m_nodes;
	Vector<Edge> m_edges;
};