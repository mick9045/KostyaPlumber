#include "GameWindow.h"
#include "resource.h"

namespace Plumber
{

	GameWindow::GameWindow()
		:BaseDialogWindow(IDD_DIALOG_TUBE)
	{
	}


	GameWindow::~GameWindow()
	{
	}

	INT_PTR GameWindow::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		return INT_PTR();
	}

}