/**************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: LIQUOUR STORE MAP SPACE
***************************************************/
#ifndef LIQOURSTORE_HPP
#define LIQOURSTORE_HPP
#include "Space.hpp"
#include <iostream>
class LiqourStore :
	public Space
{
private:
	char graphic;
	bool access;
	bool interactive;
	char designator;
public:
	LiqourStore();
	LiqourStore(Space *, Space *, Space *, Space *, int, int);
	void printGraphic();
	void positionCharacter();
	void revealSpace();
	bool getAccess();
	bool getType();
	char getDesignator();
	~LiqourStore();
};
#endif

