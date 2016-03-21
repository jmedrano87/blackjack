#include <iostream>
#include <string>
#include "../BlackJackLib/blackjack.h"

using namespace std;

void actionMenu(const unsigned);
void turn(Blackjack &, const unsigned);
unsigned getNoOfPlayers();

int main()
{
	Blackjack game;
	unsigned players = 0;
	unsigned player;
	
	players = getNoOfPlayers();
	game.startRound(players);

	cout << "The dealer first card is: ";
	game.printDealerHand(&cout, true);
	for (player = 0; player < players; player++) {
		turn(game, player);
	}
	cout << "The dealer has: ";
	game.printDealerHand(&cout, false);
	cout << endl << game.getScore() << endl;

	return 0;
}

void actionMenu(const unsigned player)
{
	cout << "Player " << player + 1 << ": What do you want to do?" << endl << "[1] Hit" << endl
		<< "[2] Stand" << endl;
	cout << "Player " << player + 1 << ": Enter choice:	";
}

void turn(Blackjack &game, const unsigned player)
{
	unsigned action;
	bool done = false;
	string str = "Input must be a number.";

	cout << endl << "Starting Player " << player + 1 << "'s turn . . ." << endl << endl;

	do {
		cout << "Hand: ";
		game.printHand(player, &cout);
		cout << ", Score: " << game.getScore(player) << endl;

		if (game.getScore(player) == 21) {
			cout << "You got blackjack!" << endl;
			break;
		}
		else if (game.getScore(player) > 21) {
			cout << "You busted!" << endl;
			break;
		}

		actionMenu(player);
		try {
			cin >> action;
			if (!cin)
				throw str;
		}
		catch (string msg) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << msg << endl;
			continue;
		}

		switch (action)
		{
		case 1:
			game.hit(player);
			break;
		case 2:
			done = true;
			break;
		default:
			cout << "Invalid selection. Please try again." << endl;
			break;
		}
	} while (!done);
}//turn()

unsigned getNoOfPlayers()
{
	unsigned players;
	string invInp = "Invalid input.";

	cout << "How many players? ";
	try {
		cin >> players;
		if (!cin)
			throw invInp;
	}
	catch (string msg) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << msg << endl;
		players = getNoOfPlayers();
	}
	return players;
}