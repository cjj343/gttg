/**************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: AA MAP SPACE
***************************************************/
#ifndef SATAN_HPP
#define SATAN_HPP
#include "Space.hpp"
#include <iostream>
class Satan :
	public Space
{
private:
	char graphic;
	bool access;
	bool interactive;
	char designator;
public:
	Satan();
	Satan(Space *, Space *, Space *, Space *, int, int);
	void printGraphic();
	void positionCharacter();
	void revealSpace();
	bool getAccess();
	bool getType();
	char getDesignator();
	~Satan();
};
#endif

