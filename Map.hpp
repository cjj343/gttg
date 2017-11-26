/*********************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: CREATES MAP AND COTROLS CHARACTER MOVEMENT
*********************************************************/
#ifndef MAP_HPP
#define MAP_HPP
#include "Space.hpp"
#include "Street.hpp"
#include "Dead.hpp"
#include "Gig.hpp"
#include "Random.hpp"
#include "MusicStore.hpp"
#include "LiqourStore.hpp"
#include "AA.hpp"
#include "Satan.hpp"
#include "Helper.hpp"
#include <vector>
#include <fstream>
class Map
{
private:
	Space * head;
	Space * tail;
	Space * bucket;
	Space * temp;
	Space * player;
	Random rand;
	std::vector<char> key;
	std::ifstream input;
	int row;
	int col;
	int count;
public:
	Map();
	void printMap();
	char moveCharacter(char);
	~Map();
};
#endif

