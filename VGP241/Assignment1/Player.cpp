#include "Player.h"
#include "Stats.h"
#include <iostream>

Player::Player(std::string name)
	: mName(name)
{

}

void Player::initPlayer()
{
	mStats[Stats::Health] = 100;

	for (size_t i = 1; i < mStats.Size(); i++)
	{
		mStats[i] = rand() % 5 + 1;
	}
}

int Player::getStat(Stats stat) const
{
	return mStats[stat];
}

const std::string Player::getName() const
{
	return mName;
}

int Player::getPlayerScore(Player playerB) const
{
	// PlayerA.Health - [(PlayerB.Attack * PlayerB.Stamina) - (PlayerA.Defense * PlayerA.Speed)]
	return
		mStats[Stats::Health] -
		((playerB.getStat(Stats::Attack) * playerB.getStat(Stats::Stamina)) - (mStats[Stats::Defense] * mStats[Stats::Speed]));
}

void Player::display() const
{
	std::cout
		<< mName << "\n"
		<< "Health: " << mStats[Stats::Health] << "\t"
		<< "Attack: " << mStats[Stats::Attack] << "\t"
		<< "Defense: " << mStats[Stats::Defense] << "\t"
		<< "Stamina: " << mStats[Stats::Stamina] << "\t"
		<< "Speed: " << mStats[Stats::Speed] << "\t\n";
}
