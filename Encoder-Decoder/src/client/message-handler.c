#include"message-handler.h"

LRESULT CALLBACK fnMessageProcessor(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_CREATE:
	{
		MainWindowCreateMenu(hWnd);
		CreateControls(hWnd);
		UpdateWindow(hWindow);
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case ON_BUTTON_PRESSED:
		{
			int keySize = GetWindowTextLengthW(hTextBoxForKey) + 1;
			char* inputedKey = (char*)malloc(keySize);                  // by default this inputed key is just a simple string
			GetWindowTextA(hTextBoxForKey, inputedKey, keySize);
			int convertedToIntKey = atoi(inputedKey);                  //we need to convert inputed key to integer

			int sizeOfString = GetWindowTextLengthW(hTextBox) + 1;
			char* plainString = (char*)malloc(sizeOfString);
			char* cipherString = (char*)malloc(sizeOfString * MAX_LENGHT_OF_MORSE_SYMBOL);
			GetWindowTextA(hTextBox, plainString, sizeOfString);
			lettersToLower(plainString);

			int selectedCipher = SendMessage(hComboBoxSelectCipher, CB_GETCURSEL, NULL, NULL);
			BOOL isEncodeMode = SendMessage(hComboBoxSelectMode, CB_GETCURSEL, NULL, NULL);

			switch (selectedCipher)
			{
			case COMBO_BOX_MORSE_SELECTED:
			{
				if (isEncodeMode)
				{
					morseCipher(plainString, cipherString, ENCODE);
					if (SendMessage(hCheckBox, BM_GETCHECK, NULL, NULL) == BST_CHECKED)
						morsePlaySound(cipherString);
				}
				else
				{
					morseCipher(plainString, cipherString, DECODE);
					if (SendMessage(hCheckBox, BM_GETCHECK, NULL, NULL) == BST_CHECKED)
						morsePlaySound(plainString);
				}
				SendMessageA(hStaticBox, WM_SETTEXT, NULL, cipherString);
				break;
			}
			case COMBO_BOX_GRONDFELD_SELECTED:
			{
				if (isEncodeMode)
					gronsfeldCipher(plainString, cipherString, convertedToIntKey, ENCODE);
				else
					gronsfeldCipher(plainString, cipherString, convertedToIntKey, DECODE);
				SendMessageA(hStaticBox, WM_SETTEXT, NULL, cipherString);
				break;
			}
			case COMBO_BOX_CAESAR_SELECTED:
			{
				if (convertedToIntKey > 9)
				{
					MessageBox(NULL, L"Wrong input. Inputed key must be in range 0-9", L"Warning", MB_OK | MB_ICONWARNING);
					break;
				}

				if (isEncodeMode)
					caesarCipher(plainString, cipherString, convertedToIntKey, ENCODE);
				else
					caesarCipher(plainString, cipherString, convertedToIntKey, DECODE);
				SendMessageA(hStaticBox, WM_SETTEXT, NULL, cipherString);
				break;

			}
			case COMBO_BOX_ATBASH_SELECTED:
			{
				atbashCipher(plainString, cipherString);
				SendMessageA(hStaticBox, WM_SETTEXT, NULL, cipherString);
				break;
			}
			case COMBO_BOX_RAILFANCE_SELECTED:
			{
				if (isEncodeMode)
					railfenceCipher(plainString, cipherString, convertedToIntKey, ENCODE);
				else
					railfenceCipher(plainString, cipherString, convertedToIntKey, DECODE);

				SendMessageA(hStaticBox, WM_SETTEXT, NULL, cipherString);
			}
			default:
			{
				break;
			}
			}
			free(inputedKey);
			free(cipherString);
			free(plainString);
			break;
		}
		case COMBO_BOX_CIPHER_SELECT:
		{
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				int selectedItem = SendMessage(hComboBoxSelectCipher, CB_GETCURSEL, NULL, NULL);
				if (selectedItem == COMBO_BOX_MORSE_SELECTED || selectedItem == COMBO_BOX_ATBASH_SELECTED)
				{
					EnableWindow(hCheckBox, TRUE);                                         // enable checkbox
					EnableWindow(hTextBoxForKey, FALSE);                                  // disable text box that used for key
					SendMessage(hTextBoxForKey, WM_SETTEXT, NULL, L"Enter the key...");  /* set the "Enter the key..." text that used as placeholder when morse cipher selected
																							because when textbox is disabled the placeholder is diabled as well*/
				}
				else
				{
					EnableWindow(hCheckBox, FALSE);                                 // disable the checkbox
					SendMessage(hCheckBox, BM_SETCHECK, BST_UNCHECKED, NULL);      // uncheck the checkbox
					SendMessage(hTextBoxForKey, WM_SETTEXT, NULL, NULL);          // remove the "Enter the key..." text that used as placeholder when morse cipher selected
					EnableWindow(hTextBoxForKey, TRUE);                          // enable text box that used for key 
				}
			}
			break;
		}
		case COMBO_BOX_MODE_SELECT:
		{
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				switch (SendMessage(hComboBoxSelectMode, CB_GETCURSEL, NULL, NULL))
				{
				case DECODE:
				{
					SendMessage(hButton, WM_SETTEXT, NULL, L"Decode");   // set the button text "Decode"
					break;
				}
				case ENCODE:
				{
					SendMessage(hButton, WM_SETTEXT, NULL, L"Encode");  // set the button text "Encode"
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		default:
		{
			break;
		}
		}
		break;
	}
	case WM_SIZING:
	{
		RECT* rect = (RECT*)lParam;

		if (rect->right - rect->left < MAIN_WINDOW_MIN_WIDTH)
		{
			if (wParam == WMSZ_LEFT || wParam == WMSZ_BOTTOMLEFT || wParam == WMSZ_TOPLEFT)
				rect->left = rect->right - MAIN_WINDOW_MIN_WIDTH;
			else
				rect->right = rect->left + MAIN_WINDOW_MIN_WIDTH;
		}
		if (rect->bottom - rect->top < MAIN_WINDOW_MIN_HEIGHT)
		{
			if (wParam == WMSZ_TOP || wParam == WMSZ_TOPLEFT || wParam == WMSZ_TOPRIGHT)
				rect->top = rect->bottom - MAIN_WINDOW_MIN_HEIGHT;
			else
				rect->bottom = rect->top + MAIN_WINDOW_MIN_HEIGHT;
		}
		break;
	}
	case WM_SIZE:
	{
		RECT clientWindowRect;
		GetClientRect(hWindow, &clientWindowRect);

		double clientWindowWidth = (clientWindowRect.right - clientWindowRect.left);
		double clientWindowHeight = (clientWindowRect.bottom - clientWindowRect.top);

		// set button size
		double buttonWidth = clientWindowWidth / BUTTON_WIDTH_RATE;
		double buttonHeight = clientWindowRect.bottom / BUTTON_HEIGHT_RATE;

		// set button position
		double buttonX = clientWindowWidth / 2 - buttonWidth / 2;
		double buttonY = clientWindowHeight - buttonHeight - 50;

		if (buttonWidth <= BUTTON_MIN_WIDTH)
			buttonWidth = BUTTON_MIN_WIDTH;
		if (buttonHeight <= BUTTON_MIN_HEIGHT)
			buttonHeight = BUTTON_MIN_HEIGHT;

		//draw button
		SetWindowPos(hButton, NULL, (int)buttonX, (int)buttonY, (int)buttonWidth, (int)buttonHeight, SWP_NOZORDER);



		//set textBox size
		double textBoxWidth = clientWindowWidth / TEXT_BOX_WIDTH_RATE;
		double textBoxHeight = clientWindowHeight / TEXT_BOX_HEIGHT_RATE;

		//set textBox position
		double textBoxX = clientWindowWidth / TEXT_BOX_X_POSITION_RATE;
		double textBoxY = clientWindowHeight / TEXT_BOX_Y_POSITION_RATE;

		// draw textBox
		SetWindowPos(hTextBox, NULL, (int)textBoxX, (int)textBoxY, (int)textBoxWidth, (int)textBoxHeight, SWP_NOZORDER);



		//set staticBox size
		double staticBoxWidth = clientWindowWidth / TEXT_BOX_WIDTH_RATE;
		double staticBoxHeight = clientWindowHeight / TEXT_BOX_HEIGHT_RATE;

		//set staticBox position
		double staticBoxX = clientWindowWidth / STATIC_BOX_X_POSITION_RATE;
		double staticBoxY = clientWindowHeight / TEXT_BOX_Y_POSITION_RATE;

		//draw staticBox
		SetWindowPos(hStaticBox, NULL, (int)staticBoxX, (int)staticBoxY, (int)staticBoxWidth, (int)staticBoxHeight, SWP_NOZORDER);



		//set ComboBoxSelectCipher size
		double comboBoxSelectCipherWidth = clientWindowWidth / COMBO_BOX_WIDTH_RATE;
		double comboBoxSelectCipherHeight = clientWindowHeight / COMBO_BOX_HEIGHT_RATE;

		//set ComboBoxSelectCipher position
		double comboBoxSelectCipherX = clientWindowWidth / COMBO_BOX_CIPHER_SELECT_X_POSITION_RATE;
		double comboBoxSelectCipherY = clientWindowHeight / COMBO_BOX_POSITION_Y_RATE;

		//draw ComboBoxSelectCipher
		SetWindowPos(hComboBoxSelectCipher, NULL, (int)comboBoxSelectCipherX, (int)comboBoxSelectCipherY,
			(int)comboBoxSelectCipherWidth, (int)comboBoxSelectCipherHeight, SWP_NOZORDER);



		//set ComboBoxSelectMode size
		double comboBoxSelectModeWidth = clientWindowWidth / COMBO_BOX_WIDTH_RATE;
		double comboBoxSelectModeHeight = clientWindowHeight / COMBO_BOX_HEIGHT_RATE;

		//set ComboBoxSelectMode position
		double comboBoxSelectModeX = clientWindowWidth / COMBO_BOX_MODE_SELECT_X_POSITION_RATE;
		double comboBoxSelectModeY = clientWindowHeight / COMBO_BOX_POSITION_Y_RATE;

		//draw ComboBoxSelectMode
		SetWindowPos(hComboBoxSelectMode, NULL, (int)comboBoxSelectModeX, (int)comboBoxSelectModeY,
			(int)comboBoxSelectModeWidth, (int)comboBoxSelectModeHeight, SWP_NOZORDER);

		//set ComboBoxSelectMode size
		double checkBoxWidth = clientWindowWidth / CHECK_BOX_WIDTH_RATE;
		double checkBoxHeight = clientWindowHeight / CHECK_BOX_HEIGHT_RATE;

		//set ComboBoxSelectMode position
		double checkBoxX = clientWindowWidth / CHECK_BOX_POSITION_X_RATE;
		double checkBoxY = clientWindowHeight / CHECK_BOX_POSITION_Y_RATE;

		//draw ComboBoxSelectMode
		SetWindowPos(hCheckBox, NULL, (int)checkBoxX, (int)checkBoxY, (int)checkBoxWidth, (int)checkBoxHeight, SWP_NOZORDER);



		//set TextBoxForKey size
		double textBoxForKeyWidth = clientWindowWidth / TEXT_BOX_FOR_KEY_WIDTH_RATE;
		double textBoxForKeyHeight = clientWindowHeight / TEXT_BOX_FOR_KEY_HEIGHT_RATE;

		//set TextBoxForKey position
		double textBoxForKeyX = clientWindowWidth / TEXT_BOX_FOR_KEY_X_POSITION_RATE;
		double textBoxForKeyY = clientWindowHeight / TEXT_BOX_FOR_KEY_Y_POSITION_RATE;

		if (textBoxForKeyHeight >= TEXT_BOX_FOR_KEY_MAX_HEIGHT)
			textBoxForKeyHeight = TEXT_BOX_FOR_KEY_MAX_HEIGHT;

		//draw TextBoxForKey
		SetWindowPos(hTextBoxForKey, NULL, (int)textBoxForKeyX, (int)textBoxForKeyY, (int)textBoxForKeyWidth, (int)textBoxForKeyHeight, SWP_NOZORDER);
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(EXIT_SUCCESS);
		break;
	}
	default:
	{
		return DefWindowProc(hWnd, iMsg, wParam, lParam);
	}
	}
}