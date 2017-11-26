#include "Player.hpp"

//CONSTRUCTOR
Player::Player()
{
	//INITIALIZE GAME VARIABLES
	BAC = STARTING_BAC;
	strings = FULL_STRINGS;
	money = STARTING_MONEY;
	itemCount = STARTING_ITEMS;
	win = false;

	//GIVE PLAYER THREE FREE ITEMS IN  STARTING PACK
	fannyPack.push_back(new Item("Beer", BEER_HEALTH, FREE));
	fannyPack.push_back(new Item("Beer", BEER_HEALTH, FREE));
	fannyPack.push_back(new Item("Beer", BEER_HEALTH, FREE));

	//INITIALIZE ATTACK TYPES
	//DEFAULT ATTACKS
	attack[0] = new attackType("Hair Whip", HAIRWHIP_DAMAGE, FREE, true);
	attack[1] = new attackType("Shred", SHRED_DAMAGE, FREE, true);
	attack[2] = new attackType("Guitar Bash", BASH_DAMAGE, FREE, true);

	//SPECIAL ATTACKS
	attack[3] = new attackType("Ninja Picks", NINJA_DAMAGE, NINJA_COST, false);
	attack[4] = new attackType("Whammy Crow Bar", WHAMMY_DAMAGE, WHAMMY_COST, false);
	attack[5] = new attackType("???", GORETAR_DAMAGE, FREE, false);

}

//ACCEPTS DOUBLE THAT IS ENEMY DAMAGE
//SUBTRACTS FROM HEALTH
//HEALTH CANNOT BE NEGATIVE
void Player::loseBAC(double damage)
{
	BAC -= damage;

	if (BAC < 0)
	{
		BAC = 0;
	}
}

//ADDS HEALTH
//HEALTH CANNOT BE GREATER THAN 20
void Player::addBAC(double health)
{
	BAC += health;

	if (BAC > STARTING_BAC)
	{
		BAC = STARTING_BAC;
	}
}

//GET
double Player::getBAC()
{
	return BAC;
}

//GET
double Player::getMoney()
{
	return money;
}

//FUNCTION ADDS ITEM TO FANNY PACK
//ACCEPTS CHAR TO INDICATE TYPE OF ITEM TO ADD
void Player::addItem(char item)
{
	//IF ITEM COUNT IS LESS THAN MAX ITEMS(10)
	if (itemCount < MAX_ITEMS)
	{
		switch (item)
		{
		case 'b': //IF BEER
		{
			//ADD NEW BEER TO FANNY PACK
			fannyPack.push_back(new Item("Beer", BEER_HEALTH, BEER_COST));

			//SUBTRACT COST OF LAST ELEMENT FROM MONEY
			money -= fannyPack.back()->cost;

			//ADD TO ITEM COUNT
			itemCount++;
		}
		break;
		case 'w': //IF WINE
		{
			//ADD WINE TO FANNY PACK
			fannyPack.push_back(new Item("Wine", WINE_HEALTH, WINE_COST));

			//SUBTRACT COST
			money -= fannyPack.back()->cost;

			//ADD TO ITEM COUNT
			itemCount++;

		}
		break;
		case 'v': //IF VODKA
		{
			//ADD VODKA TO FANNY PACK
			fannyPack.push_back(new Item("Vodka", VODKA_HEALTH, VODKA_COST));

			//SUBTRACT COST
			money -= fannyPack.back()->cost;

			//ADD TO ITEM COUNT
			itemCount++;

		}
		break;
		}
	}

	//IF PACK IS FULL
	else
	{
		std::cout << "Fanny pack is full" << std::endl;
	}
}

//USE ATTACK FUNCTION
//RETURNS DOULBE THAT IS DAMAGE
double Player::useAttack()
{
	std::string userChoice;
	int cleanInt;
	Menu attackMenu;

	//CREATE MENU FOR ATTACKS
	for (int i = 0; i < 6; i++)
	{
		attackMenu.addMenuItemInt((i + 1), attack[i]->name);
	}

	//GET AND VALIDATE USER CHOICE
	attackMenu.printMenu();
	std::getline(std::cin, userChoice);
	cleanInt = validateInt(userChoice);
	cleanInt = attackMenu.getUserInt(cleanInt);


	switch (cleanInt)
	{
	case 1: //IF HAIR WHIP
	{
		std::cout << "You used " << attack[0]->name << ", " << attack[0]->damage << " damage" << std::endl;
		return attack[0]->damage;
	}
	break;
	case 2: //IF SHRED
	{
		std::cout << "You used " << attack[1]->name << ", " << attack[1]->damage << " damage" << std::endl;
		return attack[1]->damage;
	}
	break;
	case 3: //IF GUITAR BASH
	{
		//IF ENOUGH STRINGS
		if (attack[2]->active)
		{
			std::cout << "You used " << attack[2]->name << ", " << attack[2]->damage << " damage" << std::endl;

			//BREAK A STRING FOR EVERY USE
			strings--;

			//SUBTRACT DAMAGE FROM SHRED
			attack[1]->damage -= .5;

			//IF STRINGS ARE NOW ZERO
			if (strings == 0)
			{
				//CHANGE ACTIVE TO FALSE
				attack[2]->active = false;
			}

			return attack[2]->damage;
		}

		//IF NO STRINGS
		else
		{
			std::cout << "You do not have enough strings on your guitar to use this move" << std::endl;

			//RETURN ERROR FLAG
			return -1;
		}
	}
	break;
	case 4: //IF NINJA PICKS
	{
		if (attack[3]->active)
		{
			std::cout << "You used " << attack[3]->name << ", " << attack[3]->damage << " damage" << std::endl;

			//ONE TIME USE WEAPON, CHANGE TO FALSE AFTER USE
			attack[3]->active = false;
			return attack[3]->damage;
		}

		else
		{
			std::cout << "Out of this weapon. Visit a music store to get more" << std::endl;

			//RETURN ERROR FLAG
			return -1;
		}
	}
	break;
	case 5: //IF WHAMMY CROW BAR
	{
		if (attack[4]->active)
		{
			std::cout << "You used " << attack[4]->name << ", " << attack[4]->damage << " damage" << std::endl;

			//ONE TIME USE WEAPON, CHANGE TO FALSE AFTER USE
			attack[4]->active = false;

			return attack[4]->damage;
		}

		else
		{
			std::cout << "Out of this weapon. Visit a music store to get more" << std::endl;

			//RETURN ERROR FLAG
			return -1;
		}

	}
	break;
	case 6: //IF GORETAR
	{
		if (attack[5]->active)
		{
			std::cout << "You used " << attack[5]->name << ", " << attack[5]->damage << " damage" << std::endl;
			return attack[5]->damage;
		}

		else
		{
			std::cout << "You have not unlocked this weapon" << std::endl;

			//RETURN ERROR FLAG
			return -1;
		}
	}
	break;
	}

	//RETURN ERROR FLAG
	return -1;
}

//ADD MONEY TO BANK
//MONEY EARNED FROM FIGHTS
void Player::addMoney(double m)
{
	money += m;
}

//FUNCTION ALLOWS PLAYER TO USE ITEM
void Player::useItem()
{
	Menu itemMenu;
	int count = 1;
	std::string userChoice;
	int cleanInt;
	
	//PLAYER DOESNT NEED AN ITEM IF AT MAX HEALTH
	if (BAC < 20)
	{
		//IF THERE ARE ITEMS IN THE PACK
		if (!fannyPack.empty())
		{

			//CREATE A MENU
			for (size_t i = 0; i < fannyPack.size(); i++)
			{
				itemMenu.addMenuItemInt((i + 1), fannyPack[i]->name);
			}

			//PRINT MENU
			itemMenu.printMenu();

			//GET AND VALIDATE USER INPUT
			std::getline(std::cin, userChoice);
			cleanInt = validateInt(userChoice);
			cleanInt = itemMenu.getUserInt(cleanInt);

			//ADD THAT ITEMS HEALTH VALUE TO PLAYER'S HEALTH
			BAC += fannyPack[cleanInt - 1]->health;

			if (BAC > STARTING_BAC)
			{
				BAC = STARTING_BAC;
			}

			//STATUS MESSAGE
			std::cout << "You used a " << fannyPack[cleanInt - 1]->name << std::endl;
			std::cout << "BAC: " << BAC << std::endl;

			//DELETE ITEM AND REMOVE ELEMENT FROM VECTOR
			delete fannyPack[cleanInt - 1];
			fannyPack.erase(fannyPack.begin() + (cleanInt - 1));

			//SUBTRACT FROM ITEM COUNT
			itemCount--;
		}

		else
		{
			std::cout << "Your fanny pack is empty" << std::endl;
		}
	}

	else
	{
		std::cout << "You are already max wasted!" << std::endl;
	}
}

//FUNCTION RESTORES STRINGS TO MAX
void Player::restoreStrings()
{
	money -= REPAIR_COST;
	strings = 6;
}

//ACTIVATES SPECIAL NINJA PICK WEAPON
void Player::activateNinja()
{
	money -= attack[3]->cost;
	attack[3]->active = true;
}

//ACTIVATES SPECIAL WHAMMY WEAPON
void Player::activateWhammy()
{
	money -= attack[4]->cost;
	attack[4]->active = true;
}

//ACTIVATES SPECIAL GORETAR WEAPON
void Player::activateSpecial()
{
	attack[5]->name = "Goretar";
	attack[5]->active = true;
}

//FUNCTION USED TO DETERMINE IF PLAYER CAN WIN GAME
//MUST HAVE ALL SIX STRINGS TO WIN GAME
bool Player::getStrings()
{
	if (strings == 6)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//SETS WIN VALUE
void Player::setWin()
{
	win = true;
}

//RETURNS WIN
bool Player::getWin()
{
	return win;
}

//PRINTS VITAL STATS
void Player::printStats()
{
	std::cout << "BAC: " << BAC << std::endl;
	std::cout << "Money: $" << money << std::endl;
	std::cout << "Strings: " << strings << std::endl;
}

bool Player::fannyPackStatus()
{
	if (fannyPack.size() > 0)
	{
		return true;
	}

	return false;
}


//CLEAN UP MEMORY
Player::~Player()
{
	for (int i = 0; i < 6; i++)
	{
		if (attack[i] != nullptr)
		{
			delete attack[i];
			attack[i] = nullptr;
		}
	}

	if (!(fannyPack.empty()))
	{
		for (size_t i = 0; i < fannyPack.size(); i++)
		{
			if (fannyPack[i] != nullptr)
			{
				delete fannyPack[i];
				fannyPack[i] = nullptr;
			}
		}
	}

}
