#pragma once
#include <Vector.h>
#include <WeightedGraph.h>
#include "City.h"
namespace a8
{
	class GPS
	{
	public:
		// 1. Adds a city to m_cities
		// 2. Make sure there are no repeats
		void addCity(const std::string& name, const Vector2& pos);
	private:
		Vector<City> m_cities;
		WeightedGraph<City, float> m_cityGraph;

	};
}

