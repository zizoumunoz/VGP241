#pragma once
#include <Vector.h>
#include <KDTree.h>
#include "PickUp.h"

class PickupManager
{
public:

	// 1. Adds item to pickups then stores position
	// 2. Stores pickup in KDTree<float, 3>
	void AddItem(PickupType pickupType, const Vector3& pos);

	// Do a search to find the closest item in the position
	const PickUp* GetClosestPickup(const Vector3& pos);

	//	1.Do a search to find all items within a given range
	//	2.Use the pickupType to find a specific item, if Invalid, get all pickups in
	//	range
	void ObtainPickupsInRange(const Vector3& pos, float range, PickupType pickupType);



private:
	Vector<PickUp> m_pickups;
	KDTree<float, 3> m_tree;


};
