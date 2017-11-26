/**********************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: CLASS IMPLEMENTS CHARACTER INTERACTION WITH
BONUS SPACE
***********************************************************/
#ifndef ISATAN_HPP
#define ISATAN_HPP
#include "Interactive.hpp"
class iSatan :
	public Interactive
{
private:
	std::ifstream input;
	Menu satanMenu;
public:
	iSatan();
	void entryMessage();
	void interact(Player *);
	~iSatan();
};
#endif

