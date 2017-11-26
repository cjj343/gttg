/**************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: MUSIC STORE MAP SPACE
***************************************************/
#ifndef MUSICSTORE_HPP
#define MUSICSTORE_HPP
#include "Space.hpp"
#include <iostream>
class MusicStore :
	public Space
{
private:
	char graphic;
	bool access;
	bool interactive;
	char designator;
public:
	MusicStore();
	MusicStore(Space *, Space *, Space *, Space *, int, int);
	void printGraphic();
	void positionCharacter();
	void revealSpace();
	bool getAccess();
	bool getType();
	char getDesignator();
	~MusicStore();
};
#endif
