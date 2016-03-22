#ifndef H_player
#define H_player

#include "card.h"
#include <vector>

/// <summary>
/// An object that represents a standard card game player.
/// </summary>
class PLAYINGCARDSDLL_API Player
{
public:
	/// <summary>
	/// Default constructer. Sets <paramref name="wins"/>,
	/// <paramref name="losses"/>, and <paramref name="no"/> to 0.
	/// </summary>
	Player();
	/// <summary>
	/// Adds the specified Card to this players <paramref name="hand"/>
	/// </summary>
	/// <param name='card'>The Card object to add to
	/// <paramref name="hand"/>
	/// </param>
	void addToHand(Card);
	/// <summary>
	/// Returns the number of cards in this player's hand as
	/// an uint.
	/// </summary>
	/// <returns>An unsigned interger.</returns>
	unsigned getNoOfCards() const;
	/// <summary>
	/// Returns the Card object at this.hand[card].
	/// </summary>
	/// <param name='card'> The index of the Card object to return</param>
	Card getCard(unsigned) const;
	void discardHand();		//clear() hand
	unsigned getNo();		//get the player number
	void setNo(unsigned);	//set the player number

private:
	unsigned wins;
	unsigned losses;
	std::vector<Card> hand;
	unsigned no;			//player number

};

#endif