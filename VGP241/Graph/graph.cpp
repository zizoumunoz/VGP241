#include <iostream>
#include <Graph.h>

void Exercise2()
{
	Vector<std::string> cities;
	cities.PushBack("Vancouver");		//0
	cities.PushBack("Burnaby");			//1
	cities.PushBack("Richmond");		//2
	cities.PushBack("New Westminster");	//3
	cities.PushBack("Port Moody");		//4
	cities.PushBack("Coquitlam");		//5
	cities.PushBack("Surrey");			//6
	cities.PushBack("Delta");			//7
	cities.PushBack("Tsawaasen");		//8
	cities.PushBack("Nanaimo");			//9

	Graph<std::string> citiesGraph;

	for (size_t i = 0; i < cities.Size(); i++)
	{
		citiesGraph.AddItem(&cities[i]);
	}

	citiesGraph.AddLink(0, 1);
	citiesGraph.AddLink(0, 2);
	citiesGraph.AddLink(1, 2);
	citiesGraph.AddLink(1, 4);
	citiesGraph.AddLink(1, 3);
	citiesGraph.AddLink(1, 5);

	std::cout << "Connected Cities of Greater Vancouver:\n";
	citiesGraph.PrintGraph();
	std::cout << "\n\n";

	int startingIndex = 0;
	Vector<const std::string*> connectedDFS;
	Vector<const std::string*> connectedBFS;
	citiesGraph.GetAllConnectionsBFS(startingIndex, connectedBFS);
}

struct Tile
{
	int x = 0;
	int y = 0;

	// in path finding
	bool isInPath = false;
	void Draw()
	{
		if (isInPath)
		{
			std::cout << "[0]";
		}
		else
		{
			std::cout << "[ ]";
		}
	}
	// this is so stdcout tile can be used
	friend std::ostream& operator<<(std::ostream& os, const Tile& t)
	{
		os << t.x << "_" << t.y;
		return os;
	}
};

void ClearMap(Vector<Tile>& map)
{
	for (int i = 0; i < map.Size(); i++)
	{
		map[i].isInPath = false;
	}
}

void DrawMap(int width, int height, const Vector<Tile>& tileMap)
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int index = x + (y * width);
			tileMap[index].Draw();
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void Exercise3TileMap()
{
	Vector<Tile> tileMap;
	Graph<Tile> mapGraph;

	int width = 10;
	int height = 10;
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			Tile tile;
			tile.x = x;
			tile.y = y;
			tileMap.PushBack(tile);
		}
	}
	for (size_t i = 0; i < tileMap.Size(); i++)
	{
		mapGraph.AddItem(&tileMap[i]);
	}
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			int index = x + (y * width);
			if (x + 1 < width)
			{
				int rightIndex = (x + 1) + (y * width);
				mapGraph.AddLink(index, rightIndex);

			}
			if (y + 1 < height)
			{
				int downIndex = x + ((y + 1) * width);
				mapGraph.AddLink(index, downIndex);
			}
		}
	}

	DrawMap(width, height, tileMap);

	int startX = 0;
	int startY = 0;
	int endX = 0;
	int endY = 0;
	std::cout << "Enter start x: ";
	std::cin >> startX;
	std::cout << "Enter start y: ";
	std::cin >> startY;
	std::cout << "Enter end x: ";
	std::cin >> endX;
	std::cout << "Enter end y: ";
	std::cin >> endY;

	Vector<const Tile*> pathDFS;
	Vector<const Tile*> pathBFS;
	int startIndex = startX + (startY * width);
	int endIndex = endX + (endY * width);
	mapGraph.GetPathDFS(startIndex, endIndex, pathDFS);
	mapGraph.GetPathBFS(startIndex, endIndex, pathBFS);

	system("cls");
	for (int i = 0; i < pathDFS.Size(); i++)

	{

	}
}

int main()
{
	std::cout << "Hello World!\n";

	Graph<int> myGraph;
	// create data for the graph
	Vector<int> graphData;
	for (int i = 0; i < 10; i++)
	{
		graphData.PushBack(i);
	}
	// add data to the graph
	for (int i = 0; i < graphData.Size(); i++)
	{
		myGraph.AddItem(&graphData[i]);
	}
	// link data together
	myGraph.AddLink(0, 1);
	myGraph.AddLink(0, 2);
	myGraph.AddLink(1, 3);
	myGraph.AddLink(1, 4);
	myGraph.AddLink(2, 5);
	myGraph.AddLink(2, 6);
	myGraph.AddLink(3, 7);
	myGraph.AddLink(4, 8);
	myGraph.AddLink(4, 7);
	myGraph.AddLink(5, 9);
	myGraph.AddLink(0, 9);
	myGraph.PrintGraph();

	Vector<const int*> dfsConnections;
	Vector<const int*> bfsConnections;
	myGraph.GetAllConnectionsBFS(0, bfsConnections);
	myGraph.GetAllConnectionsDFS(0, dfsConnections);

	std::cout << "Connections (DFS):\n";
	for (size_t i = 0; i < dfsConnections.Size(); i++)
	{
		std::cout << (*dfsConnections[i]) << " ";
	}
	std::cout << "\n";
	std::cout << "Connections (BFS):\n";
	for (size_t i = 0; i < bfsConnections.Size(); i++)
	{
		std::cout << (*bfsConnections[i]) << " ";
	}
	std::cout << "\n\n";

	int startIndex = 0;
	int endIndex = 9;
	Vector<const int* > pathDFS;
	Vector<const int* > pathBFS;

	std::cout << "path from 0-9:\n" << startIndex << "-" << endIndex << ":\n";
	if (myGraph.GetPathDFS(startIndex, endIndex, pathDFS))
	{
		for (int i = static_cast<int>(pathDFS.Size()) - 1; i >= 0; i--)
		{
			std::cout << (*pathDFS[i]) << "-";
		}

		std::cout << "\n";
	}
	else
	{
		std::cout << "Path is not found!\n";
	}
	std::cout << "\n";
	std::cout << "Path from " << startIndex << "-" << endIndex << " (BFS):\n";

	if (myGraph.GetPathBFS(startIndex, endIndex, pathBFS))
	{
		for (int i = static_cast<int>(pathBFS.Size()) - 1; i >= 0; i--)
		{
			std::cout << (*pathBFS[i]) << "-";
		}
		std::cout << "\n";
	}
	else
	{
		std::cout << "Path is not found!\n";
	}


}
