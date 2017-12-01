#include "Game.hpp"

//CONSTRUCTOR SETS POINTERS TO NULL
Game::Game()
{
	driver = nullptr;
	character = nullptr;
}

//RUN GAME CONTROLS INTERACTION WITH SPACES
void Game::runGame()
{
	char cleanChar;
	std::string userChoice;

	//DYNAMICALLY ALLOCATED PLAYER SO THAT NEW CHARACTER IS CREATED FOR NEW GAMES
	character = new Player();

	//LOOP WHILE THE GAME IS NOT OVER AND THE CHARACTER HAS LIFE
	while((character->getBAC() > 0) && (!(character->getWin())))
	{
		//PRINT MAP
		board.printMap();
		std::cout << std::endl;

		//PRINT STATS
		character->printStats();
		std::cout << std::endl;

		std::cout << "Make a move..." << std::endl;

		//GET A DIRECTION FROM THE USER AND VALIDATE
		std::getline(std::cin, userChoice);
		cleanChar = validateChar(userChoice);
		cleanChar = validateCustomChar(cleanChar, 'w', 'd', 's', 'a');
		
		//MOVE THE CHARACTER, GET THE SPACE AND PRINT THE MAP
		spaceType = board.moveCharacter(cleanChar);
		board.printMap();

		//SWITCH CONTROLS THE SPACE TYPE
		switch (spaceType)
		{
		case 'A'://IF SPACE IS ALCOHOLICS ANON SPACE
		{
			//MAKE A NEW INTERACTIVE OBJECT FOR THIS SPACE
			driver = new iAA();

			//DISPLAY THE ENTRY MESSAGE
			driver->entryMessage();

			//PASS CHARACTER POINTER TO INTERACT WITH THE SPACE
			driver->interact(character);

			//DELETE THE SPACE
			delete driver;
			driver = nullptr;

		}
			break;
		case 'G'://IF SPACE IS GIG SPACE
		{
			driver = new iGig();

			driver->entryMessage();

			driver->interact(character);

			delete driver;
			driver = nullptr;
		}
		break;
		case 'S'://IF SPACE IS SATAN SPACE
		{
			driver = new iSatan();

			driver->entryMessage();

			driver->interact(character);

			delete driver;
			driver = nullptr;

		}
		break;
		case 's'://IF SPACE IS STREET SPACE
		{
			driver = new iStreet();

			driver->entryMessage();

			driver->interact(character);

			delete driver;
			driver = nullptr;

		}
		break;
		case 'L': //IF SPACE IS LIQUOR STORE SPACE
		{
			driver = new iLS();

			driver->entryMessage();

			driver->interact(character);

			delete driver;
			driver = nullptr;

		}
		break;
		case 'M': //IF SPACE IS MUSIC STORE SPACE
		{
			driver = new iMS();

			driver->entryMessage();

			driver->interact(character);

			delete driver;
			driver = nullptr;
		}
		break;
		}

		//DONT DISPLAY IF PLAYER HAS ENTERED THE WINNING SPACE
		if (!(character->getWin()) && (character->fannyPackStatus()) && (character->getBAC() < character->STARTING_BAC))
		{
			//AFTER EACH INTERACTION ASK IF USER WANTS TO USE ITEM FROM PACK
			//PLAYER CAN DIE IN A FIGHT AND STILL USER ITEM FROM PACK TO BE REVIVED, FIGHT DOES NOT RESUME AFTERWARDS
			std::cout << "Would you like to use an item from your fanny pack? (Y or N)" << std::endl;
			std::getline(std::cin, userChoice);
			cleanChar = validateChar(userChoice);
			cleanChar = yesOrNo(cleanChar);

			while ((cleanChar == 'Y') && (character->fannyPackStatus()) && (character->getBAC() < character->STARTING_BAC))
			{
				character->useItem();

				if (character->getBAC() < character->STARTING_BAC)
				{
					std::cout << "Would you like to use another item from your fanny pack? (Y or N)" << std::endl;
					std::getline(std::cin, userChoice);
					cleanChar = validateChar(userChoice);
					cleanChar = yesOrNo(cleanChar);
				}
			}
		}
	}

	//TEST TO SEE IF THE PLAYER HAS WON
	if (character->getWin())
	{
		std::cout << "You won!" << std::endl;

		std::cout << std::endl << std::endl;

		//BEER.TXT FROM http://www.chris.com/ascii/
		input.open("beer.txt");
		char temp;

		//PRINT GRAPHIC
		while (!input.eof())
		{
			temp = input.get();
			std::cout << temp;
		}

		//CLOSE THE FILE
		input.close();

		std::cout << std::endl << std::endl;
	}

	else
	{
		std::cout << "You dead. Try again..." << std::endl;
	}
}

//FREE MEMORY
Game::~Game()
{
	if (driver != nullptr)
	{
		delete driver;
		driver = nullptr;
	}

	if (character != nullptr)
	{
		delete character;
		character = nullptr;
	}
}
