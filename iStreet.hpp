/**********************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: CLASS IMPLEMENTS CHARACTER INTERACTION WITH
STREET SPACES
***********************************************************/
#ifndef ISTREET_HPP
#define ISTREET_HPP
#include "Interactive.hpp"
#include "Random.hpp"
class iStreet : public Interactive
{
private:
	std::ifstream input;
	Random rand;
	
	//STRUCTS CONTAINING DATA FOR THE DIFFERENT TYPE OF ENEMIES TO ENCOUNTER
	struct BoyBand
	{
		std::string name = "Boy Band";
		double screech = 1;
		std::string screechMessage = "Boy Band used Screech, 1 damage!";
		double hairspray = 2;
		std::string hairsprayMessage = "Boy Band used Hairspray, 2 damage!";
		double girlGaggle = 3;
		std::string girlGaggleMessage = "Boy Band used Girl Gaggle, 3 damage!";
		double HP = 10;
	};

	struct FolkBand
	{
		std::string name = "Folk Band";
		double deepLyrics  = 2;
		std::string deepLyricsMessage = "Folk Band used Deep Lyrics, 2 damage!";
		double suspenderWhip = 3;
		std::string suspenderWhipMessage = "Folk Band used Suspender Whip, 3 damage!";
		double banjoSmash = 4;
		std::string banjoSmashMessage = "Folk Band used Banjo Smash, 4 damage!";
		double HP = 10;
	};

	struct JazzBand
	{
		std::string name = "Jazz Band";
		double superiority = 3;
		std::string superiorityMessage = "Jazz Band used Superiority, 3 damage!";
		double radomNote = 4;
		std::string randomNoteMessage = "Jazz Band used Random Note, 4 damage!";
		double saxophoneSmash = 5;
		std::string saxophoneSmashMessage = "Jazz Band used Saxophone Smash, 5 damage!";
		double HP = 10;
	};

	struct Empty
	{
		std::string message = "It was just your imagination...";
	};

	BoyBand bb;
	FolkBand fb;
	JazzBand jb;
	Empty e;
public:
	iStreet();
	void entryMessage();
	void interact(Player *);
	~iStreet();
};
#endif

