#include "Team.h"

void a6::Team::init(int numPlayers)
{
	for (size_t i = 0; i < numPlayers; i++)
	{
		a6::Player temp{ "Player " + std::to_string(i) };
		
	}
}
