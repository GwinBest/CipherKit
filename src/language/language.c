#include "language.h"

int findLetterPositionInEnglishAlphabet(const char letter)
{
	size_t letterPosition = 0;
	while (letter != alphabet[letterPosition].english)
	{
		if (++letterPosition >= ALPHABET_LENGHT + ADDITIONAL_MORSE_SYMBOLS_COUNT)
			return NOT_FOUNDED;
	}
	return letterPosition;
}

int findLetterPositionInMorseAlphabet(const char* string, int* stringLetterPosition)
{
	int size = 0;
	char morseLetter[MAX_LENGHT_OF_MORSE_SYMBOL] = " ";

	while (string[*stringLetterPosition] != ' ' && string[*stringLetterPosition] != '\0')
	{
		if (size >= MAX_LENGHT_OF_MORSE_SYMBOL)
			return NOT_FOUNDED;

		morseLetter[size++] = string[*stringLetterPosition];
		(*stringLetterPosition)++;
	}
	(*stringLetterPosition)++;

	if (morseLetter[0] == ' ') // if morse symbol is ' '
		size++;

	morseLetter[size] = '\0';

	for (int letterPosition = 0; letterPosition < ALPHABET_LENGHT + ADDITIONAL_MORSE_SYMBOLS_COUNT; letterPosition++)
	{
		int position = 0;
		int counter = 0;
		while (morseLetter[position] != '\0')
		{
			if (morseLetter[position] == alphabet[letterPosition].morse[position])
			{
				counter++;
			}
			else
			{
				counter = 0;
				break;
			}
			position++;
		}

		if (counter == strlen(alphabet[letterPosition].morse))
			return letterPosition;
	}

	return NOT_FOUNDED;
}

void lettersToLower(char* string)
{
	int letterPosition = 0;
	while (string[letterPosition] != '\0')
	{
		if (string[letterPosition] >= 'A' && string[letterPosition] <= 'Z')
			string[letterPosition] += 'a' - 'A';
		letterPosition++;
	}
}


