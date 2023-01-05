#include "game.h"

using namespace std;

Game :: Game() {

	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "Karthik";
	players[5] = "KLRahul";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "BKumar";
	players[10] = "Ishant";

	isFirstInning = false;
	teamA.teamName = "Team-A";
	teamB.teamName = "Team-B";
}

void Game :: welcome() {
	cout<<" --------------------------------CRIC IN-------------------------------- \n";
	cout<<"|                                                                       |\n";
	cout<<"|                 !!!WELCOME TO VIRTUAL CRICKET APP!!!                  |\n";
	cout<<"|                                                                       |\n";
	cout<<" ----------------------------------------------------------------------- \n";

	cout<<"\n\n";
	cout<<" ----------------------------------------------------------------------- \n";
	cout<<"|                              INSTRUCTIONS                             |\n";
	cout<<"|-----------------------------------------------------------------------|\n";
	cout<<"| 1. Create 2 teams (Team-A & Team-B of 4 players each) from a given    |\n";
	cout<<"|    pool of 11 players.                                                |\n";
	cout<<"| 2. Lead the toss and decide the choice of play.                       |\n";
	cout<<"| 3. Each innings will be of 6 balls.                                   |\n";
	cout<<" ----------------------------------------------------------------------- \n\n";
}

void Game :: display() {

	cout<<"Press Enter to continue\n\n";
	cin.get();

	cout<<"-------------------------------------------------\n";
	cout<<"|\t\tPool of Players\t\t\t|\n";
	cout<<"-------------------------------------------------\n";
	for (int i = 0; i < 11; i++) {
		cout<<"|\t\t["<<i<<"]"<<" "<<players[i]<<"\t\t\t|\n";
	}
	cout<<"-------------------------------------------------\n";

	cout<<"Press Enter to continue.\n";
	getchar();
}

int Game :: integerInput() {

	int n;
	while(!(cin>>n)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Invalid input, Enter only integer... Try Again!\n";
	}

	return n;
}

bool Game :: validatePlayer (int index) {
	int n;
	vector<Player> player;

	player = teamA.player;
	n = player.size();
	for(int i = 0; i < n; i++) {
		if(player[i].id == index) {
			return true;
		}
	}
	player = teamB.player;
	n = player.size();
	for(int i = 0; i < n; i++) {
		if(player[i].id == index) {
			return true;
		}
	}
	return false;
}

void Game :: selectPlayers() {

	cout<<endl;
	cout<<"--------------------------------------------------\n";
	cout<<"|\t\tCreate Team-A & Team-B\t\t |\n";
	cout<<"--------------------------------------------------\n";

	for (int i = 0; i < playersPerTeam; i++) {

		teamAselection:

		cout<<"\n\tSelect Player ["<<i+1<<"] of Team-A: ";
		int teamAplayerid = integerInput();

		if (teamAplayerid<0 || teamAplayerid>10){
			cout<<"Please select from the given players.\n";
			goto teamAselection;
		}
		else if (validatePlayer(teamAplayerid)) {
			cout<<"Re-entries of players is not permitted\n";
			goto teamAselection;
		}
		else {
			Player teamAplayer;
			teamAplayer.id = teamAplayerid;
			teamAplayer.name = players[teamAplayerid];
			teamA.player.push_back(teamAplayer);
		}

		teamBselection:

		cout<<"\n\tSelect Player ["<<i+1<<"] of Team-B: ";

		int teamBplayerid = integerInput();

		if (teamBplayerid<0 || teamBplayerid>10){
					cout<<"Please select from the given players.\n";
					goto teamBselection;
		}
		else if (validatePlayer(teamBplayerid)) {
			cout<<"Re-entries of players is not permitted\n";
			goto teamBselection;
		}
		else {
			Player teamBplayer;
			teamBplayer.id = teamBplayerid;
			teamBplayer.name = players[teamBplayerid];
			teamB.player.push_back(teamBplayer);
		}
	}
}

void Game::showTeamPlayers() {

    vector<Player> teamAPlayers = teamA.player;
    vector<Player> teamBPlayers = teamB.player;

    cout << endl << endl;
    cout << "--------------------------\t\t--------------------------" << endl;
    cout << "|         Team-A         |\t\t|         Team-B         |" << endl;
    cout << "--------------------------\t\t--------------------------" << endl;

    for (int i = 0; i < playersPerTeam; i++) {
        cout << "|\t" << "[" << i+1 << "] " << teamAPlayers[i].name << "\t |"
        	<< "\t\t"
			<< "|\t" << "[" << i+1  << "] " << teamBPlayers[i].name << "\t |" << endl;
    }
    cout << "--------------------------\t\t--------------------------" << endl << endl;
}

void Game :: toss () {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout<<"Press Enter to toss\n\n";
	//while(getchar()!='\n');
	getchar();
	cout<<"|---------------------------------|\n";
	cout<<"|       Let's toss the coin       |\n";
	cout<<"|---------------------------------|\n";
	cout<<"Tossing the coin....\n\n";
	//usleep(2000000);
	int n;
	srand(time(NULL));
	n = rand() % 2; // 0 or 1

	switch(n) {
	case 0:
		cout<<"Team-A won the toss\n\n";
		tossChoice(teamA);
		break;
	case 1:
		cout<<"Team-B won the toss\n\n";
		tossChoice(teamB);
		break;
	}
}

void Game::tossChoice(Team tossWinnerTeam) {
	cout<<"Enter 1 to bat or 2 to bowl first\n"<<endl
			<<"1. Bat"<<endl
			<<"2. Bowl\n";
	int a = integerInput();
	switch(a) {
	case 1:
		cout<<tossWinnerTeam.teamName<<" won the toss and selected to bat\n";

		if(tossWinnerTeam.teamName.compare("Team-A")==0) {
			battingTeam = &teamA;
			bowlingTeam = &teamB;
		}
		break;
	case 2:
		cout<<tossWinnerTeam.teamName<<" won the toss and selected to bowl\n";

		if(tossWinnerTeam.teamName.compare("Team-A")==0) {
			battingTeam = &teamB;
			bowlingTeam = &teamA;
		}
		break;
	default:
		cout<<"Invalid Input Try Again...\n";
		tossChoice(tossWinnerTeam);
	}
}

void Game::firstInning(){
	cout<<"\n\t\t|||FIRST INNING STARTS|||\n\n";
	isFirstInning = true;
	initializePlayers();
	playInnings();
}

void Game::initializePlayers() {
	batsman = &battingTeam -> player[0];
	bowler = &bowlingTeam -> player[0];
	cout<<battingTeam->teamName<<" - "<<batsman->name<<" is batting.\n";
	cout<<bowlingTeam->teamName<<" - "<<bowler->name<<" is bowling.\n";
}

void Game::playInnings() {
	for (int i = 0; i < maxBalls; i++) {
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while(getchar() != '\n');
		cout<<"\nPress Enter to Bowl!"<<endl;
		cin.get();
		cout<<"Bowling..."<<endl;
		bat();

		if(!validateInningScore()){
			break;
		}
	}
}

void Game::bat() {
	srand(time(NULL));
	int runs = rand() % 7;
	//update batting team and batsman score
	batsman->runScored += runs;
	battingTeam->totalRunScored += runs;
	batsman->ballsPlayed ++;
	//update bowling team and bowler score
	bowler->ballsBowled ++;
	bowlingTeam->totalBallsBowled ++;
	bowler->runsGiven += runs;

	if (runs != 0) {
		cout<<endl<<bowler->name<<" to "<<batsman->name<<" "<<runs<<" runs.\n";
		gameScoreCard();
	}else {
		cout<<endl<<bowler->name<<" to "<<batsman->name<<" "<<"OUT!\n";

		battingTeam->wicketsLost ++;
		int wickets = bowler->wicketsTaken ++;
		batsman = &battingTeam->player[wickets];
		gameScoreCard();
	}
}

bool Game::validateInningScore() {
	if(isFirstInning) {
		if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {
			cout << "\n\t\t ||| FIRST INNINGS ENDS |||\n\n";
			cout << battingTeam->teamName<<" "<<battingTeam->totalRunScored<<" - "<<battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<")\n";
			cout << bowlingTeam->teamName<<" needs "<<battingTeam->totalRunScored + 1<<" runs to win the match.\n\n";
			return false;
		}
	}
	else {
		if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls || bowlingTeam->totalRunScored>battingTeam->totalRunScored) {
			cout << "\n\t\t ||| SECOND INNINGS ENDS |||\n\n";
			cout << battingTeam->teamName<<" "<<battingTeam->totalRunScored<<" - "<<battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<")\n";
			return false;
		}
	}
	return true;
}

void Game :: gameScoreCard() {
	cout << "--------------------------------------------------------------------------\n";
	cout<<"\t"<<battingTeam->teamName<<" "<<battingTeam->totalRunScored<<" - "<<battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<") | "
			<<batsman->name<<" "<<batsman->runScored<<" ("<<batsman->ballsPlayed<<")\t"<<bowler->name<<" "<<bowler->ballsBowled<<" - "<<bowler->runsGiven<<" - "
			<<bowler->wicketsTaken<<endl;
	cout << "--------------------------------------------------------------------------\n";
}

void Game::secondInning(){
	cout<<"\n\t\t|||SECOND INNING STARTS|||\n\n";
	isFirstInning = false;
	Team temp = *battingTeam;
	*battingTeam = *bowlingTeam;
	*bowlingTeam = temp;
	initializePlayers();
	playInnings();
}

void Game::winner() {
    if(bowlingTeam->totalRunScored > battingTeam->totalRunScored)
        cout<<endl<<bowlingTeam->teamName<<" won the match by "<<playersPerTeam-bowlingTeam->wicketsLost<<" wickets!!"<<endl;
    else if(battingTeam->totalRunScored > bowlingTeam->totalRunScored)
        cout<<endl<<battingTeam->teamName<<" won the match by "<<battingTeam->totalRunScored-bowlingTeam->totalRunScored<<" runs!!"<<endl;
}


void Game::summary() {
    cout<<endl<<endl<<"\t\t\t|| MATCH ENDS ||\n"<<endl;
    cout<<battingTeam->teamName<<" "<<battingTeam->totalRunScored<<"-"<<battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<")\n";
    cout<<" -----------------------------------------------\n";
    cout<<"| PLAYER\t\tBATTING\t\tBOWLING\t|\n";
    for(int i=0;i<playersPerTeam;i++)
    {
    cout<<"|-----------------------------------------------|\n";
    cout<<"| ["<<i+1<<"] "<<battingTeam->player[i].name<<"\t\t"<<battingTeam->player[i].runScored<<"("<<battingTeam->player[i].ballsPlayed<<")\t\t"<<battingTeam->player[i].ballsBowled<<"-"<<battingTeam->player[i].runsGiven<<"-"<<battingTeam->player[i].wicketsTaken<<"\t|\n";
    }
    cout<<" -----------------------------------------------\n\n";
    cout<<bowlingTeam->teamName<<" "<<bowlingTeam->totalRunScored<<"-"<<bowlingTeam->wicketsLost<<" ("<<battingTeam->totalBallsBowled<<")\n";
    cout<<"-----------------------------------------------\n";
    cout<<"| PLAYER\t\tBATTING\t\tBOWLING\t|\n";
    for(int i=0;i<playersPerTeam;i++)
    {
    cout<<"|-----------------------------------------------|\n";
    cout<<"| ["<<i+1<<"] "<<bowlingTeam->player[i].name<<"\t\t"<<bowlingTeam->player[i].runScored<<"("<<bowlingTeam->player[i].ballsPlayed<<")\t\t"<<bowlingTeam->player[i].ballsBowled<<"-"<<bowlingTeam->player[i].runsGiven<<"-"<<bowlingTeam->player[i].wicketsTaken<<"\t|\n";
    }
    cout<<" -----------------------------------------------\n";
}
