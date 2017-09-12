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
		Level level = _levelManager.GetLevel(1);
		

		for (int y = 0; y < 7; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				_tubeViewArr[y][x].Create(hWindow());
			}
		}

		auto collection = level.GetCollection();
		
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				
				//_tubeViewArr[j][i].SetTube(std::shared_ptr<StraightPipe>(new StraightPipe()));
				_tubeViewArr[y][x].SetTube(collection.getTube(y, x));
				_tubeViewArr[y][x].SetPos(x * 100, (y * 100));
				
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