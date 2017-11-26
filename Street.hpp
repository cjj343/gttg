/**************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: STREET MAP SPACE
***************************************************/
#ifndef STREET_HPP
#define STREET_HPP
#include "Space.hpp"
#include <iostream>
class Street :
	public Space
{
private:
	char graphic;
	bool access;
	bool interactive;
	char designator;
public:
	Street();
	Street(Space * t, Space * r, Space * b, Space * l, int row, int col);
	void printGraphic();
	void positionCharacter();
	void revealSpace();
	bool getAccess();
	bool getType();
	char getDesignator();
	~Street();
};
#endif
