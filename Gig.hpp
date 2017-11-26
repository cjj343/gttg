/**************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: GIG MAP SPACE
***************************************************/
#ifndef GIG_HPP
#define GIG_HPP
#include "Space.hpp"
#include <iostream>
class Gig : public Space
{
private:
	char graphic;
	bool access;
	bool interactive;
	char designator;
public:
	Gig();
	Gig(Space *, Space *, Space *, Space *, int, int);
	void printGraphic();
	void positionCharacter();
	void revealSpace();
	bool getAccess();
	bool getType();
	char getDesignator();
	~Gig();
};
#endif

