#include "AA.hpp"

//DEFAULT CONSTRUCTOR
AA::AA()
{
	graphic = '?';
	access = true;
	interactive = true;
	designator = 'A';
}

//OVERIDE
AA::AA(Space * t, Space * r, Space * b, Space * l, int row, int col) : Space(t, r, b, l, row, col)
{
	graphic = '?';
	access = true;
	interactive = true;
	designator = 'A';
}

void AA::printGraphic()
{
	std::cout << graphic;
}

void AA::positionCharacter()
{
	graphic = 'P';
}

void AA::revealSpace()
{
	graphic = 'A';
}

bool AA::getAccess()
{
	return access;
}

bool AA::getType()
{
	return interactive;
}

char AA::getDesignator()
{
	return designator;
}

AA::~AA()
{
}
