#include "TubeView.h"
#include "resource.h"
#include <windowsx.h>


namespace Plumber
{
	TubeView::TubeView()
		:BaseDialogWindow(IDD_DIALOG_TUBE)
	{
	}

	TubeView::~TubeView()
	{
	}

	void TubeView::Cls_OnClose(HWND hwnd)
	{
		Close();
	}

	INT_PTR TubeView::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			HANDLE_MSG(hwnd, WM_CLOSE, Cls_OnClose);
			
		}
	}
}