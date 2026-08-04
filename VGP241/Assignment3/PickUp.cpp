#include "PickUp.h"
#include "PickupType.h"

PickUp::PickUp(PickupType pickupType, const Vector3& pos)
	: m_type(pickupType), m_position(pos)
{
	switch (m_type)
	{
	case Invalid:
		m_name = "Invalid Name";
		break;
	case Health:
		m_name = "Health Pickup";
		break;
	case WeaponAmmo:
		m_name = "Weapon Ammo";
		break;
	case Coins:
		m_name = "Coins";
		break;
	case Upgrade:
		m_name = "Upgrade";
		break;
	case SpecialItem:
		m_name = "Special Item";
		break;
	default:
		m_name = "Default Case";
		break;
	}
}

Vector3 PickUp::GetPos()
{
	return m_position;
}
