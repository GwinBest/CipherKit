#include "gronsfeld.h"

void gronsfeldCipher(const char* plainString, char* cipherString, const unsigned key, const unsigned mode)
{
	int keyLength = findKeyLength(key);
	int currentDigit = 1;

	size_t plainStringLetterPosition = 0;
	while (plainString[plainStringLetterPosition] != '\0')
	{
		int keyDigit = findKeyDigit(key, keyLength, &currentDigit);

		int letterPositionInAlphabet = findLetterPositionInEnglishAlphabet(plainString[plainStringLetterPosition]);

		switch (mode)
		{
		case DECODE:
		{
			if (letterPositionInAlphabet == NOT_FOUNDED || letterPositionInAlphabet >= ALPHABET_LENGHT)
			{
				cipherString[plainStringLetterPosition] = plainString[plainStringLetterPosition];
				break;
			}
			else if (letterPositionInAlphabet >= keyDigit)
			{
				cipherString[plainStringLetterPosition] = alphabet[letterPositionInAlphabet - keyDigit].english;
				break;
			}
			else
				cipherString[plainStringLetterPosition] = alphabet[ALPHABET_LENGHT - (keyDigit - letterPositionInAlphabet)].english;
			break;
		}
		case ENCODE:
		{
			if (letterPositionInAlphabet != NOT_FOUNDED && letterPositionInAlphabet < ALPHABET_LENGHT)
				cipherString[plainStringLetterPosition] = alphabet[(letterPositionInAlphabet + keyDigit) % ALPHABET_LENGHT].english;
			else
				cipherString[plainStringLetterPosition] = plainString[plainStringLetterPosition];
			break;
		}
		default:
			break;
		}
		plainStringLetterPosition++;
	}
	cipherString[plainStringLetterPosition] = '\0';
}
