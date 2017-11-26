/**********************************************************************************************
Author: Cameron Jackson
Date: 10/9/2017
Description: This class is a generic utility class that generates random numbers
***********************************************************************************************/

#ifndef RANDOM_HPP
#define RANDOM_HPP
#include <ctime>
#include <cstdlib>
class Random
{
private:
	time_t seed;
public:
	Random();
	int rangedRandom(int x, int y);
	int rangelessRandom();
	~Random();
};
#endif

