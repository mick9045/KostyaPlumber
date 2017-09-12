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
	private:
		HBRUSH _hbrBackground;
		TubeView _tubeViewArr[7][10];
		LevelManager _levelManager;

		// Inherited via BaseDialogWindow
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	};
}

