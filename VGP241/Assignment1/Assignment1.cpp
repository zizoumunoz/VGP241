#include <iostream>
// #include <Array.h>
#include <Vector.h>
#include "Player.h"

int main()
{
	srand(time(NULL));

	std::cout << "Custom Containers Assignment 1\n";
	// add necessary .h and .cpp files
	// since its small, can fit it all in main
	// using appropriate .h and .cpp helps practice formatting C++ code

	// 3a. Create vector of players
	Vector<a1::Player> players;

	// 3b. Add 10 players with random names

	players.PushBack(a1::Player("John"));
	players.PushBack(a1::Player("Jane"));
	players.PushBack(a1::Player("Mario"));
	players.PushBack(a1::Player("Mary"));
	players.PushBack(a1::Player("Jeff"));

	players.PushBack(a1::Player("Pablo"));
	players.PushBack(a1::Player("Paul"));
	players.PushBack(a1::Player("Paula"));
	players.PushBack(a1::Player("Robert"));
	players.PushBack(a1::Player("Rupert"));

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

	players.PushBack(a1::Player("Pubert"));
	players.PushBack(a1::Player("Anisa"));
	players.PushBack(a1::Player("Ethan"));
	players.PushBack(a1::Player("Martin"));
	players.PushBack(a1::Player("Dale"));

	players.PushBack(a1::Player("Dave"));


	players.PushBack(a1::Player("Steve"));
	players.PushBack(a1::Player("Matthew"));
	players.PushBack(a1::Player("Gilbert"));
	players.PushBack(a1::Player("Peter"));
	players.PushBack(a1::Player("Joe"));

	players.PushBack(a1::Player("Glenn"));
	players.PushBack(a1::Player("Meg"));
	players.PushBack(a1::Player("Stewart"));
	players.PushBack(a1::Player("Brian"));
	players.PushBack(a1::Player("Quahog"));

	// 3f. Pick a random 2 players, compare their stats to see who would win in a fight

	a1::Player player1 = players[rand() % players.Size()];
	a1::Player player2;
	do
	{
		player2 = players[rand() % players.Size()];
	} while (player1.getName() == player2.getName());

	std::cout << "Seleted random players: " << player1.getName() << " and " << player2.getName() << ".\n";

	std::cout << "Scores: " << player1.getName() << " - " << player1.getPlayerScore(player2) << "\n";
	std::cout << "Scores: " << player2.getName() << " - " << player2.getPlayerScore(player1) << "\n";

	if (player1.getPlayerScore(player2) > player2.getPlayerScore(player1))
	{
		std::cout << player1.getName() << " wins!\n";
	}
	else if(player1.getPlayerScore(player2) == player2.getPlayerScore(player1))
	{
		bool coin = rand() < rand();
		if (coin)
		{
			std::cout << player1.getName() << " wins by coinflip!\n";
		}
		else
		{
			std::cout << player2.getName() << " wins by coinflip!\n";
		}
	}
	else
	{
		std::cout << player2.getName() << " wins!\n";
	}




}
