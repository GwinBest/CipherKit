#include"window-controls.h"

void CreateControls(HWND hWnd)
{
	hTextBox = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		L"edit",
		L"Enter string to encode...",
		WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL | ES_MULTILINE,
		10, 140,
		540, 400,
		hWnd,
		NULL,
		NULL,
		NULL);

	hButton = CreateWindowEx(
		WS_EX_PALETTEWINDOW,
		L"button",
		L"Encode",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		NULL, NULL,
		300, 30,
		hWnd,
		(HMENU)(ON_BUTTON_PRESSED),
		NULL,
		NULL);


	hStaticBox = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		L"edit",
		L"Encoded string...",
		WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL | ES_MULTILINE | ES_READONLY,
		600, 140,
		540, 400,
		hWnd,
		NULL,
		NULL,
		NULL);

	hComboBoxSelectCipher = CreateWindowEx(
		WS_EX_PALETTEWINDOW,
		L"comboBox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
		950, 50,
		150, 150,
		hWnd,
		(HMENU)(COMBO_BOX_CIPHER_SELECT),
		NULL,
		NULL);
	SendMessage(hComboBoxSelectCipher, CB_ADDSTRING, NULL, L"Morse");
	SendMessage(hComboBoxSelectCipher, CB_ADDSTRING, NULL, L"Gronsfeld");
	SendMessage(hComboBoxSelectCipher, CB_ADDSTRING, NULL, L"Caesar");
	SendMessage(hComboBoxSelectCipher, CB_ADDSTRING, NULL, L"Atbash");
	SendMessage(hComboBoxSelectCipher, CB_ADDSTRING, NULL, L"Railfence");
	SendMessage(hComboBoxSelectCipher, CB_SETCURSEL, COMBO_BOX_MORSE_SELECTED, NULL);

	hComboBoxSelectMode = CreateWindowEx(
		WS_EX_PALETTEWINDOW,
		L"comboBox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
		750, 50,
		165, 150,
		hWnd,
		(HMENU)(COMBO_BOX_MODE_SELECT),
		NULL,
		NULL);
	SendMessage(hComboBoxSelectMode, CB_ADDSTRING, NULL, L"Decode");
	SendMessage(hComboBoxSelectMode, CB_ADDSTRING, NULL, L"Encode");
	SendMessage(hComboBoxSelectMode, CB_SETCURSEL, ENCODE, NULL);

	hCheckBox = CreateWindowEx(
		WS_EX_PALETTEWINDOW,
		L"button",
		L"Play morse sound",
		WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		950, 90,
		165, 20,
		hWnd,
		NULL,
		NULL,
		NULL);

	hTextBoxForKey = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,
		L"edit",
		L"Enter the key...",
		WS_CHILD | WS_VISIBLE | ES_NUMBER,
		40, 50,
		165, 30,
		hWnd,
		NULL,
		NULL,
		NULL);
	SendMessage(hTextBoxForKey, EM_SETCUEBANNER, (WPARAM)FALSE, (LPARAM)L"Enter the key...");   //set the placeholder "Enter the key..."
	EnableWindow(hTextBoxForKey, FALSE);                                                       // disable textbox that used for key by default
}

