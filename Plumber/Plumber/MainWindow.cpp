#include "MainWindow.h"


namespace Plumber
{
	MainWindow::MainWindow()
		:BaseDialogWindow(IDD_DIALOG_MAIN)
	{
	}


	MainWindow::~MainWindow()
	{
	}

	INT_PTR MainWindow::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		return INT_PTR();
	}
}
