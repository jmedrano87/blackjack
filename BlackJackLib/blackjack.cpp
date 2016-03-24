#include "blackjack.h"
#include <fstream>

using namespace std;

Blackjack::Blackjack()
{
	deck.shuffle();
}

void Blackjack::deal(Player &player, Card card)
{
	player.addToHand(card);
}

unsigned Blackjack::getScore(unsigned player) const
{
	unsigned card;
	unsigned score = 0;

	for (card = 0; card < players[player].getNoOfCards(); card++) {
		switch (players[player].getCard(card).value)
		{
		case 11:
		case 12:
		case 13:
			score += 10;
			break;
		case 14:
			score += (score + 11 > 21) ? 1 : 11;
			break;
		default:
			score += players[player].getCard(card).value;
			break;
		}//switch
	}//for
	return score;
}

unsigned Blackjack::getScore() const
{
	unsigned card, score = 0;

	for (card = 0; card < house.getNoOfCards(); card++) {
		switch (house.getCard(card).value)
		{
		case 11:
		case 12:
		case 13:
			score += 10;
			break;
		case 14:
			score += (score + 11 > 21) ? 1 : 11;
			break;
		default:
			score += house.getCard(card).value;
			break;
		}//switch
	}//for
	return score;
}

void Blackjack::startRound(unsigned noOfPlayers)
{
	unsigned i, j;

#ifdef _DEBUG

	ofstream deckLog;
	deckLog.open("blackjack_deck.txt");
	deck.print(&deckLog);
	deckLog.close();

#endif //DEBUG

	players.resize(noOfPlayers);

	for (i = 0; i < noOfPlayers; i++) {
		players[i].setNo(i);
		for (j = 0; j < 2; j++) {
			deal(players[i], deck.drawCard());
		}
	}
	deal(house, deck.drawCard());
	deal(house, deck.drawCard());
}

void Blackjack::endRound(unsigned min)
{
	while (getScore() < min) {
		deal(house, deck.drawCard());
	}

	if (getScore() <= 20) {
		for (unsigned i = 0; i < players.size(); i++) {
			if (getScore(i) > getScore() && !(getScore(i) > 21))
				players[i].addWin();
			else
				players[i].addLoss();
		}
	}
	else if (getScore() > 21) {
		for (unsigned i = 0; i < players.size(); i++) {
			if (getScore(i) <= 21)
				players[i].addWin();
			else
				players[i].addLoss();
		}
	}
}

void Blackjack::printHand(unsigned player, ostream *out) const
{
	unsigned i;

	for (i = 0; i < players[player].getNoOfCards(); i++) {
		*out << players[player].getCard(i).rank << players[player].getCard(i).suit << " ";
	}
}

void Blackjack::printDealerHand(std::ostream *out, bool firstOnly) const
{
	unsigned i;

	if (firstOnly)
		*out << house.getCard(0).rank << house.getCard(0).suit << " ??";
	else
		for (i = 0; i < house.getNoOfCards(); i++)
			*out << house.getCard(i).rank << house.getCard(i).suit << " ";
}

void Blackjack::hit(unsigned player)
{
	deal(players[player], deck.drawCard());
}

vector<Card> Blackjack::getPlayerHand(unsigned player) const
{
	vector<Card> hand;

	for (unsigned i = 0; i < players[player].getNoOfCards(); i++)
		hand.push_back(players[player].getCard(i));

	return hand;
}

vector<Card> Blackjack::getHouseHand() const
{
	vector<Card> hand;

	for (unsigned i = 0; i < house.getNoOfCards(); i++)
		hand.push_back(house.getCard(i));

	return hand;
}