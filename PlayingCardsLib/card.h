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

struct PLAYINGCARDSDLL_API Card
{
	std::string rank;
	std::string suit;
	unsigned value;		//2 - 14 (2 - A)
	bool drawn;
}; 

#endif