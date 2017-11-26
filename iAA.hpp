/**********************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: CLASS IMPLEMENTS CHARACTER INTERACTION WITH
AA SPACES
***********************************************************/
#ifndef IAA_HPP
#define IAA_HPP
#include "Interactive.hpp"

const double SOBRIETY_PENALTY = 1;
const double RUN_PENALTY = .5;
const double BONUS = 2;

class iAA : public Interactive
{
private:
	std::ifstream input;
	Menu aaMenu;
public:
	iAA();
	void entryMessage();
	void interact(Player *);
	~iAA();
};
#endif

