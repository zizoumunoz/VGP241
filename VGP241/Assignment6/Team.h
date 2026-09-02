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
	private:
		std::string m_name;
		Vector<Player> m_players;
	};

}
