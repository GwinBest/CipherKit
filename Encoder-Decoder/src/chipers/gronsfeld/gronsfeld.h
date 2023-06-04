#pragma once

#include"../../language/language.h"
#include"../../mode-settings.h"
#include"../../key/key.h"

#include<math.h>
#include<string.h>


/* mode settings:
* DECODE - 0
* ENCODE - 1
*/
void gronsfeldCipher(const char* plainString, char* cipherString, const unsigned key, const unsigned mode);