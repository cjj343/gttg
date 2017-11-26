#include "iAA.hpp"

//CONSTRUCTOR SETS UP INTERACTION MENU
iAA::iAA()
{
	aaMenu.addMenuItemInt(1, "Get sober");
	aaMenu.addMenuItemInt(2, "Crack open a beer");
	aaMenu.addMenuItemInt(3, "Run");
}

//PRINT ENTRY MESSAGE
void iAA::entryMessage()
{
	input.open("aa_intro.txt");
	char temp;

	while (!input.eof())
	{
		temp = input.get();
		std::cout << temp;
	}

	input.close();

	std::cout << std::endl << std::endl;
}

//ACCEPTS PTR TO CHARACTER
//IMPLEMENTS INTERACTION WITH SPACE
void iAA::interact(Player * character)
{
	std::string userChoice;
	int cleanInt;

	//PRINT THE MENU
	aaMenu.printMenu();

	//GET AND VALIDATE USER INPUT
	std::getline(std::cin, userChoice);
	cleanInt = validateInt(userChoice);
	cleanInt = aaMenu.getUserInt(cleanInt);

	//SWITCH FOR CHARACTER ACTION
	switch (cleanInt)
	{
	case 1:
	{
		std::cout << "Sobriety failed! Lose " << SOBRIETY_PENALTY << " BAC" << std::endl;
		character->loseBAC(SOBRIETY_PENALTY);
	}
		break;

	case 2:
	{
		std::cout << "Bold move Cotton! Gain " << BONUS << " BAC and bonus Beer" << std::endl;
		character->addBAC(BONUS);
	}
	break;

	case 3:
	{
		std::cout << "You made it out, but not quck enough. Lose " << RUN_PENALTY << " BAC" << std::endl;
		character->loseBAC(RUN_PENALTY);
	}
	break;
	}
}


iAA::~iAA()
{
}
