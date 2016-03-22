#ifndef H_blackjack
#define H_blackjack

#ifdef _WIN32
	#ifdef BLACKJACKDLL_EXPORTS
	#define BLACKJACKDLL_API __declspec(dllexport)
	#else
	#define BLACKJACKDLL_API __declspec(dllimport)
	#endif
#else
#define BLACKJACKDLL_API
#endif

#include <vector>
#include "../PlayingCardsLib/deck.h"
#include "../PlayingCardsLib/player.h"

class BLACKJACKDLL_API Blackjack
{
public:
	Blackjack();
	unsigned getScore(unsigned) const;				//Calculate and return player[x]'s current hand score
	unsigned getScore() const;
	void startRound(unsigned = 1);					//Deal 2 cards to x players and the house
	void endRound(unsigned = 16);					//Deal cards to house until score >= min
	void printHand(unsigned, std::ostream *) const;	//Output rank and suit of each Card in players[x].hand
	void printDealerHand(std::ostream *, bool = false) const;
	void hit(unsigned);								//deal a card to player[x]
	std::vector<Card> getPlayerHand(unsigned = 0) const;
	std::vector<Card> getHouseHand() const;

private:
	Deck deck;
	std::vector<Player> players;
	Player house;
	void deal(Player &, Card);						//Add Card to Player.hand
};

#endif