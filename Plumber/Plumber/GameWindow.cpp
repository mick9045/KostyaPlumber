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
		Level level = _levelManager.GetLevel(_levelCount);
		
		
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				_tubeViewArr[y][x].Create(hWindow());
				_tubeViewArr[y][x].SetPos(x * 100, ((y + 1) * 100));
			}
		}

		TubeCollection collection = level.GetCollection();
		TubeView * tubeView = new TubeView();

		auto startPipe = new StraightPipe();
		_startTube.Create(hWindow());
		_endTube.Create(hWindow());
		_endTube.SetPos(100 * 9, 100 * 6);
		_startTube.SetTube(std::shared_ptr<BaseTube>(new EmptyPipe()));
		_endTube.SetTube(std::shared_ptr<BaseTube>(new EmptyPipe()));
		/*auto startPipe = new StraightPipe();
		_tubeViewArr[0][0].SetTube(std::shared_ptr<BaseTube>(startPipe));
		auto endPipe = new StraightPipe();
		_tubeViewArr[6][9].SetTube(std::shared_ptr<BaseTube>(endPipe));*/

		
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				_tubeViewArr[y][x].SetTube(collection.getTube(y, x));
			}
		}

		

		return FALSE;
	}

	HBRUSH GameWindow::Cls_OnCtlColor(HWND hwnd, HDC hdc, HWND hwndChild, int type)
	{
		return _hbrBackground;
	}


	VOID GameWindow::Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify)
	{
		if (codeNotify == BN_CLICKED)
		{
			switch (id)
			{
			case IDC_BUTTON_START:
			{
				if (_levelManager.GetLevel(_levelCount).GetCollection().startWater())
					MessageBox(hwnd, TEXT("������� �������"), TEXT("������!"), MB_OK);
				else
					MessageBox(hwnd, TEXT("�������"), TEXT("���������"), MB_OK);
				for (int y = 0; y < 5; y++)
				{
					for (int x = 0; x < 10; x++)
					{
						_tubeViewArr[y][x].UpdateImage();
					}
				}
			}
			break;

			default:
				break;
			}
		}
	}
	INT_PTR GameWindow::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			HANDLE_MSG(hwnd, WM_CLOSE, Cls_OnClose);
			HANDLE_MSG(hwnd, WM_INITDIALOG, Cls_OnInitDialog);
			HANDLE_MSG(hwnd, WM_CTLCOLORDLG, Cls_OnCtlColor);
			HANDLE_MSG(hwnd, WM_COMMAND, Cls_OnCommand);
		}
		return false;
	}



}