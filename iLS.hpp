/**********************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: CLASS IMPLEMENTS CHARACTER INTERACTION WITH
LIQOUR STORE SPACES
***********************************************************/
#ifndef ILS_HPP
#define ILS_HPP
#include "Interactive.hpp"
class iLS : public Interactive
{
private:
	std::ifstream input;
	Menu lsMenu;
public:
	iLS();
	void entryMessage();
	void interact(Player *);
	~iLS();
};
#endif

