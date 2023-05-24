#include"caesar.h"

void caesarCipher(const char* stringToEncode, char* encodedString, int key, int mode)
{
	size_t stringToEncodeLetterPosition = 0;
	while (stringToEncode[stringToEncodeLetterPosition] != '\0')
	{
		int letterPositionInAlphabet = findLetterPositionInEnglishAlphabet(stringToEncode[stringToEncodeLetterPosition]);

		switch (mode)
		{
		case DECODE:
		{
			if (letterPositionInAlphabet == NOT_FOUNDED || letterPositionInAlphabet >= ALPHABET_LENGHT)
			{
				encodedString[stringToEncodeLetterPosition] = stringToEncode[stringToEncodeLetterPosition];
				break;
			}
			else if (letterPositionInAlphabet >= key)
			{
				encodedString[stringToEncodeLetterPosition] = alphabet[letterPositionInAlphabet - key].english;
				break;
			}
			else
				encodedString[stringToEncodeLetterPosition] = alphabet[ALPHABET_LENGHT - (key - letterPositionInAlphabet)].english;
			break;
		}
		case ENCODE:
		{
			if (letterPositionInAlphabet != NOT_FOUNDED && letterPositionInAlphabet < ALPHABET_LENGHT)
				encodedString[stringToEncodeLetterPosition] = alphabet[(letterPositionInAlphabet + key) % ALPHABET_LENGHT].english;
			else
				encodedString[stringToEncodeLetterPosition] = stringToEncode[stringToEncodeLetterPosition];
			break;
		}
		default:
			break;
		}
		stringToEncodeLetterPosition++;
	}
	encodedString[stringToEncodeLetterPosition] = '\0';
}
