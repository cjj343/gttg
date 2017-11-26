/************************************************************************************
Author: Cameron Jackson
Last Updated: 10/16/2017
Description: This file contains various helper functions.  At last update, can do the
following:
	- validate int
	- validate double
	- validate signed int
	- validate single char
	- validate int within range
	- validate double within range
	- validate Y or N
*************************************************************************************/

#ifndef HELPER_HPP
#define HELPER_HPP
#include <string>

int validateInt(std::string s);
double validateDouble(std::string);
int validateSignedInt(std::string s);
char validateChar(std::string s);
int intTwolimits(int z, int x, int y);
double doubleTwoLimits(double, double, double);
char validateCustomChar(char, char, char, char, char);
char yesOrNo(char c);


#endif // !HELPER_H