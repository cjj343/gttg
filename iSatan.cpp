#include "iSatan.hpp"

//CONSTRUCTOR SETS UP INTERACTION MENU
iSatan::iSatan()
{
	satanMenu.addMenuItemInt(1, "Sell your soul");
	satanMenu.addMenuItemInt(2, "Dont sell your soul");
}

//PRINT ENTRY MESSAGE
void iSatan::entryMessage()
{
	input.open("satan_intro.txt");
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
void iSatan::interact(Player * character)
{
	std::string userChoice;
	int cleanInt;

	//PRINT MENU
	satanMenu.printMenu();

	//GET AND VALIDATE USER INPUT
	std::getline(std::cin, userChoice);
	cleanInt = validateInt(userChoice);
	cleanInt = satanMenu.getUserInt(cleanInt);

	//SWITCH FOR USER INTERACTION
	switch (cleanInt)
	{
	case 1:
	{
		std::cout << "You have activated a guitar of unimaginable power! Use it to destroy your enemies!" << std::endl;

		//ACTIVATE SPECIAL WEAPON
		character->activateSpecial();

	}
	break;
	case 2:
	{
		std::cout << "Really? Okay, well you still have your soul I guess..." << std::endl;
	}
	break;
	}
}


iSatan::~iSatan()
{
}
