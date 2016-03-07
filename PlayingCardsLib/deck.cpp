#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "deck.h"

Deck::Deck()
{
	srand(time(NULL));
	buildDeck();
}

void Deck::buildDeck()
{
	unsigned deckCard;
	unsigned suitCard;
	
	for (deckCard = 0, suitCard = 2; deckCard < deckSize; deckCard++, suitCard++) {
		cards[deckCard].value = suitCard;
		switch (suitCard)
		{
		case 11:
			cards[deckCard].rank = 'J';
			break;
		case 12:
			cards[deckCard].rank = 'Q';
			break;
		case 13:
			cards[deckCard].rank = 'K';
			break;
		case 14:
			cards[deckCard].rank = 'A';
			suitCard = 1;	//reset suitCard as 'A' is last card in each
			break;
		default:
			cards[deckCard].rank = std::to_string(suitCard);
			break;
		}//switch
	
		cards[deckCard].suit = determineSuit(deckCard);
		cards[deckCard].drawn = false;
	}//for
}//buildDeck

std::string Deck::determineSuit(unsigned currentCard) const
{
	if (currentCard < 13)
		return "H";	//Heart \u2665
	else if (currentCard < 26)
		return "D";	//Diamond \u2666
	else if (currentCard < 39)
		return "C";	//Club \u2663
	else
		return "S";	//Spade \u2660
}//determineSuit

void Deck::resetDrawn()
{
	unsigned currentCard;
	
	for (currentCard = 0; currentCard < deckSize; currentCard++)
		cards[currentCard].drawn = false;
}//resetDrawn

void Deck::shuffle()
{
	unsigned cardsShuffled;
	Card tempDeck[deckSize];
	
	for (cardsShuffled = 0; cardsShuffled < deckSize; cardsShuffled++)
		tempDeck[cardsShuffled] = drawCard();
	
	for (cardsShuffled = 0; cardsShuffled < deckSize; cardsShuffled++)
		cards[cardsShuffled] = tempDeck[cardsShuffled];
	
	resetDrawn();
}//shuffleMe

Card Deck::drawCard()
{
	unsigned cardToDraw;
	
	do {
		cardToDraw = rand() % deckSize;
	} while (cards[cardToDraw].drawn);
	
	cards[cardToDraw].drawn = true;
	
	return cards[cardToDraw];
}//drawCard

void Deck::print(std::ostream *out) const
{
	unsigned currentCard;
	
	for (currentCard = 0; currentCard < deckSize; currentCard++)
		*out << "Card " << currentCard << ": " << cards[currentCard].rank
			<< cards[currentCard].suit << std::endl;
}//print