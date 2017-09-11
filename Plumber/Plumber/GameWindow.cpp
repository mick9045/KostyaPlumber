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
		HBITMAP hBackground = (HBITMAP)LoadImage(
			GetModuleHandle(NULL),
			_T("Images/pattern.bmp"),
			IMAGE_BITMAP,
			0, 0,
			LR_LOADFROMFILE
		);

		_hbrBackground = CreatePatternBrush(hBackground);
		DeleteObject(hBackground);
	}


	GameWindow::~GameWindow()
	{
		DeleteObject(_hbrBackground);
	}

	void GameWindow::Cls_OnClose(HWND hwnd)
	{
		Close();
	}

	BOOL Plumber::GameWindow::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
	{
		SetSize(1024, 740);
		/*std::shared_ptr<BaseTube> tube = std::make_shared<StraightPipe>();
		TubeView *tubeView = new TubeView();
		tubeView->Create(hWindow());
		tubeView->SetTube(tube);
		std::shared_ptr<BaseTube> tube2 = std::make_shared<StraightPipe>();
		TubeView *tubeView2 = new TubeView();
		tubeView2->Create(hWindow());
		tubeView2->SetTube(tube2);
		tubeView2->SetPos(100, 0);*/
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				_tubeViewArr[j][i].Create(hWindow());
				_tubeViewArr[j][i].SetTube(std::shared_ptr<StraightPipe>(new StraightPipe()));
				_tubeViewArr[j][i].SetPos(i * 100 + 12, j * 100);
				
			}
		}
		return FALSE;
	}

	HBRUSH GameWindow::Cls_OnCtlColor(HWND hwnd, HDC hdc, HWND hwndChild, int type)
	{
		return _hbrBackground;
	}

	INT_PTR GameWindow::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			HANDLE_MSG(hwnd, WM_CLOSE, Cls_OnClose);
			HANDLE_MSG(hwnd, WM_INITDIALOG, Cls_OnInitDialog);
			HANDLE_MSG(hwnd, WM_CTLCOLORDLG, Cls_OnCtlColor);
		}
		return false;
	}



}