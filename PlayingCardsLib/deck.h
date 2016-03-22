#ifndef H_deck
#define H_deck

#include "card.h"

const unsigned deckSize = 52;

class PLAYINGCARDSDLL_API Deck
{
public:
	Deck();
	/// <summary>Randomize order of cards and call resetDrawn when done.</summary>
	void shuffle();
	/// <summary>Output rank and suit of each element of deck.cards[] to *out.</summary>
	void print(std::ostream *out) const;
	/// <summary>Returns a random Card object and sets its drawn value to true.</summary>
	Card drawCard();

private:
	/// <summary>
	/// The deck, represented as an array of Card objects.
	/// </summary>
	Card cards[deckSize];
	/// <summary>Creates the card objects and adds them to deck.cards[]</summary>
	void buildDeck();
	/// <summary>
	/// Returns a single Capital letter, as a string, to represent the card's suit.
	/// </summary>
	std::string determineSuit(unsigned) const;
	/// <summary>Sets the value of card.drawn to false for all card[] elements.</summary>
	void resetDrawn();

};

#endif