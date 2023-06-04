#include "atbash.h"

void atbashCipher(const char* plainStiring, char* cipherString)
{
	size_t plainStiringLetterPosition = 0;
	while (plainStiring[plainStiringLetterPosition] != '\0')
	{
		int letterPositionInAlphabet = findLetterPositionInEnglishAlphabet(plainStiring[plainStiringLetterPosition]);

		if (letterPositionInAlphabet != NOT_FOUNDED && letterPositionInAlphabet < ALPHABET_LENGHT)
			cipherString[plainStiringLetterPosition] = alphabet[ALPHABET_LENGHT - letterPositionInAlphabet - 1].english;  //ALPHABET_LENGHT macro includes space symbol, so we use -1 to remove it
		else
			cipherString[plainStiringLetterPosition] = plainStiring[plainStiringLetterPosition];

		plainStiringLetterPosition++;
	}

	cipherString[plainStiringLetterPosition] = '\0';
}
