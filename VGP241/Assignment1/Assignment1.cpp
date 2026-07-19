#include <iostream>
#include <Array.h>
#include <Vector.h>
#include "Player.h"

int main()
{
    std::cout << "Custom Containers Assignment 1\n";
    // add necessary .h and .cpp files
    // since its small, can fit it all in main
    // using appropriate .h and .cpp helps practice formatting C++ code

    // 3a. Create vector of players
    Vector<Player> players;
    
    // 3b. Add 10 players with random names

    players.PushBack(Player("John"));
    players.PushBack(Player("Jane"));
    players.PushBack(Player("Mario"));
    players.PushBack(Player("Mary"));
    players.PushBack(Player("Jeff"));

    players.PushBack(Player("Pablo"));
    players.PushBack(Player("Paul"));
    players.PushBack(Player("Paula"));
    players.PushBack(Player("Robert"));
    players.PushBack(Player("Rupert"));

    for (size_t i = 0; i < players.Size(); i++)
    {
        players[i].initPlayer();
    }

    std::cout << players[0].getName() << "\n";

}
