/**********************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: CLASS IMPLEMENTS CHARACTER INTERACTION WITH
MUSIC STORE SPACES
***********************************************************/
#ifndef IMS_HPP
#define IMS_HPP
#include "Interactive.hpp"
class iMS :
	public Interactive
{
private:
	std::ifstream input;
	Menu msMenu;
public:
	iMS();
	void entryMessage();
	void interact(Player *);
	~iMS();
};
#endif

