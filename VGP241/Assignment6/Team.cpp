#include "Team.h"
#include <Global.h>

void a6::Team::init(int numPlayers)
{
	for (size_t i = 0; i < numPlayers; i++)
	{
		a6::Player temp{ "Player " + std::to_string(i) };

	}
}

a6::Player* a6::Team::GetNextBattlingPlayer()
{
	Player* targetPlayer = &m_players[0];

	for (size_t i = 1; i < m_players.Size(); i++)
	{
		if (m_players[i].getStats(Stats::AttackCount) > 0)
		{
			if (targetPlayer->getStats(Stats::Speed) < m_players[i].getStats(Stats::Speed))
			{
				targetPlayer = &m_players[i];
			}
		}
	}

	return targetPlayer;
}

void a6::Team::DamagePlayer(a6::Player* player)
{
	// get player from this team 
	Player* targetPlayer = &m_players[rand() % m_players.Size()];

	int targetHealth = targetPlayer->getStats(Stats::Health);
	targetPlayer->setStat(
		Stats::Health,
		targetHealth - player->getStats(Stats::Attack)
	);

	int randChance = (rand() % 100) + 1;

	// 25% chance that the player attacked will slow down by 10
	if (randChance <= 25)
	{
		targetPlayer->setStat(
			Stats::Speed,
			targetPlayer->getStats(Stats::Speed) - 10
		);

		if (targetPlayer->getStats(Stats::Speed) < 5)
		{
			targetPlayer->setStat(Stats::Speed, 5);
		}
	}
	if (randChance <= 10)
	{
		player->setStat(
			Stats::Speed,
			player->getStats(Stats::Speed) + 5
		);
	}

	player->setStat(Stats::AttackCount, 0);
}

int a6::Team::GetRemainingPlayers()
{
	int total = 0;
	for (size_t i = 0; i < m_players.Size(); i++)
	{
		if (m_players[i].getStats(Stats::Health) > 0)
		{
			++total;
		}
	}
	return total;
}

void a6::Team::OrderPlayers()
{
	Global::IntroSort()
}


