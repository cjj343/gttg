#include "Map.hpp"

//CONSTRUCTOR DOES A LOT OF STUFF
Map::Map()
{
	row = 0;
	col = 0;
	count = 0;
	int type = 0;
	char tempChar;
	head = nullptr;
	tail = nullptr;
	bucket = nullptr;
	temp = nullptr;
	player = nullptr;

	//OPEN KEY FILE
	input.open("key.txt");

	//PUT VALUES IN A VECTOR
	while (!input.eof())
	{
		tempChar = input.get();
		key.push_back(tempChar);
	}

	input.close();

	//FIRST SPACE
	head = new Dead(nullptr, nullptr, nullptr, nullptr, row, col);
	tail = head;
	count++;

	//LOOP THROUGH KEY FILE
	for (size_t i = 1; i < key.size(); i++)
	{
		//ADD TO COL FOR EVERY ITERATION
		col++;

		//IF COL IS GREATER THAN 10 THEN SET BACK TO 0 AND INCREMENT ROW
		if (col > 10)
		{
			col = 0;
			row++;
		}

		//KEY SAYS DEAD SPACE
		//LINK SPACES LEFT TO RIGHT
		if (key[i] == 'X')
		{
			bucket = new Dead(nullptr, nullptr, nullptr, tail, row, col);
			tail->right = bucket;
			tail = bucket;
			bucket = nullptr;

		}

		//KEY SAYS STREET SPACE
		//LINK SPACES LEFT TO RIGHT
		else if (key[i] == ' ')
		{
			bucket = new Street(nullptr, nullptr, nullptr, tail, row, col);
			tail->right = bucket;
			tail = bucket;
			bucket = nullptr;
		}

		//KEY SAYS STORE SPACE
		//LINK SPACES LEFT TO RIGHT
		else if (key[i] == 'S')
		{
			//RANDOMIZE STORE TYPE
			type = rand.rangedRandom(1, 3);

			switch (type)
			{
			case 1:
			{
				bucket = new MusicStore(nullptr, nullptr, nullptr, tail, row, col);
				tail->right = bucket;
				tail = bucket;
				bucket = nullptr;
			}
			break;
			case 2:
			{
				bucket = new LiqourStore(nullptr, nullptr, nullptr, tail, row, col);
				tail->right = bucket;
				tail = bucket;
				bucket = nullptr;
			}
			break;
			case 3:
			{
				bucket = new AA(nullptr, nullptr, nullptr, tail, row, col);
				tail->right = bucket;
				tail = bucket;
				bucket = nullptr;
			}
			break;
			}

		}

		//KEY SAYS SPECIAL SPACE
		//LINK SPACES LEFT TO RIGHT
		else if (key[i] == '!')
		{
			bucket = new Satan(nullptr, nullptr, nullptr, tail, row, col);
			tail->right = bucket;
			tail = bucket;
			bucket = nullptr;
		}

		//KEY SAYS WINNING SPACE
		//LINK SPACES LEFT TO RIGHT
		else if (key[i] == 'G')
		{
			bucket = new Gig(nullptr, nullptr, nullptr, tail, row, col);
			tail->right = bucket;
			tail = bucket;
			bucket = nullptr;
		}
	}

	//RESET 
	bucket = head;
	temp = head;
	count = 0;

	//FIND ELEMENT DIRECLY BELOW FIRST ELEMENT
	while (count < 11)
	{
		temp = temp->right;
		count++;
	}

	//LOOP UNTIL SECOND TO LAST ROW
	while (bucket->row < 10)
	{
		//CONNECT THE TOP AND BOTTOM PTRS
		bucket->bottom = temp;
		temp->top = bucket;

		//PROGRESS ELEMENTS
		bucket = bucket->right;
		temp = temp->right;
	}

	//RESET
	temp = nullptr;
	bucket = head;

	//FIND POSITION [1][1] ON MAP
	while (bucket->row != 1)
	{
		bucket = bucket->right;
	}

	while(bucket->col != 1)
	{
		bucket = bucket->right;
	}

	//PUT PLAYER AT THIS POSITION
	player = bucket;
	player->positionCharacter();
	bucket = nullptr;
}

//PRINTS MAP
void Map::printMap()
{
	bucket = head;
	row = 0;

	//WHILE CURRENT ELEMENT IS NOT THE LAST
	while (bucket != tail)
	{
		//KEEP TRACK OF ROW
		row = bucket->row;

		//PRINT GRAPHIC AT SPACE
		bucket->printGraphic();
		bucket = bucket->right;

		//IF ROW INCREMENTS
		if (bucket->row > row)
		{
			//THEN PRINT A NEW LINE
			std::cout << std::endl;
		}
	}

	//PRINT LAST GRAPHIC AND NEW LINE
	bucket->printGraphic();
	std::cout << std::endl;;
}

//ACCEPTS AND RETURNS CHAR
//MOVES CHARACTER
char Map::moveCharacter(char direction)
{
	bool badMove = false;
	char space = '$';
	std::string userChoice;

	//LOOP UNTIL CHARACTER MAKES A VALID MOVE
	do
	{
		badMove = false;

		//MOVE SWITCH
		switch (direction)
		{
		case 'w'://PLAYER CHOOSES UP
		{
			//IF SPACE IS ACCESSIBLE
			if (player->top->getAccess())
			{
				//IF THE SPACES ARE ADJACENT STORES
				if (player->getType() && player->top->getType())
				{
					std::cout << "Can't move there!" << '\n';
					badMove = true;
					std::getline(std::cin, userChoice);
					direction = validateChar(userChoice);
					direction = validateCustomChar(direction, 'w', 'd', 's', 'a');
				}

				else
				{
					//RESTORE GRAPHIC FOR PREVIOUS SPACE
					player->revealSpace();

					//MOVE PLAYER
					player = player->top;

					//CHANGE GRAPHIC
					player->positionCharacter();

					//RETURNS CHAR FOR SPACE TYPE
					space = player->getDesignator();
					return space;
				}
			}
			else
			{
				std::cout << "Can't move there!" << '\n';
				badMove = true;
				std::getline(std::cin, userChoice);
				direction = validateChar(userChoice);
				direction = validateCustomChar(direction, 'w', 'd', 's', 'a');
			}
		}
		break;
		case 'd': //IF RIGHT
		{
			if (player->right->getAccess())
			{
				if (player->getType() && player->right->getType())
				{
					std::cout << "Can't move there!" << '\n';
					badMove = true;
					std::getline(std::cin, userChoice);
					direction = validateChar(userChoice);
					direction = validateCustomChar(direction, 'w', 'd', 's', 'a');
				}

				else
				{
					player->revealSpace();
					player = player->right;
					player->positionCharacter();
					space = player->getDesignator();
					return space;
				}
			}
			else
			{
				std::cout << "Can't move there!" << '\n';
				badMove = true;
				std::getline(std::cin, userChoice);
				direction = validateChar(userChoice);
				direction = validateCustomChar(direction, 'w', 'd', 's', 'a');
			}
		}
			break;
		case 's': //IF DOWN
		{
			if (player->bottom->getAccess())
			{
				if (player->getType() && player->bottom->getType())
				{
					std::cout << "Can't move there!" << '\n';
					badMove = true;
					std::getline(std::cin, userChoice);
					direction = validateChar(userChoice);
					direction = validateCustomChar(direction, 'w', 'd', 's', 'a');
				}

				else
				{
					player->revealSpace();
					player = player->bottom;
					player->positionCharacter();
					space = player->getDesignator();
					return space;
				}
			}
			else
			{
				std::cout << "Can't move there!" << '\n';
				badMove = true;
				std::getline(std::cin, userChoice);
				direction = validateChar(userChoice);
				direction = validateCustomChar(direction, 'w', 'd', 's', 'a');
			}
		}
			break;
		case 'a': // IF LEFT
		{
			if (player->left->getAccess())
			{
				if (player->getType() && player->left->getType())
				{
					std::cout << "Can't move there!" << '\n';
					badMove = true;
					std::getline(std::cin, userChoice);
					direction = validateChar(userChoice);
					direction = validateCustomChar(direction, 'w', 'd', 's', 'a');
				}

				else
				{
					player->revealSpace();
					player = player->left;
					player->positionCharacter();
					space = player->getDesignator();
					return space;
				}
			}
			else
			{
				std::cout << "Can't move there!" << '\n';
				badMove = true;
				std::getline(std::cin, userChoice);
				direction = validateChar(userChoice);
				direction = validateCustomChar(direction, 'w', 'd', 's', 'a');
			}
		}
			break;
		}
	} while (badMove);

	return space;
}

//CLEAN UP MEMORY
Map::~Map()
{
	bucket = head;

	while (bucket != tail)
	{
		temp = bucket;
		bucket = bucket->right;
		delete temp;
	}

	delete bucket;
	bucket = nullptr;
	head = nullptr;
	tail = nullptr;
	player = nullptr;

}
