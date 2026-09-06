#pragma once
#include <string>
#include <Array.h>
#include "Stats.h"
namespace a6
{
	class Player
	{
	public:
		Player();
		Player(std::string name);
		/// <summary>
		/// Initialize player with default values.
		/// Health = 100
		/// Speed = rand(20, 100)
		/// Attack = rand(5, 20)
		/// AttackCount = 1, each attack reduces it by 1 (at 0 can't attack)
		/// </summary>
		void init();
		/// <summary>
		/// Return value of stated stat.
		/// </summary>
		int getStats(Stats stat);

		/// <summary>
		/// Update a stat.
		/// </summary>
		void setStat(Stats stat, int value);

		/// <summary>
		/// Returns true if health > 0
		/// </summary>
		bool isAlive() const;

	private:
		std::string m_name;
		Array<int, 4> m_stats;
	};
}

