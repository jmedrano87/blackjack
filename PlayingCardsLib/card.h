#ifndef H_card
#define H_card

#ifdef _WIN32
	#ifdef PLAYINGCARDSDLL_EXPORTS
	#define PLAYINGCARDSDLL_API __declspec(dllexport)
	#else
	#define PLAYINGCARDSDLL_API __declspec(dllimport)
	#endif // PLAYINGCARDSDLL_EXPORTS
#else
#define PLAYINGCARDSDLL_API
#endif

#include <string>

/// <summary>
/// Represents a standard playing card
/// </summary>
struct PLAYINGCARDSDLL_API Card
{
	/// <summary>
	/// The literal rank of the card (2 - 10, and J - A).
	/// </summary>
	std::string rank;
	/// <summary>
	/// The Suit the card belongs to, represented as a single capital letter.
	/// </summary>
	std::string suit;
	/// <summary>
	/// Stores the numerical value that corresponds to the card's
	/// <paramref name="rank"/>.
	/// <para>
	/// 2 - 10 are literal, A can be 11 or 1, and J, Q, K are 10.
	/// </para>
	/// </summary>
	unsigned value;
	/// <summary>
	/// Default false. Set to true when this Card is "drawn".
	/// </summary>
	bool drawn;
}; 

#endif