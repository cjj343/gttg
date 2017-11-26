/**********************************************************************************************
Author: Cameron Jackson
Date: 10/9/2017
Description: This class is a generic utility class that handles menu tasks.  This
version can create a menu with numbered or lettered choices.  It also handles and validates
the user selection.
***********************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>
#include "Helper.hpp"

class Menu
{
private:
	std::string type;
	std::vector<int>choiceNum;
	std::vector<char>choiceChar;
	std::vector<std::string>choiceDescription;
public:
	Menu();
	Menu(std::string s);
	void addMenuItemChar(char c, std::string s);
	void addMenuItemInt(int x, std::string s);
	void printMenu();
	int getUserInt(int x);
	char getUserChar(char c);
	~Menu();
};

#endif

