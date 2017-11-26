/******************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: ABSTRACT CLASS FOR INTERACTIVE SPACES
*******************************************************/
#ifndef INTERACTIVE_HPP
#define INTERACTIVE_HPP
#include "Player.hpp"
#include "Menu.hpp"
#include <iostream>
#include <fstream>
#include "Helper.hpp"
#include <string>
#include "Player.hpp"
class Interactive
{ 
public:
	Interactive();
	virtual void entryMessage() = 0;
	virtual void interact(Player *) = 0;
	virtual ~Interactive();
};
#endif

