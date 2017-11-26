/*********************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION:
	- RUN GAME FUNCTION CONTROLS PLAYER INTERACTION WITH
	GAME SPACES
	- RUNS WHILE CHARACTER STILL HAS LIFE AND THE GAME
	HAS NOT BEEN WON
*********************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Map.hpp"
#include "Helper.hpp"
#include "Player.hpp"
#include "iAA.hpp"
#include "iLS.hpp"
#include "iStreet.hpp"
#include "iMS.hpp"
#include "iSatan.hpp"
#include "iGig.hpp"
#include "Interactive.hpp"
#include <iostream>
#include <fstream>
class Game
{
private:
	Map board;
	char spaceType;
	Player * character;
	Interactive * driver;
	std::ifstream input;
public:
	Game();
	void runGame();
	~Game();
};
#endif

