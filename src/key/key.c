#include"key.h"

int findKeyLength(unsigned key)
{
	size_t length = 0;
	while (key /= 10)
	{
		length++;
	}
	return ++length;
}

int findKeyDigit(const unsigned key, const unsigned keyLength, int* currentDigit)
{
	int KeyDigit = (int)(key / pow(10, keyLength - (*currentDigit))) % 10;
	(*currentDigit)++;
	if ((*currentDigit) > keyLength) //reset currentDigit
		(*currentDigit) = 1;

	return KeyDigit;
}