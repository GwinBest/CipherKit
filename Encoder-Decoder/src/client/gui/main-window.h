#pragma once
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <Windows.h>
#include <CommCtrl.h>

#define MAIN_WINDOW_MIN_WIDTH    1150
#define MAIN_WINDOW_MIN_HEIGHT   550

#define ON_MENU_ALPHABET_PRESSED 231


WNDCLASSEX NewWindowClass(const HBRUSH bgColor, const HCURSOR cursor, const HINSTANCE hInstance, const HICON icon, const PWSTR name, const WNDPROC procedure);
void MainWindowCreateMenu(HWND hWnd);
