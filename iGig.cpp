#include "iGig.hpp"

iGig::iGig()
{
}

//PRINT ENTRY MESSAGE
void iGig::entryMessage()
{
	input.open("gig_intro.txt");
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
void iGig::interact(Player * character)
{

	//IF CHARACTER HAS ALL GUITAR STRINGS
	if (character->getStrings())
	{
		std::cout << "Dude! Where have you been!? We have a show to play" << std::endl;

		//SET WIN BOOL
		character->setWin();
	}

	else
	{
		std::cout << "Dude! You cant play with broken strings! Come back with a working guitar" << std::endl;
	}
}


iGig::~iGig()
{
}
