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

    // 3c. Display the names of all players and all of their stats
    for (size_t i = 0; i < players.Size(); i++)
    {
        players[i].display();
        std::cout << "\n";
    }

    // 3d. Remove 6 players
    for (size_t i = 0; i < 6; i++)
    {
        players.PopBack();
    }

    // 3e. Add players for a total of 20

    players.PushBack(Player("Pubert"));
    players.PushBack(Player("Anisa"));
    players.PushBack(Player("Ethan"));
    players.PushBack(Player("Martin"));
    players.PushBack(Player("Dale"));

    players.PushBack(Player("Dave"));
    players.PushBack(Player("Steve"));
    players.PushBack(Player("Matthew"));
    players.PushBack(Player("Gilbert"));
    players.PushBack(Player("Peter"));
    players.PushBack(Player("Joe"));

    players.PushBack(Player("Glenn"));
    players.PushBack(Player("Meg"));
    players.PushBack(Player("Stewart"));
    players.PushBack(Player("Brian"));
    players.PushBack(Player("Quahog"));

    // 3f. Pick a random 2 players, compare their stats to see who would win in a fight


}
