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
	/// <summary>Returns the Card object at this.hand[card].</summary>
	/// <param name='card'> The index of the Card object to return</param>
	Card getCard(unsigned) const;
	/// <summary>Resets this player's hand by calling hand.clear().</summary>
	void discardHand();
	/// <summary>Returns an uint representing the player's "number" (player.no).</summary>
	unsigned getNo();
	/// <summary>Set the player's "number" (player.no) to the passed uint.</summary>
	void setNo(unsigned);

private:
	/// <summary>An uint representing the number of times this player has won.</summary>
	unsigned wins;
	/// <summary>An uint representing the number of times this player has lost.</summary>
	unsigned losses;
	/// <summary>
	/// Represents this player's "hand" as a vector of <paramref name='Card'/> objects.
	/// </summary>
	std::vector<Card> hand;
	/// <summary>An uint that serves as a unique identifier for the player.</summary>
	unsigned no;

};

#endif