#include "MusicStore.hpp"

MusicStore::MusicStore()
{
	graphic = '?';
	access = true;
	interactive = true;
	designator = 'M';
}

MusicStore::MusicStore(Space * t, Space * r, Space * b, Space * l, int row, int col) : Space(t, r, b, l, row, col)
{
	graphic = '?';
	access = true;
	interactive = true;
	designator = 'M';
}

void MusicStore::printGraphic()
{
	std::cout << graphic;
}

void MusicStore::positionCharacter()
{
	graphic = 'P';
}

void MusicStore::revealSpace()
{
	graphic = 'M';
}

bool MusicStore::getAccess()
{
	return access;
}

bool MusicStore::getType()
{
	return interactive;
}

char MusicStore::getDesignator()
{
	return designator;
}


MusicStore::~MusicStore()
{
}
