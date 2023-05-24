#include"morse.h"

void morseCipher(const char* stringToEncode, char* encodedString, const unsigned mode)
{
	letterPosition position;
	size_t stringToEncodeletterPosition = 0;
	size_t encodedStringLetterPosition = 0;

	while (stringToEncode[stringToEncodeletterPosition] != '\0' && stringToEncodeletterPosition < strlen(stringToEncode))
	{
		switch (mode)
		{
		case DECODE:
		{
			position.lettterInMorseAlphabet = findLetterPositionInMorseAlphabet(stringToEncode, &stringToEncodeletterPosition);
			decode(encodedString, position.letterInEnglishAlphabet, &encodedStringLetterPosition);
			break;
		}
		case ENCODE:
		{
			position.letterInEnglishAlphabet = findLetterPositionInEnglishAlphabet(stringToEncode[stringToEncodeletterPosition]);
			encode(encodedString, position.letterInEnglishAlphabet, &encodedStringLetterPosition);
			stringToEncodeletterPosition++;
			break;
		}
		default:
			break;
		}
	}
	encodedString[encodedStringLetterPosition] = '\0';
}

void morsePlaySound(const char* encodedString)
{
	size_t position = 0;
	while (encodedString[position] != '\0')
	{
		if (encodedString[position] == '.')
		{
			PlaySound(L"dot.wav", 0, SND_SYNC);
		}
		else if (encodedString[position] == '-')
		{
			PlaySound(L"dash.wav", 0, SND_SYNC);
		}
		else if (encodedString[position] == ' ' && encodedString[position + 1] == ' ')
			SILENCE_BETWEEN_WORDS;
		else
			SILENCE_BETWEEN_LETTERS;

		position++;
	}
}

void decode(char* decodedString, const int letterPositionInMorseAlphabet, int* decodedStringPosition)
{
	decodedString[*decodedStringPosition] = alphabet[letterPositionInMorseAlphabet].english;
	(*decodedStringPosition)++;
}

void encode(char* encodedString, const int letterPositionInEnglishAlphabet, int* encodedStringLetterPosition)
{
	size_t position = 0;
	while (alphabet[letterPositionInEnglishAlphabet].morse[position] != '\0')
	{
		encodedString[*encodedStringLetterPosition] = alphabet[letterPositionInEnglishAlphabet].morse[position];
		(*encodedStringLetterPosition)++;
		position++;
	}
	encodedString[*encodedStringLetterPosition] = ' ';
	(*encodedStringLetterPosition)++;
}

