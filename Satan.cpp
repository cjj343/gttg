#include "Satan.hpp"

Satan::Satan()
{
	graphic = 'X';
	access = true;
	interactive = false;
	designator = 'S';
}

Satan::Satan(Space * t, Space * r, Space * b, Space * l, int row, int col) : Space(t, r, b, l, row, col)
{
	graphic = 'X';
	access = true;
	interactive = false;
	designator = 'S';
}

void Satan::printGraphic()
{
	std::cout << graphic;
}

void Satan::positionCharacter()
{
	graphic = 'P';
}

void Satan::revealSpace()
{
	graphic = '!';
	access = false;
}

bool Satan::getAccess()
{
	return access;
}

bool Satan::getType()
{
	return interactive;
}

char Satan::getDesignator()
{
	return designator;
}


Satan::~Satan()
{
}
