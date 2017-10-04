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
		SetWindowText(hwnd, TEXT("Уровень 1"));
		
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
				if (!checking) {
					SetTimer(hwnd,             // handle to main window 
						IDT_TIMER1,            // timer identifier 
						400,                 // 1-second interval 
						(TIMERPROC)NULL);
					checking = true;
				}
			}
			break;

			default:
				break;
			}
		}
	}

	void GameWindow::Cls_OnTimer(HWND hwnd, UINT id)
	{
		Answer::Answer result = _levelManager.GetLevel(_levelCount).GetCollection().startWater();
		updateAllWatered();
		switch (result)
		{
		case Answer::CONTINUE:
			break;

		case Answer::FINISH:
			KillTimer(hwnd, IDT_TIMER1);
			checking = false;
			if (_levelCount < 3)
			{
				MessageBox(hwnd, TEXT("Уровень пройден"), TEXT(":)"), MB_OK);
				_levelCount++;
				refield();
			}
			else if (_levelCount == 3)
			{
				MessageBox(hwnd, TEXT("Победа"), TEXT(":)"), MB_OK);
				_levelCount = 1;
				Close();
			}
			
			break;

		case Answer::LEAK:
			KillTimer(hwnd, IDT_TIMER1);
			checking = false;
			MessageBox(hwnd, TEXT("Поражение"), TEXT(":("), MB_OK);
			unWaterAll();
			break;
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
			HANDLE_MSG(hwnd, WM_TIMER, Cls_OnTimer);
		}
		return false;
	}

	void GameWindow::updateAll()
	{
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				_tubeViewArr[y][x].UpdateImage();
			}
		}
	}

	void GameWindow::updateAllWatered()
	{

		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				auto tube = _levelManager.GetLevel(_levelCount).GetCollection().getTube(y,x);
				if(tube->IsFilled())
				_tubeViewArr[y][x].UpdateImage();
			}
		}
	}

	void GameWindow::unWaterAll()
	{
		Level level = _levelManager.GetLevel(_levelCount);
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				level.GetCollection().getTube(y, x)->unWater();
			}
		}
		updateAll();
	}
	void GameWindow::refield()
	{
		tString text = TEXT("Уровень ");
		text+= to_tstring(_levelCount);
		SetWindowText(_hwnd, text.c_str());
		Level level = _levelManager.GetLevel(_levelCount);
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				_tubeViewArr[y][x].SetTube(level.GetCollection().getTube(y, x));
			}
		}
	}

}