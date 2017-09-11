#pragma once
#include "BaseDialogWindow.h"

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
	private:
		// Inherited via BaseDialogWindow
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	};
}

