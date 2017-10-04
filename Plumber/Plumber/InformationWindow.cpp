#include "InformationWindow.h"
#include "resource.h"
#include "Windowsx.h"

namespace Plumber
{

	InformationWindow::InformationWindow()
		:BaseDialogWindow(IDD_INFORMATION)
	{
	}


	InformationWindow::~InformationWindow()
	{
	}

	void InformationWindow::Cls_OnClose(HWND hwnd)
	{
		Close();
	}

	INT_PTR InformationWindow::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			HANDLE_MSG(hwnd, WM_CLOSE, Cls_OnClose);
			HANDLE_MSG(hwnd, WM_COMMAND, Cls_OnCommand);
		
			//HANDLE_MSG(hwnd, WM_)

		}

		return FALSE;
	}

	
	VOID InformationWindow::Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify)
	{
		if (codeNotify == BN_CLICKED)
		{
			switch (id)
			{
			
			case IDOK:
			{
				Close();
			}

			default:
				break;
			}
		}
	}
}
