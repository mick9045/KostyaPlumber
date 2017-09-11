#include "GameWindow.h"
#include "resource.h"
#include "TubeView.h"
#include "Pipes.h"
#include <windowsx.h>
#include <memory>

namespace Plumber
{

	GameWindow::GameWindow()
		:BaseDialogWindow(IDD_DIALOG_GAME)
	{
		
	}


	GameWindow::~GameWindow()
	{
	}

	void GameWindow::Cls_OnClose(HWND hwnd)
	{
		Close();
	}

	BOOL Plumber::GameWindow::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
	{
		SetSize(1100, 700);
		std::shared_ptr<BaseTube> tube = std::make_shared<StraightPipe>();
		TubeView *tubeView = new TubeView();
		tubeView->Create(hWindow());
		tubeView->SetTube(tube);
		return FALSE;
	}

	INT_PTR GameWindow::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			HANDLE_MSG(hwnd, WM_CLOSE, Cls_OnClose);
			HANDLE_MSG(hwnd, WM_INITDIALOG, Cls_OnInitDialog);
		}
		return false;
	}



}