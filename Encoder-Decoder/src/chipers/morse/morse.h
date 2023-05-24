#pragma once

#include"../../language/language.h"
#include"../../mode-settings.h"

#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<stdio.h>

#define DOT_DURATION                  100
#define SILENCE_BETWEEN_LETTERS       Sleep(DOT_DURATION/2)
#define SILENCE_BETWEEN_WORDS         Sleep(DOT_DURATION)

typedef union
{
	int letterInEnglishAlphabet;
	int lettterInMorseAlphabet;

} letterPosition;

/* mode settings :
* DECODE - 0,
* ENCODE - 1
*/
void morseCipher(const char* stringToEncode, char* encodedString, const unsigned mode);
void decode(char* decodedString, const int letterPositionInMorseAlphabet, int* decodedStringPosition);
void encode(char* encodedString, const int letterPositionInEnglishAlphabet, int* encodedStringLetterPosition);
void morsePlaySound(const char* encodedString);
