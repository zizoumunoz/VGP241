#include <iostream>
#include "Team.h"

using namespace a6;



int main()
{
    srand(time(0));

    Team teamA("Team A");
    Team teamB("Team B");

    teamA.init(20);
    teamB.init(20);

    int turn = 0;

    while (teamA.GetRemainingPlayers() > 0 && teamB.GetRemainingPlayers() > 0)
    {
        std::cout << "\nTURN " << turn++ << "\n";

        teamA.StartTurn();  
        teamB.StartTurn();

        teamA.OrderPlayers();
        teamB.OrderPlayers();

        while (true)
        {
            Player& p1 = teamA.GetNextBattlingPlayer();
            Player
        }
    }

    return 0;
}