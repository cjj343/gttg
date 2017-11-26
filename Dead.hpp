/**************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: DEAD MAP SPACE
***************************************************/
#ifndef DEAD_HPP
#define DEAD_HPP
#include "Space.hpp"
#include <iostream>
class Dead :
	public Space
{
private:
	char graphic;
	bool access;
	bool interactive;
	char designator;
public:
	Dead();
	Dead(Space *, Space *, Space *, Space *, int, int);
	void positionCharacter();
	void printGraphic();
	void revealSpace();
	bool getAccess();
	bool getType();
	char getDesignator();
	~Dead();
};
#endif
