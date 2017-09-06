#include "MainWindow.h"
#include <Windowsx.h>


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
		}
		return FALSE;
	}
}
