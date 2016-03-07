#ifndef H_deck
#define H_deck

#include "card.h"

const unsigned deckSize = 52;	//No Jokers

class PLAYINGCARDSDLL_API Deck
{
public:
	Deck();
	void shuffle();							//Randomize order of cards and call resetDrawn when done
	void print(std::ostream *out) const;	//Output rank and suit of each element of cards[]
	Card drawCard();						//Returns a random Card and sets it drawn value to true

private:
	Card cards[deckSize];
	void buildDeck();						//Creates the card objects and adds them to cards[]
	std::string determineSuit(unsigned) const;
	void resetDrawn();						//Sets value of drawn to false for all card elements

};

#endif
