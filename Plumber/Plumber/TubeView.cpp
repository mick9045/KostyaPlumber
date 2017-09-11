#include "TubeView.h"
#include "resource.h"
#include <windowsx.h>
#include <memory>
#include "Pipes.h"


namespace Plumber
{
	HBITMAP TubeView::_hbmpBackground = (HBITMAP)LoadImage(
		GetModuleHandle(NULL),
		_T("Images/pattern.bmp"),
		IMAGE_BITMAP,
		0, 0,
		LR_LOADFROMFILE
	);

	HBRUSH TubeView::_hbrBackground = CreatePatternBrush(_hbmpBackground);

	TubeView::TubeView()
		:BaseDialogWindow(IDD_DIALOG_TUBE)
	{
	}

	TubeView::~TubeView()
	{
	}

	void TubeView::SetTube(std::shared_ptr<BaseTube> tube)
	{
		_tube = tube;
		UpdateImage();
	}

	void TubeView::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
	{
		if (codeNotify == STN_CLICKED || codeNotify == STN_DBLCLK)
		{
			switch (id)
			{
			case IDC_STATIC_TUBE:
				if (_tube)
				{
					_tube->Rotate();
					UpdateImage();
				}
				break;
			}
		}
	}

	void TubeView::Cls_OnSize(HWND hwnd, UINT state, int cx, int cy)
	{
		//SetSize(GetDlgItem(hwnd, IDC_STATIC_TUBE), cx, cy);
	}

	BOOL TubeView::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
	{
		SetSize(100, 100);
		SetSize(GetDlgItem(hwnd, IDC_STATIC_TUBE),100, 100);
		UpdateImage();
		return 0;
	}

	HBRUSH TubeView::Cls_OnCtlColor(HWND hwnd, HDC hdc, HWND hwndChild, int type)
	{
		return _hbrBackground;
	}

	void TubeView::UpdateImage()
	{
		if (_tube)
		{
			SendDlgItemMessage(
				hWindow(),
				IDC_STATIC_TUBE,
				STM_SETIMAGE,
				IMAGE_ICON,
				(LPARAM)_tube->GetImage()
			);
		}
	}

	INT_PTR TubeView::DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			HANDLE_MSG(hwnd, WM_INITDIALOG, Cls_OnInitDialog);
			HANDLE_MSG(hwnd, WM_COMMAND, Cls_OnCommand);
			//HANDLE_MSG(hwnd, WM_CTLCOLORDLG, Cls_OnCtlColor);
			HANDLE_MSG(hwnd, WM_CTLCOLORSTATIC, Cls_OnCtlColor);
		}
		return false;
	}
}