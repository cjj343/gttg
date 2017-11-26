#include "iLS.hpp"

//CONSTRUCTOR SETS MENU OPTIONS
iLS::iLS()
{
	lsMenu.addMenuItemInt(1, "Beer");
	lsMenu.addMenuItemInt(2, "Wine");
	lsMenu.addMenuItemInt(3, "Vodka");
	lsMenu.addMenuItemInt(4, "Exit");
}

//PRINT ENTRY MESSAGE
void iLS::entryMessage()
{
	input.open("ls_intro.txt");
	char temp;

	while (!input.eof())
	{
		temp = input.get();
		std::cout << temp;
	}

	input.close();

	std::cout << std::endl << std::endl;
}

//ACCEPTS PLAYER PTR
//IMPLEMENTS INTERACTION
void iLS::interact(Player * character)
{
	std::string userChoice;
	int cleanInt;

	//LOOP WHILE USER WANTS TO BUY ITEMS
	do
	{
		//PRINT MENU
		lsMenu.printMenu();

		//GET AND VALIDATE USER INPUT
		std::getline(std::cin, userChoice);
		cleanInt = validateInt(userChoice);
		cleanInt = lsMenu.getUserInt(cleanInt);

		//SWITCH FOR MENU
		switch (cleanInt)
		{
		case 1:
		{
			if (character->getMoney() >= character->BEER_COST)
			{
				character->addItem('b');
				std::cout << "1 Beer added to your fanny pack" << std::endl;
			}
			else
			{
				std::cout << "You do not have enough money for this item" << std::endl;
			}

		}
		break;

		case 2:
		{
			if (character->getMoney() >= character->WINE_COST)
			{
				character->addItem('w');
				std::cout << "1 bottle of wine added to your fanny pack" << std::endl;
			}
			else
			{
				std::cout << "You do not have enough money for this item" << std::endl;
			}
		}
		break;

		case 3:
		{
			if (character->getMoney() >= character->VODKA_COST)
			{
				character->addItem('v');
				std::cout << "1 bottle of vodka added to your fanny pack" << std::endl;
			}
			else
			{
				std::cout << "You do not have enough money for this item" << std::endl;
			}
		}
		break;
		case 4:
			break;
		}
	} while (cleanInt != 4);
}


iLS::~iLS()
{
}
