#include "LiqourStore.hpp"

LiqourStore::LiqourStore()
{
	graphic = '?';
	access = true;
	interactive = true;
	designator = 'L';
}

LiqourStore::LiqourStore(Space * t, Space * r, Space * b, Space * l, int row, int col) : Space(t, r, b, l, row, col)
{
	graphic = '?';
	access = true;
	interactive = true;
	designator = 'L';
}

void LiqourStore::printGraphic()
{
	std::cout << graphic;
}

void LiqourStore::positionCharacter()
{
	graphic = 'P';
}

void LiqourStore::revealSpace()
{
	graphic = 'L';
}

bool LiqourStore::getAccess()
{
	return access;
}

bool LiqourStore::getType()
{
	return interactive;
}

char LiqourStore::getDesignator()
{
	return designator;
}


LiqourStore::~LiqourStore()
{
}
