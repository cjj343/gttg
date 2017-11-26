/**************************************************************
*AUTHOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: PLAYER CLASS
***************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <vector>
#include "Menu.hpp"
#include <iostream>
#include <string>
#include "Helper.hpp"
class Player
{
private:
	double BAC;
	int strings;
	double money;
	int itemCount;
	bool win;

	struct attackType
	{
		std::string name;
		double damage;
		double cost;
		bool active;
		attackType(std::string n, double d, double c, bool a)
		{
			name = n;
			damage = d;
			cost = c;
			active = a;
		}
	};

	struct Item
	{
		std::string name;
		double health;
		double cost;
		Item(std::string n, double h, double c)
		{
			name = n;
			health = h;
			cost = c;
		}
	};

	std::vector<Item *> fannyPack;
	attackType * attack[6];
public:
	const double STARTING_BAC = 20;
	const double STARTING_MONEY = 25;
	const int STARTING_ITEMS = 3;
	const int MAX_ITEMS = 10;
	const double REPAIR_COST = 5;
	const int FULL_STRINGS = 6;
	const double BEER_HEALTH = 5;
	const double BEER_COST = 3;
	const double WINE_HEALTH = 10;
	const double WINE_COST = 5;
	const double VODKA_HEALTH = 20;
	const double VODKA_COST = 10;
	const double FREE = 0;
	const double HAIRWHIP_DAMAGE = 3;
	const double SHRED_DAMAGE = 5;
	const double BASH_DAMAGE = 10;
	const double NINJA_DAMAGE = 6;
	const double NINJA_COST = 3;
	const double WHAMMY_DAMAGE = 7;
	const double WHAMMY_COST = 4;
	const double GORETAR_DAMAGE = 1000000;
	Player();
	void loseBAC(double);
	void addBAC(double);
	double getBAC();
	double getMoney();
	void addItem(char);
	double useAttack();
	void addMoney(double);
	void useItem();
	void restoreStrings();
	void activateNinja();
	void activateWhammy();
	void activateSpecial();
	bool getStrings();
	void setWin();
	bool getWin();
	void printStats();
	bool fannyPackStatus();
	~Player();
};
#endif
