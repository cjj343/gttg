/**********************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: CLASS IMPLEMENTS CHARACTER INTERACTION WITH
GIG SPACE
***********************************************************/
#ifndef IGIG_HPP
#define IGIG_HPP
#include "Interactive.hpp"
class iGig :
	public Interactive
{
private:
	std::ifstream input;
public:
	iGig();
	void entryMessage();
	void interact(Player *);
	~iGig();
};
#endif
