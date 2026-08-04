#include "PickupManager.h"

void PickupManager::AddItem(PickupType pickupType, const Vector3& pos)
{
	PickUp newPickup(pickupType, pos);

	m_pickups.PushBack(newPickup);

	PickUp* storedPickup = &m_pickups[m_pickups.Size() - 1];

	m_tree.AddItem(storedPickup->m_position.data(), storedPickup);
}

const PickUp* PickupManager::GetClosestPickup(const Vector3 & pos)
{
	return nullptr;
}

void PickupManager::ObtainPickupsInRange(const Vector3& pos, float range, PickupType pickupType)
{}
