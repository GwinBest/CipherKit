#pragma once

#include<Windows.h>
#include <CommCtrl.h>

#include"../../mode-settings.h"


enum selectedChiper
{
	COMBO_BOX_MORSE_SELECTED,
	COMBO_BOX_GRONDFELD_SELECTED,
	COMBO_BOX_CAESAR_SELECTED,
	COMBO_BOX_ATBASH_SELECTED,
	COMBO_BOX_RAILFENCE_SELECTED,
	COMBO_BOX_BACONIAN_SELECTED,
	COMBO_BOX_VIGENERE_SELECTED,

};

#define ON_BUTTON_PRESSED                            228
#define COMBO_BOX_CIPHER_SELECT                      229
#define COMBO_BOX_MODE_SELECT                        230

HWND hWindow;
HWND hTextBox;
HWND hButton;
HWND hStaticBox;
HWND hComboBoxSelectCipher;
HWND hComboBoxSelectMode;
HWND hCheckBox;
HWND hTextBoxForKey;

void CreateControls(HWND hWnd);