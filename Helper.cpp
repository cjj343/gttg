#include <iostream>
#include <cctype>
#include <stdexcept>
#include "Helper.hpp"

//THIS FUNCTION VALIDATES AN INT WITH AN UPPER AND LOWER RANGE.
//ACCEPTS UPPER AND LOWER RANGE AS WELL AS THE INT TO BE VALIDATED. 
//RETURNS VALIDATED INT
int intTwolimits(int z, int x, int y)
{
	std::string userChoice = "";

	while (z < x || z > y)
	{
		std::cout << "Invalid! Please enter a different value..." << std::endl;
		std::getline(std::cin, userChoice);
		z = validateInt(userChoice);
	}

	return z;
}

//THIS FUNCTION VALIDATES AN DOUBLE WITH AN UPPER AND LOWER RANGE. 
//ACCEPTS UPPER AND LOWER RANGE AS WELL AS THE DOUBLE TO BE VALIDATED. 
//RETURNS VALIDATED DOUBLE
double doubleTwoLimits(double z, double x, double y)
{

	std::string userChoice = "";

	while (z < x || z > y)
	{
		std::cout << "Invalid! Please enter a different value..." << std::endl;
		std::getline(std::cin, userChoice);
		z = validateDouble(userChoice);
	}

	return z;
}

char validateCustomChar(char a, char b, char c, char d, char e)
{
	std::string userChoice;

	while (a != b && a != c && a != d && a != e)
	{
		std::cout << "Invalid! Please enter a different value..." << std::endl;
		std::getline(std::cin, userChoice);
		a = validateChar(userChoice);
	}

	return a;
}

//THIS FUNCTION VALIDATES THAT A USER ENTERED A Y OR N.
//RETURNS VALIDATED CHAR
char yesOrNo(char c)
{
	std::string userChoice;

	while (true)
	{
		if (c == 'Y' || c == 'y')
		{
			c = std::toupper(c);
			return c;
		}

		else if (c == 'N' || c == 'n')
		{
			c = std::toupper(c);
			return c;
		}

		else
		{
			std::cout << "Invalid entry! Please enter Y or N (y or n)." << std::endl;
			std::getline(std::cin, userChoice);
			c = validateChar(userChoice);
		}
	}

	return c;
}

//THIS FUNCTION VALIDATES THAT THE USER ENETERED AN UNSIGNED INTEGER.
//ACCEPTS STRING AND RETRUNS INT
int validateInt(std::string s)
{
	bool fail = false;
	int safe = 0;

	if (s.length() == 0)
	{
		fail = true;
	}

	for (size_t i = 0; i < s.length(); i++)
	{
		if (!(std::isdigit(s[i])))
		{
			fail = true;
		}
	}

	if (!fail) //FROM STACK OVERLOW
	{
		try
		{
			safe = std::stoi(s);
		}

		catch (std::out_of_range)
		{
			fail = true;
		}

	}
	

	while (fail)
	{
		fail = false;
		std::cout << "Invalid! Please enter a different value..." << std::endl;
		std::cin.clear();
		s.erase();
		s.empty();
		std::getline(std::cin, s);

		if (s.length() == 0)
		{
			fail = true;
		}

		for (size_t i = 0; i < s.length(); i++)
		{
			if (!(std::isdigit(s[i])))
			{
				fail = true;
			}
		}

		if (!fail)
		{
			try
			{
				safe = std::stoi(s);
			}

			catch (std::out_of_range)
			{
				fail = true;
			}
		}
	}



	safe = std::stoi(s);
	return safe;
}

//THIS FUNCTION VALIDATES THAT THE USER ENETERED AN UNSIGNED OR SIGNED INTEGER. ACCEPTS STRING AND RETRUNS INT
int validateSignedInt(std::string s)
{
	bool fail = false;
	int safe = 0;

	if (s.length() == 0)
	{
		fail = true;
	}

	if (s[0] == '-')
	{
		for (size_t i = 1; i < s.length(); i++)
		{
			if (!(std::isdigit(s[i])))
			{
				fail = true;
			}
		}
	}

	else if (s[0] != '-')
	{
		for (size_t i = 0; i < s.length(); i++)
		{
			if (!(std::isdigit(s[i])))
			{
				fail = true;
			}
		}
	}

	if (!fail)
	{
		try
		{
			safe = std::stoi(s);
		}

		catch (std::out_of_range)
		{
			fail = true;
		}
	}

	while (fail)
	{
		fail = false;
		std::cout << "Invalid! Please enter a different value..." << std::endl;
		std::cin.clear();
		s.erase();
		s.empty();
		std::getline(std::cin, s);

		if (s.length() == 0)
		{
			fail = true;
		}

		if (s[0] == '-')
		{
			for (size_t i = 1; i < s.length(); i++)
			{
				if (!(std::isdigit(s[i])))
				{
					fail = true;
				}
			}
		}

		else if (s[0] != '-')
		{
			for (size_t i = 0; i < s.length(); i++)
			{
				if (!(std::isdigit(s[i])))
				{
					fail = true;
				}
			}
		}

		if (!fail)
		{
			try
			{
				safe = std::stoi(s);
			}

			catch (std::out_of_range )
			{
				fail = true;
			}
		}
	}

	safe = std::stoi(s);
	return safe;
}

//THIS FUNCTION VALIDATES THE USER ENTERED A SINGLE CHAR. ACCEPTS STRING, RETURNS INT
char validateChar(std::string s)
{
	bool fail = false;
	char safeChar;

	if (s.length() != 1)
	{
		fail = true;
	}

	for (size_t i = 0; i < s.length(); i++)
	{
		if (!(std::isalpha(s[i])))
		{
			fail = true;
		}
	}

	while (fail)
	{
		fail = false;
		std::cout << "Invalid! Please enter a different value..." << std::endl;
		std::cin.clear();
		s.erase();
		s.empty();
		std::getline(std::cin, s);

		if (s.length() != 1)
		{
			fail = true;
		}

		for (size_t i = 0; i < s.length(); i++)
		{
			if (!(std::isalpha(s[i])))
			{
				fail = true;
			}
		}
	}

	safeChar = s[0];

	return safeChar;
}


//VALIDATES A DOUBLE, SIGNED OR UNSIGNED
//ACCEPTS STRING
//RETURNS DOUBLE
double validateDouble(std::string s)
{
	bool fail = false;
	int countDot = 0;
	int countDash = 0;

	if (s.length() == 0)
	{
		fail = true;
	}

	if (!fail)
	{
		for (size_t i = 0; i < s.length(); i++)
		{
			if ((std::isalpha(s[i])) || (s[i] == '\n') || (s[i] == '\t') || (s[i] == '\v') || (s[i] == '\b') || (s[i] == '\r') || (s[i] == '\f') || (s[i] == '\a'))
			{
				fail = true;
			}
		}
	}

	if (!fail)
	{
		for (size_t i = 0; i < s.length(); i++)
		{
			if ((!(std::isdigit(s[i]))) && (s[i] != '.') && (s[i] != '-'))
			{
				fail = true;
			}
		}
	}

	if (!fail)
	{
		for (size_t i = 0; i < s.length(); i++)
		{
			if (s[i] == '.')
			{
				countDot++;
			}

			if (s[i] == '-')
			{
				countDash++;
			}
		}

		if (countDot > 1 || countDash > 1)
		{
			fail = true;
		}
	}

	if (!fail) //from stack overflow
	{
		try
		{
			std::stod(s);
		}
		catch (const std::out_of_range )
		{
			fail = true;
		}
	}

	while (fail)
	{
		fail = false;
		countDot = 0;
		countDash = 0;

		std::cout << "Invalid! Please enter a different value..." << std::endl;
		std::getline(std::cin, s);

		if (s.length() == 0)
		{
			fail = true;
		}

		if (!fail)
		{
			for (size_t i = 0; i < s.length(); i++)
			{
				if ((std::isalpha(s[i])) || (s[i] == '\n') || (s[i] == '\t') || (s[i] == '\v') || (s[i] == '\b') || (s[i] == '\r') || (s[i] == '\f') || (s[i] == '\a'))
				{
					fail = true;
				}
			}
		}

		if (!fail)
		{
			for (size_t i = 0; i < s.length(); i++)
			{
				if ((!(std::isdigit(s[i]))) && (s[i] != '.') && (s[i] != '-'))
				{
					fail = true;
				}
			}
		}

		if (!fail)
		{
			for (size_t i = 0; i < s.length(); i++)
			{
				if (s[i] == '.')
				{
					countDot++;
				}

				if (s[i] == '-')
				{
					countDash++;
				}
			}

			if (countDot > 1 || countDash > 1)
			{
				fail = true;
			}
		}

		if (!fail)
		{
			try
			{
				std::stod(s);
			}
			catch (const std::out_of_range)
			{
				fail = true;
			}
		}
	}

	return stod(s);

}
