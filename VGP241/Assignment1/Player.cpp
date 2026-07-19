#include "Player.h"
#include "Stats.h"

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
