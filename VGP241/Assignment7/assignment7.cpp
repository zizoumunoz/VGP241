#include <iostream>
#include "City.h"


int main()
{
	using namespace a7;

	City city;

	city.addHouse("A", { 20, 40 });
	city.addHouse("B", { 50, 20 });
	city.addHouse("C", { 90, 40 });
	city.addHouse("D", { 60, 80 });
	city.addHouse("E", { 30, 120 });
	city.addHouse("F", { 100, 110 });
	city.addHouse("G", { 150, 130 });
	city.addHouse("H", { 160, 90 });
	city.addHouse("I", { 140, 60 });
	city.addHouse("J", { 180, 30 });
	city.addHouse("K", { 200, 120 });
	city.addHouse("L", { 220, 70 });
	city.addHouse("M", { 240, 50 });

	city.connectAllHouses();

	std::cout << "Optimal roads (Prim):\n";
	float totalPricePrim = city.getTotalRoadDistancePrim();
	std::cout << "Cost to connect all houses $" << totalPricePrim * 10.0f << "\n\n";

	std::cout << "Optimal roads (Kruskal):\n";
	float totalPriceKruskal = city.getTotalDistanceKruskal();
	std::cout << "Cost to connect all houses  $" << totalPriceKruskal * 10.0f << "\n";

	return 0;
}