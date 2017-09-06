#include <Windows.h>
#include <tchar.h>
#include "MainWindow.h"

#include <CommCtrl.h>

#pragma comment(lib, "comctl32")

void inline EnableCommonControls();

INT WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, INT nCmdShow)
{
	EnableCommonControls();
	MSG msg;

	auto mainDialog = new Plumber::MainWindow();
	HWND hMainWindow = mainDialog->Create();

	while (GetMessage(&msg, NULL, NULL, NULL))
	{

		/*
		if (!IsDialogMessage(hMainWindow, &msg))
		{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		}
		*/
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	delete mainDialog;
	return msg.wParam;
}


void inline EnableCommonControls()
{
	INITCOMMONCONTROLSEX icc = { sizeof(INITCOMMONCONTROLSEX), ICC_WIN95_CLASSES };
	InitCommonControlsEx(&icc);
	LoadLibrary(TEXT("RICHED20.DLL"));

}