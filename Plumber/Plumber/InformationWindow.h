#pragma once
#include "BaseDialogWindow.h"

namespace Plumber
{
	class InformationWindow
		:public BaseDialogWindow
	{
	public:
		InformationWindow();
		~InformationWindow();
	protected:
		void Cls_OnClose(HWND hwnd);
		VOID Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify);
	private:
		// Inherited via BaseDialogWindow
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	};
}

#pragma once
