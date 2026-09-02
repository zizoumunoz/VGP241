#include "Player.h"

a6::Player::Player()
	: m_name("default")
{
}

a6::Player::Player(std::string name)
	: m_name(name)
{
}

void a6::Player::init()
{
	m_stats[Stats::Health] = 100;
	m_stats[Stats::Speed] = (rand() % 80) + 21;
	m_stats[Stats::Attack] = (rand() % 15) + + 6;
	m_stats[Stats::AttackCount] = 1;
}

int a6::Player::getStats(Stats stat)
{
	return m_stats[stat];
}

void a6::Player::setStat(Stats stat, int value)
{
	m_stats[stat] = value;
}

bool a6::Player::isAlive() const
{
	return m_stats[Stats::Health] > 0;
}
