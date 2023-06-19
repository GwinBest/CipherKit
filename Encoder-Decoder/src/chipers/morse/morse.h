#pragma once

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<Windows.h>

#include"../../language/language.h"
#include"../../mode-settings.h"


#define DOT_DURATION                  100
#define SILENCE_BETWEEN_LETTERS       Sleep(DOT_DURATION/2)
#define SILENCE_BETWEEN_WORDS         Sleep(DOT_DURATION)

typedef union letterPosition_t
{
	int letterInEnglishAlphabet;
	int lettterInMorseAlphabet;

} letterPosition;

/* mode settings :
* DECODE - 0,
* ENCODE - 1
*/
void morseCipher(const char* plainString, char* cipherString, const unsigned mode);
void decode(char* decodedString, const int letterPositionInMorseAlphabet, int* decodedStringPosition);
void encode(char* cipherString, const int letterPositionInEnglishAlphabet, int* cipherStringLetterPosition);
void morsePlaySound(const char* cipherString);
