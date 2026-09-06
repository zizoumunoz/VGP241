#pragma once
#include <string>
#include <Vector.h>
#include "Player.h"
namespace a6
{
	class Team
	{
	public:
		void init(int numPlayers);

		// Returns the player with the fastest speed that hasn't attacked.
		Player* GetNextBattlingPlayer();

		// 1. Pass in the player from another team
		// 2. Use that player's damage to attack a random living player in the team
		// 3. 25% chance that the player attacked will slow down by 10
		//		a. Don't let speed go lower than 5
		// 4. 10% chance the attacking player will speed up by 5
		// 5. Attacking player's attackCount is set to 0
		void DamagePlayer(Player* player);

		// Returns the count of the number of players that have health > 0
		int GetRemainingPlayers();

		// 1. Sorts players by fastest speed (use IntroSort)
		// 2. if they have already attacked this turn:
		//		a. With the sort callback, if the AttackCount or Health is 0
		//		   act as if the speed is 0 (treat is as 0 in the callback, don't set it)
		void OrderPlayers();
	private:
		std::string m_name;
		Vector<Player> m_players;
	};

}
