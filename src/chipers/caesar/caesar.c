#include"caesar.h"

void caesarCipher(const char* plainString, char* cipherString, int key, int mode)
{
	size_t plainStringLetterPosition = 0;
	while (plainString[plainStringLetterPosition] != '\0')
	{
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
			else if (letterPositionInAlphabet >= key)
			{
				cipherString[plainStringLetterPosition] = alphabet[letterPositionInAlphabet - key].english;
				break;
			}
			else
				cipherString[plainStringLetterPosition] = alphabet[ALPHABET_LENGHT - (key - letterPositionInAlphabet)].english;
			break;
		}
		case ENCODE:
		{
			if (letterPositionInAlphabet != NOT_FOUNDED && letterPositionInAlphabet < ALPHABET_LENGHT)
				cipherString[plainStringLetterPosition] = alphabet[(letterPositionInAlphabet + key) % ALPHABET_LENGHT].english;
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
