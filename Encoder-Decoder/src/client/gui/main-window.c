#include"main-window.h"

WNDCLASSEX NewWindowClass(const HBRUSH bgColor, const HCURSOR cursor, const HINSTANCE hInstance, const HICON icon, const PWSTR name, const WNDPROC procedure)
{
	WNDCLASSEX window;
	window.cbSize = sizeof(WNDCLASSEX);
	window.lpszClassName = name;
	window.hInstance = hInstance;
	window.cbClsExtra = NULL;
	window.cbWndExtra = NULL;
	window.hbrBackground = bgColor;
	window.hIcon = icon;
	window.hIconSm = icon;
	window.hCursor = cursor;
	window.style = CS_HREDRAW | CS_VREDRAW;
	window.lpszMenuName = NULL;
	window.lpfnWndProc = procedure;

	return window;
}

void MainWindowCreateMenu(HWND hWnd)
{
	HMENU rootMenu = CreateMenu();
	HMENU subMenuAlphabet = CreateMenu();

	AppendMenu(subMenuAlphabet, MF_STRING, ON_MENU_ALPHABET_PRESSED, L"Show avaible alphabets");

	AppendMenu(rootMenu, MF_POPUP, (UINT_PTR)subMenuAlphabet, L"Alphabet");
	AppendMenu(rootMenu, MF_STRING, NULL, L"Help");
	SetMenu(hWnd, rootMenu);

}