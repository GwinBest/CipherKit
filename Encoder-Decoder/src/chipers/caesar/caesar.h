#pragma once

#include"../../mode-settings.h"
#include"../../language/language.h"

/* mode settings:
* DECODE - 0
* ENCODE - 1
*/
void caesarCipher(const char* plainString, char* cipherString, int key, int mode);