#include "Gig.hpp"

Gig::Gig()
{
	graphic = '?';
	access = true;
	interactive = true;
	designator = 'G';
}

Gig::Gig(Space * t, Space * r, Space * b, Space * l, int row, int col) : Space(t, r, b, l, row, col)
{
	graphic = '?';
	access = true;
	interactive = true;
	designator = 'G';
}

void Gig::printGraphic()
{
	std::cout << graphic;
}

void Gig::positionCharacter()
{
	graphic = 'P';
}

void Gig::revealSpace()
{
	graphic = '!';
}

bool Gig::getAccess()
{
	return access;
}

bool Gig::getType()
{
	return interactive;
}

char Gig::getDesignator()
{
	return designator;
}


Gig::~Gig()
{
}
