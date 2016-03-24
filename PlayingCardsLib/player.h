#ifndef H_player
#define H_player

#include "card.h"
#include <vector>

class PLAYINGCARDSDLL_API Player
{
public:
	Player();
	void addToHand(Card);
	unsigned getNoOfCards() const;
	Card getCard(unsigned) const;
	void discardHand();		//clear() hand
	unsigned getNo();		//get the player number
	void setNo(unsigned);	//set the player number
	unsigned getWins() const;
	void addWin();
	unsigned getLosses() const;
	void addLoss();

private:
	unsigned wins;
	unsigned losses;
	std::vector<Card> hand;
	unsigned no;			//player number

};

#endif