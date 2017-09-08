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

		// Inherited via BaseDialogWindow
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	};
}

