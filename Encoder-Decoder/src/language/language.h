#pragma once 

#include<string.h>


#define ALPHABET_LENGHT                       26
#define ADDITIONAL_MORSE_SYMBOLS_COUNT        31
#define MAX_LENGHT_OF_MORSE_SYMBOL            8
#define SPACE_POSITION                        26

#define NOT_FOUNDED                          -1

typedef struct
{
	char english;
	char morse[MAX_LENGHT_OF_MORSE_SYMBOL];

} aplhabet;

static aplhabet alphabet[ALPHABET_LENGHT + ADDITIONAL_MORSE_SYMBOLS_COUNT] =
{
	{'a',   ".-"},
	{'b', "-..."},
	{'c', "-.-."},
	{'d',  "-.."},
	{'e',    "."},
	{'f', "..-."},
	{'g',  "--."},
	{'h', "...."},
	{'i',   ".."},
	{'j', ".---"},
	{'k',  "-.-"},
	{'l', ".-.."},
	{'m',   "--"},
	{'n',   "-."},
	{'o',  "---"},
	{'p', ".--."},
	{'q', "--.-"},
	{'r',  ".-."},
	{'s',  "..."},
	{'t',    "-"},
	{'u',  "..-"},
	{'v', "...-"},
	{'w',  ".--"},
	{'x', "-..-"},
	{'y', "-.--"},
	{'z', "--.."},

	{' ',    " "},
	{'0',"-----"},
	{'1',".----"},
	{'2',"..---"},
	{'3',"...--"},
	{'4',"....-"},
	{'5',"....."},
	{'6',"-...."},
	{'7',"--..."},
	{'8',"---.."},
	{'9',"----."},
	{'.',".-.-.-"},
	{',',"--..--"},
	{'?',"..--.."},
	{'\'',".----."},
	{'!',"-.-.--"},
	{'/',"-..-."},
	{'(',"-.--."},
	{')',"-.--.-"},
	{'&',".-..."},
	{':',"---..."},
	{';',"-.-.-."},
	{'=',"-...-"},
	{'+',".-.-."},
	{'-',"-....-"},
	{'_',"..--.-"},
	{'"',".-..-."},
	{'$',"...-..-"},
	{'@',".--.-."},
	{'¿',"..-.-"},
	{'¡',"--...-"},

};

int findLetterPositionInEnglishAlphabet(const char letter);
int findLetterPositionInMorseAlphabet(const char* string, int* stringLetterPosition);
void lettersToLower(char* string);