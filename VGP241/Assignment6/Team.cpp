#include "Team.h"
#include <Global.h>

a6::Team::Team(std::string name)
	: m_name(name)
{}

void a6::Team::init(int numPlayers)
{
	for (size_t i = 0; i < numPlayers; i++)
	{
		a6::Player temp{ "Player " + std::to_string(i) };
		temp.init();
		m_players.PushBack(temp);

	}
}

a6::Player& a6::Team::GetNextBattlingPlayer() const
{
	for (size_t i = 1; i < m_players.Size(); i++)
	{
		if (m_players[i].getStats(Stats::AttackCount) > 0 && m_players[i].getStats(Stats::AttackCount) > 0)
		{
			return m_players[i];
		}
	}

	return nullptr;
}

void a6::Team::DamagePlayer(a6::Player* player)
{
	// get player from this team and make sure the player is not DEAD
	Vector<Player*> living;

	for (size_t i = 0; i < m_players.Size(); i++)
	{
		if (m_players[i].getStats(Stats::Health) > 0)
		{
			living.PushBack(&m_players[i]);
		}
	}

	if (living.Size() == 0)
	{
		return;
	}


	Player* targetPlayer = living[rand() % m_players.Size()];

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
	Global::IntroSort(m_players.Begin(), m_players.End(),
		[](const Player& a, const Player& b)
		{
			int speedA = a.getStats(Stats::Speed);
			int speedB = b.getStats(Stats::Speed);

			if (a.getStats(Stats::Health) <= 0 || a.getStats(Stats::AttackCount) == 0)
			{
				speedA = 0;
			}

			if (b.getStats(Stats::Health) <= 0 || b.getStats(Stats::AttackCount) == 0)
			{
				speedB = 0;
			}

			return speedA > speedB;
		}

	);
}

std::string a6::Team::getName() const
{
	return m_name;
}


