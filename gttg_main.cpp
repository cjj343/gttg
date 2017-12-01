/******************************************************************
*AUHTOR: CAMERON JACKSON
*LAST UPDATED: 11/26/2017
*DESCRIPTION: MAIN, PRINTS RULES AND START MENU.
*******************************************************************/
#include "Game.hpp"
#include <fstream>
#include "Menu.hpp"
#include "Helper.hpp"
#include <string>

int main()
{
	//VARIABLES AND OBJECTS
	Game * driver;
	Menu startMenu;
	std::ifstream input;
	char temp;
	std::string userChoice;
	int cleanInt = 0;

	//CREATE THE OPEING MENU
	startMenu.addMenuItemInt(1, "Play");
	startMenu.addMenuItemInt(2, "Quit");

	//ENTER FULL SCRREEN MODE SO GRAPHIC DISPLAYS CORRECTLY
	std::cout << "Please enter full screen mode" << '\n';
	std::cin.get();
	
	//OPEN FILE FOR GRAPHIC. ART FROM http://www.chris.com/ascii/
	input.open("guitar.txt");

	//PRINT GRAPHIC
	while (!input.eof())
	{
		temp = input.get();
		std::cout << temp;
	}

	//CLOSE THE FILE
	input.close();

	std::cout << std::endl << std::endl;

	//OPEN FILE WITH RULES
	input.open("rules.txt");

	//PRINT THE RULES
	while (!input.eof())
	{
		temp = input.get();
		std::cout << temp;
	}

	//CLOSE THE FILE
	input.close();

	std::cout << std::endl << std::endl;

	//PRINT THE START MENU
	startMenu.printMenu();

	//GET AND VALIDATE USER CHOICE
	std::getline(std::cin, userChoice);
	cleanInt = validateInt(userChoice);
	cleanInt = startMenu.getUserInt(cleanInt);

	//wHILE USER SELCETS PLAY
	while(cleanInt == 1)
	{
		//MAKE NEW GAME
		driver = new Game;
		
		//RUN GAME
		driver->runGame();

		//DELETE GAME
		delete driver;
		driver = nullptr;

		//PRINT THE START MENU
		startMenu.printMenu();

		//GET AND VALIDATE USER CHOICE
		std::getline(std::cin, userChoice);
		cleanInt = validateInt(userChoice);
		cleanInt = startMenu.getUserInt(cleanInt);

	}

	return 0;
}