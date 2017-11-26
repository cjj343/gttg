#include "Random.hpp"

//SEEDS THE RANDOM NUMBER
Random::Random()
{
	seed = time(0);
	srand(seed);
}

//RANDOM NUMBER WITH TWO LIMITS
int Random::rangedRandom(int x, int y)
{
	return rand() % (y - x + 1) + x;
}


int Random::rangelessRandom()
{
	return rand();
}

Random::~Random()
{
}
