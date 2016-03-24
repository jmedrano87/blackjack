#include "player.h"

Player::Player()
{
	wins = 0;
	losses = 0;
	no = 0;
}

void Player::addToHand(Card card)
{
	hand.push_back(card);
}

unsigned Player::getNoOfCards() const
{
	return hand.size();
}

Card Player::getCard(unsigned card) const
{
	return hand[card];
}

void Player::discardHand()
{
	hand.clear();
}

unsigned Player::getNo()
{
	return no;
}

void Player::setNo(unsigned playerNo)
{
	no = playerNo;
}

void Player::addWin() 
{
	wins++;
}

unsigned Player::getWins() const
{
	return wins;
}

unsigned Player::getLosses() const
{
	return losses;
}
void Player::addLoss()
{
	losses++;
}