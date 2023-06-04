#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"../../mode-settings.h"
#include"../../bool.h"

void railfenceCipher(const char* plainString, char* cipherString, const unsigned ralisCount, const unsigned mode);
void railfenceDecode(const char* cipherString, const unsigned railsCount, char* plainString);
void railfenceEncode(const char* plainString, const unsigned railsCount, char* cipherString, const unsigned plainStringLength);