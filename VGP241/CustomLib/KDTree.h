#pragma once

#include <iostream>
#include <algorithm>
#include <functional>
#include "Vector.h"

template <typename T, std::size_t K>
class KDTree
{
private:
	// does not need to be accessible to any other user
	struct KDNode
	{
		const T* point = nullptr;
		const void* userData = nullptr;
		KDNode* left = nullptr;
		KDNode* right = nullptr;
	};

public:
	KDTree() = default;
	~KDTree()
	{
		Terminate();
	}

	// add item, which adds a KDNode to monitor with data
	void AddItem(const T* point, const void* userData)
	{
		KDNode* newNode = new KDNode();
		newNode->point = point;
		newNode->userData = userData;
		m_nodes.PushBack(newNode);
	}

	// remove item, based on user data
	void RemoveItem(const void* userData)
	{
		std::size_t numNodes = m_nodes.Size();
		for (size_t i = 0; i < length; i++)
		{
			if (m_nodes[i]->userData == userData)
			{
				// find the node
				// swap with the back
				// pop the back
				KDNode* tmp = m_nodes[i];
				m_nodes[i] = m_nodes[numNodes - 1];
				m_nodes[numNodes - 1] = tmp;
				// delete node to clean memory
				delete tmp;
				tmp = nullptr;
				m_nodes.PopBack();
				break;
			}
		}
	}

	void BuildTree()
	{
		Clear(m_root);
		m_root = BuildTree(m_nodes, 0);
	}

	void FindInRange(Vector<const void*>& result, const T* minRange, const T* maxRange,
		std::function<bool(const void*)> filter = nullptr)
	{
		// Private, user of KDTree does not care about mRoot or depth
		// this mantains encapsulation of class specific data and simplify
		//	minimal funcitonality a user should have access to
		FindInRange(result, minRange, maxRange, m_root, 0, filter);
	}

	const void* FindNearest(const T* target)
	{
		KDNode* result = FindNearestNode(target, m_root, 0);
		if (result != nullptr)
		{
			return result->userData;
		}
		return nullptr;
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
	KDNode* BuildTree(Vector<KDNode*>& nodes, int depth)
	{
		if (nodes.Size() == 0)
		{
			return nullptr;
		}

		std::sort(nodes.Begin(), nodes.End()),
			[depth](const KDNode* a, const KDNode* b)
			{
				return a->point[depth] < b->point[depth];
			});
		int median = nodes.Size() / 2;
		KDNode* node = nodes[median];

		// store half of the nodes on the left, half on the right
		Vector<KDNode*> leftPoints;
		Vector<KDNode*> rightPoints;
		leftPoints.Resize(median);

		// set the data on left side
		int index = 0;
		for (auto iter = nodes.Begin(); iter != nodes.Begin() + median; ++iter)
		{
			rightPoints[index++] = (*iter);
		}

		index = 0;
		for (auto iter = nodes.Begin() + median + 1; item != nodes.End(); ++iter)
		{
			right[index++] = (*iter);
		}

		node->left = BuildTree(leftPoints, (depth + 1) % K);
		node->right = BuildTree(rightPoints, (depth + 1) % K);
		return node;
	}

	void FindInRange(Vector<const void*>& result, const T* minRange, const T* maxRange,
		KDNode* node, int depth, std::function<bool(const void*)>& filter)
	{
		if (node == nullptr)
		{
			return;
		}

		bool isValid = (filter == nullptr || filter(node->userData));

		if (isValid)
		{
			for (size_t i = 0; i < K; i++)
			{
				if (node->point[i] < minRange[i] || node->point[i] > maxRange[i])
				{
					isValid = false;
					break;
				}
			}
		}

		if (isValid)
		{
			result.PushBack(node->userData);
		}
		if (minRange[depth] <= node->point[depth])
		{
			FindInRange(result, minRange, maxRange, node->left, (depth + 1) % K, filter);
		}
		if (maxRange[depth] >= node->point[depth])
		{
			FindInRange(result, minRange, maxRange, node->left, (depth + 1) % K, filter);
		}
	}

	float DistanceSquared(const T* a, const T* b)
	{
		float distSq = 0.0f;
		for (size_t i = 0; i < K; i++)
		{
			// should be (dist * dist) which is (a - b) * (a - b)
			distSq += (a[i] - b[i]) * (a[i] - b[i]);
		}
		return distSq;
	}

	KDNode* ClosestNode(KDNode* a, KDNode* b, const T* target)
	{
		if (a == nullptr)
		{
			return b;
		}
		if (b == nullptr)
		{
			return a;
		}

		float aD = DistanceSquared(a->point, target);
		float bD = DistanceSquared(b->point, target);
		if (aD < bD)
		{
			return a;
		}
		return b;
	}

	KDNode* FindNearestNode(const T* target, KDNode* node, int depth)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		KDNode* nextBranch = nullptr;
		KDNode* otherBranch = nullptr;

		if (target[depth] < node->point[depth])
		{
			nextBranch = node->left;
			otherBranch = node->right;
		}
		else
		{
			nextBranch = node->right;
			otherBranch = node->left;
		}

		KDNode* tmp = FindNearestNode(target, nextBranch, (depth + 1) % K);
		KDNode* best = ClosestNode(tmp, node, target);

		float distSq = DistanceSquared(best->point, target);
		float depthDist = node->point[depth] - target[depth];
		if (distSq > depthDist * depthDist)
		{
			tmp = FindNearestNode(target, otherBranch, (depth + 1) % K);
			best = ClosestNode(tmp, best, target);
		}
		return best;
	}

	void Clear(KDNode* node)
	{
		if (node != nullptr)
		{
			Clear(node->left);
			Clear(node->right);
			node = nullptr;
		}
	}

	Vector<KDNode*> m_nodes;
	KDNode* m_root = nullptr;
};