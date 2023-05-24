#pragma once

#include"../../mode-settings.h"
#include"../../language/language.h"

/* mode settings:
* DECODE - 0
* ENCODE - 1
*/
void caesarCipher(const char* stringToEncode, char* encodedString, int key, int mode);