#pragma once
#include <string>
#include "PickupType.h"
#include "Vector3.h"

class PickUp
{
public:
	PickUp() = default;
	PickUp(PickupType pickupType, const Vector3& pos);
private:
	PickupType m_type;
	std::string m_name;
	Vector3 m_position;
};
