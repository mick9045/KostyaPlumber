#include "GameWindow.h"
#include "resource.h"
#include "TubeView.h"

namespace Plumber
{

	GameWindow::GameWindow()
		:BaseDialogWindow(IDD_DIALOG_TUBE)
	{
		TubeView *tubeView = new TubeView();
		tubeView->Create(hWindow());
		delete tubeView;
	}


	GameWindow::~GameWindow()
	{
	}

	INT_PTR GameWindow::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		return INT_PTR();
	}

}