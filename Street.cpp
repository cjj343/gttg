#include "Street.hpp"

Street::Street()
{
	graphic = ' ';
	access = true;
	interactive = false;
	designator = 's';
}

Street::Street(Space * t, Space * r, Space * b, Space * l, int row, int col) : Space(t, r, b, l, row, col)
{
	graphic = ' ';
	access = true;
	interactive = false;
	designator = 's';
}

void Street::printGraphic()
{
	std::cout << graphic;
}

void Street::positionCharacter()
{
	graphic = 'P';
}

void Street::revealSpace()
{
	graphic = ' ';
}

bool Street::getAccess()
{
	return access;
}

bool Street::getType()
{
	return interactive;
}

char Street::getDesignator()
{
	return designator;
}

Street::~Street()
{
}



