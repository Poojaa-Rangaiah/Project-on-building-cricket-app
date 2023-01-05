#include <vector>
#include "player.h"

class Team {
	public:
		Team();
		std::string teamName;
		int totalRunScored;
		int wicketsLost;
		int totalBallsBowled;
		std::vector <Player> player;


};
