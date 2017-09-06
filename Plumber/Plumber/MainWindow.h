#pragma once
#include "BaseDialogWindow.h"
#include "resource.h"

namespace Plumber
{
	class MainWindow
		:public BaseDialogWindow
	{
	public:
		MainWindow();
		~MainWindow();
	protected:
		void Cls_OnClose(HWND hwnd);
	private:
		// Inherited via BaseDialogWindow
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
		

	};
}
