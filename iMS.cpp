#include "iMS.hpp"

//CONSTRUCTORE CREATES CLASS MENU
iMS::iMS()
{
	msMenu.addMenuItemInt(1, "Strings");
	msMenu.addMenuItemInt(2, "Ninja Picks");
	msMenu.addMenuItemInt(3, "Whammy Crow Bar");
	msMenu.addMenuItemInt(4, "Exit");
}

//PRINT ENTRY MESSAFE
void iMS::entryMessage()
{
	input.open("ms_intro.txt");
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
void iMS::interact(Player * character)
{
	std::string userChoice;
	int cleanInt;

	//LOOP WHILE PLAYER WANTS TO KEEP BUYING ITEMS
	do
	{
		//PRINT MENU
		msMenu.printMenu();

		//GET AND VALIDATE USER INPUT
		std::getline(std::cin, userChoice);
		cleanInt = validateInt(userChoice);
		cleanInt = msMenu.getUserInt(cleanInt);

		//MENU SWITCH
		switch (cleanInt)
		{
		case 1:
		{
			if ((character->getMoney() >= character->REPAIR_COST) && !(character->getStrings()))
			{
				character->restoreStrings();
				std::cout << "Strings restored" << std::endl;
			}
			else
			{
				if (character->getMoney() < character->REPAIR_COST)
				{
					std::cout << "You do not have enough money for this item" << std::endl;
				}
				else if (character->getStrings())
				{
					std::cout << "Your guitar is in working order" << std::endl;
				}
			}

		}
		break;

		case 2:
		{
			if (character->getMoney() >= character->NINJA_COST && !(character->getNinja()))
			{
				character->activateNinja();
				std::cout << "Ninja Picks now available" << std::endl;
			}
			else
			{
				if (character->getMoney() < character->NINJA_COST)
				{
					std::cout << "You do not have enough money for this item" << std::endl;
				}
				else if (character->getNinja())
				{
					std::cout << "This item is already active" << std::endl;
				}
			}
		}
		break;

		case 3:
		{
			if (character->getMoney() >= character->WHAMMY_COST && !(character->getWhammy()))
			{
				character->activateWhammy();
				std::cout << "Whammy Crow Bar now active" << std::endl;
			}
			else
			{
				if (character->getMoney() < character->WHAMMY_COST)
				{
					std::cout << "You do not have enough money for this item" << std::endl;
				}
				else if (character->getWhammy())
				{
					std::cout << "This item is already active" << std::endl;
				}
			}
		}
		break;
		case 4:
			break;
		}
	} while (cleanInt != 4);
}


iMS::~iMS()
{
}
