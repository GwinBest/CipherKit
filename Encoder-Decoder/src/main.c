#include"client/message-handler.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	WNDCLASSEX MainWindow = NewWindowClass(
		GetSysColorBrush(COLOR_WINDOW),
		LoadCursor(NULL, IDC_ARROW),
		hInstance,
		LoadIcon(hInstance, IDI_WARNING),
		L"Main Window",
		fnMessageProcessor);

	if (!RegisterClassEx(&MainWindow))
		return EXIT_FAILURE;

	hWindow = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,
		MainWindow.lpszClassName,
		L"Decoder3000",
		WS_OVERLAPPEDWINDOW,
		280, 180,
		1200, 720,
		NULL,
		NULL,
		NULL,
		NULL);

	if (hWindow == INVALID_HANDLE_VALUE)
		return EXIT_FAILURE;

	ShowWindow(hWindow, SW_SHOWNORMAL);
	UpdateWindow(hWindow);

	MSG message;
	while (GetMessage(&message, NULL, NULL, NULL))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return (int)(message.wParam);
}
