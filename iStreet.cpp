#include "iStreet.hpp"

iStreet::iStreet()
{
}

//PRINTS SET UP FOR SPACE
void iStreet::entryMessage()
{
	input.open("street_intro.txt");
	char temp;

	while (!input.eof())
	{
		temp = input.get();
		std::cout << temp;
	}

	input.close();

	std::cout << std::endl << std::endl;
}

//ACCEPTS CHARACTER POINTER
//ALLOWS CHARACTER TO INTERACT WITH SPACE
void iStreet::interact(Player * character)
{
	int enemy = rand.rangedRandom(1, 4);
	double attack = 0;
	int first = 0;
	int enemyAttack = 0;
	int money = 0;

	//GENERATE RANDOM ENEMY
	switch (enemy)
	{
	case 1: //BOY BAND
	{
		std::cout << "A Boy Band approaches! Prepare for a fight!" << std::endl;

		//LOOP UNTIL ONE CHARACTER DIES
		while ((character->getBAC() > 0) && (bb.HP > 0))
		{
			//DETERMINE WHO ATTACKS FIRST
			first = rand.rangedRandom(1, 2);

			//PLAYER ATTACKS FIRST
			if (first == 1)
			{
				std::cout << "You attack first. Choose an attack" << std::endl;
				
				//LOOP UNTIL A VALID ATTACK IS CHOSEN
				do
				{
					attack = character->useAttack();

				} while (attack == -1);

				//SUBTRACT ATTACK DAMAGE FROM ENEMY HP
				bb.HP -= attack;

				//HP CANNOT BE LESS THAN ZERO
				if (bb.HP < 0)
				{
					bb.HP = 0;
				}

				//IF PLAYER STILL ALIVE
				if (bb.HP > 0)
				{
					//GENERATE RANDOM ENEMY ATTACK
					enemyAttack = rand.rangedRandom(1, 3);

					switch (enemyAttack)
					{
					case 1: //ATTACK 1
					{
						//PRINT MESSAGE
						std::cout << bb.screechMessage << std::endl;

						//SUBTRACT FROM CHARACTER HEALTH
						character->loseBAC(bb.screech);
					}
					break;

					case 2: //ATTACK 2
					{
						std::cout << bb.hairsprayMessage << std::endl;
						character->loseBAC(bb.hairspray);

					}
					break;

					case 3: //ATTACK 3
					{
						std::cout << bb.girlGaggleMessage << std::endl;
						character->loseBAC(bb.girlGaggle);
					}
					break;
					}

				}

				//PRINT END OF ROUND STATS
				std::cout << bb.name << " HP: " << bb.HP << std::endl;
				std::cout << "BAC: " << character->getBAC() << std::endl;
			}

			//IF ENEMY ATTACKS FIRST
			else
			{
				std::cout << bb.name << " attacks first" << std::endl;

				enemyAttack = rand.rangedRandom(1, 3);

				switch (enemyAttack)
				{
				case 1:
				{
					std::cout << bb.screechMessage << std::endl;
					character->loseBAC(bb.screech);
				}
				break;

				case 2:
				{
					std::cout << bb.hairsprayMessage << std::endl;
					character->loseBAC(bb.hairspray);

				}
				break;

				case 3:
				{
					std::cout << bb.girlGaggleMessage << std::endl;
					character->loseBAC(bb.girlGaggle);
				}
				break;
				}

				if (character->getBAC() > 0)
				{
					std::cout << "Choose an attack" << std::endl;

					do
					{
						attack = character->useAttack();

					} while (attack == -1);

					bb.HP = bb.HP - attack;

					if (bb.HP < 0)
					{
						bb.HP = 0;
					}
				}

				std::cout << bb.name << " HP: " << bb.HP << std::endl;
				std::cout << "BAC: " << character->getBAC() << std::endl;
			}
		}
	}
	break;
	case 2: //FOLK BAND
	{
		std::cout << "A Folk Band approaches! Prepare for a fight!" << std::endl;

		while ((character->getBAC() > 0) && (fb.HP > 0))
		{
			first = rand.rangedRandom(1, 2);

			if (first == 1)
			{
				std::cout << "You attack first. Choose an attack" << std::endl;

				do
				{
					attack = character->useAttack();

				} while (attack == -1);

				fb.HP -= attack;

				if (fb.HP < 0)
				{
					fb.HP = 0;
				}

				if (fb.HP > 0)
				{
					enemyAttack = rand.rangedRandom(1, 3);

					switch (enemyAttack)
					{
					case 1:
					{
						std::cout << fb.deepLyricsMessage << std::endl;
						character->loseBAC(fb.deepLyrics);
					}
					break;

					case 2:
					{
						std::cout << fb.suspenderWhipMessage << std::endl;
						character->loseBAC(fb.suspenderWhip);

					}
					break;

					case 3:
					{
						std::cout << fb.banjoSmashMessage << std::endl;
						character->loseBAC(fb.banjoSmash);
					}
					break;
					}

				}

				std::cout << fb.name << " HP: " << fb.HP << std::endl;
				std::cout << "BAC: " << character->getBAC() << std::endl;
			}

			else
			{
				std::cout << fb.name << " attacks first" << std::endl;

				enemyAttack = rand.rangedRandom(1, 3);

				switch (enemyAttack)
				{
				case 1:
				{
					std::cout << fb.deepLyricsMessage << std::endl;
					character->loseBAC(fb.deepLyrics);
				}
				break;

				case 2:
				{
					std::cout << fb.suspenderWhipMessage << std::endl;
					character->loseBAC(fb.suspenderWhip);

				}
				break;

				case 3:
				{
					std::cout << fb.banjoSmashMessage << std::endl;
					character->loseBAC(fb.banjoSmash);
				}
				break;
				}

				if (character->getBAC() > 0)
				{
					std::cout << "Choose an attack" << std::endl;

					do
					{
						attack = character->useAttack();

					} while (attack == -1);

					fb.HP -= attack;

					if (fb.HP < 0)
					{
						fb.HP = 0;
					}
				}
			}

			std::cout << fb.name << " HP: " << fb.HP << std::endl;
			std::cout << "BAC: " << character->getBAC() << std::endl;
		}
	}
	break;
	case 3: //JAZZ BAND
	{
		std::cout << "A Jazz Band approaches! Prepare for a fight!" << std::endl;

		while ((character->getBAC() > 0) && (jb.HP > 0))
		{
			first = rand.rangedRandom(1, 2);

			if (first == 1)
			{
				std::cout << "You attack first. Choose an attack" << std::endl;

				do
				{
					attack = character->useAttack();

				} while (attack == -1);

				jb.HP -= attack;

				if (jb.HP < 0)
				{
					jb.HP = 0;
				}

				if (jb.HP > 0)
				{
					enemyAttack = rand.rangedRandom(1, 3);

					switch (enemyAttack)
					{
					case 1:
					{
						std::cout << jb.superiorityMessage << std::endl;
						character->loseBAC(jb.superiority);
					}
					break;

					case 2:
					{
						std::cout << jb.randomNoteMessage << std::endl;
						character->loseBAC(jb.radomNote);

					}
					break;

					case 3:
					{
						std::cout << jb.saxophoneSmashMessage << std::endl;
						character->loseBAC(jb.saxophoneSmash);
					}
					break;
					}

				}

				std::cout << jb.name << " HP: " << jb.HP << std::endl;
				std::cout << "BAC: " << character->getBAC() << std::endl;
			}

			else
			{
				std::cout << jb.name << " attacks first" << std::endl;

				enemyAttack = rand.rangedRandom(1, 3);

				switch (enemyAttack)
				{
				case 1:
				{
					std::cout << jb.superiorityMessage << std::endl;
					character->loseBAC(jb.superiority);
				}
				break;

				case 2:
				{
					std::cout << jb.randomNoteMessage << std::endl;
					character->loseBAC(jb.radomNote);

				}
				break;

				case 3:
				{
					std::cout << jb.saxophoneSmashMessage << std::endl;
					character->loseBAC(jb.saxophoneSmash);
				}
				break;
				}

				if (character->getBAC() > 0)
				{
					std::cout << "Choose an attack" << std::endl;

					do
					{
						attack = character->useAttack();

					} while (attack == -1);

					jb.HP -= attack;

					if (jb.HP < 0)
					{
						jb.HP = 0;
					}
				}
			}

			std::cout << jb.name << " HP: " << jb.HP << std::endl;
			std::cout << "BAC: " << character->getBAC() << std::endl;
		}
	}
	break;
	case 4: //NO ENEMY
	{
		std::cout << e.message << std::endl;
	}
	break;
	}

	//IF CHARACTER SURVIVED THE FIGHT
	if (character->getBAC() > 0 && enemy != 4)
	{
		//GENERATE A RANDOM DOLLAR AMOUNT
		money = rand.rangedRandom(0, 5);

		std::cout << "You earned $" << money << "!" << std::endl;

		//ADD IT TO CHARACTER'S BANK
		character->addMoney(static_cast<double>(money));
	}

}


iStreet::~iStreet()
{
}
