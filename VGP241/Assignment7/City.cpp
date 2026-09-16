#include "City.h"

void a7::City::addHouse(const std::string& name, const Vector2& pos)
{
	House temp{ name, pos };

	for (size_t i = 0; i < m_houses.Size(); i++)
	{
		if (m_houses[i] == temp)
		{
			return;
		}
	}

	m_houses.PushBack(temp);

}

void a7::City::connectAllHouses()
{
    const float MAX_DIST = 75.0f;

    // First: add all houses as nodes in both graphs
    for (size_t i = 0; i < m_houses.Size(); i++)
    {
        m_housesGraph.AddItem(&m_houses[i]);
        m_housesEdgesGraph.AddItem(&m_houses[i]);
    }

    // Second: connect houses within max distance
    for (size_t i = 0; i < m_houses.Size(); i++)
    {
        for (size_t j = i + 1; j < m_houses.Size(); j++)
        {
            float dx = m_houses[i].getPos().x - m_houses[j].getPos().x;
            float dy = m_houses[i].getPos().y - m_houses[j].getPos().y;
            float dist = sqrt(dx * dx + dy * dy);

            if (dist <= MAX_DIST)
            {
                // Prim graph (adjacency)
                m_housesGraph.AddLink(i, j, dist);

                // Kruskal graph (edge list)
                m_housesEdgesGraph.AddLink(i, j, dist);
            }
        }
    }
}

float a7::City::getTotalRoadDistancePrim()
{
    Vector<const House*> mst;
    Vector<const House*> links;
    float totalWeight = 0.0f;

    // Start Prim at node 0
    m_housesGraph.ObtainMST(0, mst, links, totalWeight);

    return totalWeight;
}

float a7::City::getTotalDistanceKruskal()
{
    Vector<const House*> mst;
    Vector<const House*> links;
    float totalWeight = 0.0f;

    m_housesGraph.ObtainMST(0, mst, links, totalWeight);

    std::cout << "Prim MST Connections:\n";

    for (size_t i = 0; i < links.Size(); i++)
    {
        if (links[i] != nullptr)
        {
            std::cout << links[i]->getName() << " -> " << mst[i]->getName() << "\n";
        }
    }

    std::cout << "Total distance: " << totalWeight << "\n";

}
