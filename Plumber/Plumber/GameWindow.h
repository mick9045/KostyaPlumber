#pragma once
#include "BaseDialogWindow.h"
#include "TubeView.h"
#include "LevelManager.h"

namespace Plumber
{
	class GameWindow
		:public BaseDialogWindow
	{
	public:
		GameWindow();
		~GameWindow();
	protected:
		void Cls_OnClose(HWND hwnd);
		BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
		HBRUSH Cls_OnCtlColor(HWND hwnd, HDC hdc, HWND hwndChild, int type);
		VOID GameWindow::Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify);
		void Cls_OnTimer(HWND hwnd, UINT id);
	private:
		HBRUSH _hbrBackground;
		TubeView _tubeViewArr[5][10];
		TubeView _startTube;
		TubeView _endTube;
		LevelManager _levelManager;
		int _levelCount = 1;
		// Inherited via BaseDialogWindow
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
		void updateAll();
		void updateAllWatered();
		bool checking = false;
		void unWaterAll();
		void refield();
	};
}

