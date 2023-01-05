#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h"

class Game {
	public:
		Game();
		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string players[11];

		bool isFirstInning;
		Team teamA, teamB;
		Team *battingTeam, *bowlingTeam;
		Player *batsman, *bowler;

		void welcome();
		void display();
		int integerInput();
		void selectPlayers();
		bool validatePlayer(int);
		void showTeamPlayers();
		void toss();
		void tossChoice(Team);
		void firstInning();
		void initializePlayers();
		void playInnings();
		void bat();
		bool validateInningScore();
		void gameScoreCard();
		void secondInning();
		void winner();
		void summary();
};

