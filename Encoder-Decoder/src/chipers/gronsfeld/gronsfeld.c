#include "gronsfeld.h"

void gronsfeldCipher(const char* stringToEncode, char* encodedString, const unsigned key, const unsigned mode)
{
	int keyLength = findKeyLength(key);
	int currentDigit = 1;

	size_t stringToEncodeLetterPosition = 0;
	while (stringToEncode[stringToEncodeLetterPosition] != '\0')
	{
		int keyDigit = findKeyDigit(key, keyLength, &currentDigit);

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
			else if (letterPositionInAlphabet > keyDigit)
			{
				encodedString[stringToEncodeLetterPosition] = alphabet[letterPositionInAlphabet - keyDigit].english;
				break;
			}
			else
				encodedString[stringToEncodeLetterPosition] = alphabet[ALPHABET_LENGHT - (keyDigit - letterPositionInAlphabet)].english;
			break;
		}
		case ENCODE:
		{
			if (letterPositionInAlphabet != NOT_FOUNDED && letterPositionInAlphabet < ALPHABET_LENGHT)
				encodedString[stringToEncodeLetterPosition] = alphabet[(letterPositionInAlphabet + keyDigit) % ALPHABET_LENGHT].english;
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
