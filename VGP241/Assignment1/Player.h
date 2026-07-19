#pragma once
#include <string>
#include <Array.h>
#include "Stats.h"

class Player
{
public:
	Player() = default;

	// Function to initialize player with default values
	void initPlayer();

	int getStat(Stats stat) const;

private:
	std::string mName = "";
	Array<int, 5> mStats;

};

