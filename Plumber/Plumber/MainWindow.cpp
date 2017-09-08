#include "MainWindow.h"
#include <Windowsx.h>
#include "resource.h"
#include "GameWindow.h"

namespace Plumber
{
	MainWindow::MainWindow()
		:BaseDialogWindow(IDD_DIALOG_MAIN)
	{
	}


	MainWindow::~MainWindow()
	{
	}

	void MainWindow::Cls_OnClose(HWND hwnd)
	{
		Close();
	}

	INT_PTR MainWindow::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			HANDLE_MSG(hwnd, WM_CLOSE, Cls_OnClose);	
			HANDLE_MSG(hwnd, WM_DESTROY, Cls_OnDestroy);
			HANDLE_MSG(hwnd, WM_COMMAND, Cls_OnCommand);
			//HANDLE_MSG(hwnd, WM_)
		}

		return FALSE;
	}

	VOID MainWindow::Cls_OnDestroy(HWND hwnd)
	{
		PostQuitMessage(NULL);
	}

	VOID MainWindow::Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify)
	{
		if (codeNotify == BN_CLICKED)
		{
			switch (id)
			{
			case IDOK:
			{
				GameWindow * gameWindow = new GameWindow();
				ShowWindow(hWindow(), SW_HIDE);
				gameWindow->CreateModal();
				delete gameWindow;
				ShowWindow(hWindow(), SW_SHOW);
			}
			default:
				break;
			}
		}
	}
}
