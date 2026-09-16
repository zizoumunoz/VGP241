#pragma once
#include <Vector.h>
#include <MSTGraph.h>
#include <MSTGraphK.h>
#include "House.h"

namespace a7
{
	class City
	{
	public:
		void addHouse(const std::string& name, const Vector2& pos);
		void connectAllHouses();
		float getTotalRoadDistancePrim();
		float getTotalDistanceKruskal();

		Vector<House> m_houses;
		MSTGraph<House, float> m_housesGraph;
		MSTGraph<House, float> m_housesEdgesGraph;


	};
}

