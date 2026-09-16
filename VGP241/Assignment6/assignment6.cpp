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

    teamA.StartTurn();
    teamB.StartTurn();

    Player* playerA = teamA.GetNextBattlingPlayer();
    Player* playerB = teamB.GetNextBattlingPlayer();

    

    return 0;
}