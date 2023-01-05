#include "game.h"
using namespace std;

int main() {

	Game game;

	game.welcome();
	game.display();
	game.integerInput();
	game.selectPlayers();
	game.showTeamPlayers();
	game.toss();
	game.firstInning();
	game.secondInning();
	game.winner();
	game.summary();
	return 0;
}
