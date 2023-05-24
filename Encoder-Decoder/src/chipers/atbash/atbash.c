#include "atbash.h"

void atbashCipher(const char* stringToEncode, char* encodedString)
{
	size_t stringToEncodeLetterPosition = 0;
	while (stringToEncode[stringToEncodeLetterPosition] != '\0')
	{
		int letterPositionInAlphabet = findLetterPositionInEnglishAlphabet(stringToEncode[stringToEncodeLetterPosition]);

		if (letterPositionInAlphabet != NOT_FOUNDED && letterPositionInAlphabet < ALPHABET_LENGHT)
			encodedString[stringToEncodeLetterPosition] = alphabet[ALPHABET_LENGHT - letterPositionInAlphabet - 1].english;  //ALPHABET_LENGHT macro includes space symbol, so we use -1 to remove it
		else
			encodedString[stringToEncodeLetterPosition] = stringToEncode[stringToEncodeLetterPosition];

		stringToEncodeLetterPosition++;
	}

	encodedString[stringToEncodeLetterPosition] = '\0';
}
