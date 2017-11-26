#include "Space.hpp"



Space::Space()
{
	top = nullptr;
	right = nullptr;
	bottom = nullptr;
	left = nullptr;
}

Space::Space(Space * t, Space * r, Space * b, Space * l, int row, int col)
{
	top = t;
	right = r;
	bottom = b;
	left = l;
	this->row = row;
	this->col = col;
}


Space::~Space()
{
}
