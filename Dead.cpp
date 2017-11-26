#include "Dead.hpp"

Dead::Dead()
{
	graphic = 'X';
	access = false;
	interactive = false;
	designator = 'X';
}

Dead::Dead(Space * t, Space * r, Space * b, Space * l, int row, int col) : Space(t, r, b, l, row, col)
{
	graphic = 'X';
	access = false;
	interactive = false;
	designator = 'X';

}

void Dead::positionCharacter()
{
	graphic = 'P';
}

void Dead::printGraphic()
{
	std::cout << graphic;
}

void Dead::revealSpace()
{
	graphic = 'X';
}

bool Dead::getAccess()
{
	return access;
}

bool Dead::getType()
{
	return interactive;
}

char Dead::getDesignator()
{
	return designator;
}

Dead::~Dead()
{
}
