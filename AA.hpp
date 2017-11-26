/**************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: AA MAP SPACE
***************************************************/
#ifndef AA_HPP
#define AA_HPP
#include "Space.hpp"
#include <iostream>
class AA :
	public Space
{
private:
	char graphic;
	bool access;
	bool interactive;
	char designator;
public:
	AA();
	AA(Space *, Space *, Space *, Space *, int, int);
	void printGraphic();
	void positionCharacter();
	void revealSpace();
	bool getAccess();
	bool getType();
	char getDesignator();
	~AA();
};
#endif

