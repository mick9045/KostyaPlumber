#include "BaseDialogWindow.h"
#include "exception"
#include "resource.h"

namespace Plumber
{
	BaseDialogWindow::~BaseDialogWindow()
	{
		Close();
		_hwnd = NULL;
	}

	BaseDialogWindow::BaseDialogWindow(INT nResource)
	{
		_hwnd = NULL;
		_nResource = nResource;
	}

	BOOL BaseDialogWindow::IsCreated()
	{
		return ::IsWindow(_hwnd);
	}

	HWND BaseDialogWindow::Create(HWND hwndParent, HINSTANCE hInstance)
	{
		if (IsCreated())
		{
			return _hwnd;
		}
		_bModal = false;
		_hwnd = CreateDialogParam(
			hInstance,
			MAKEINTRESOURCE(_nResource),
			hwndParent,
			MessageRoute,
			reinterpret_cast<LPARAM>(this)
		);
		if (_hwnd != NULL)
		{
			::ShowWindow(_hwnd, SW_SHOW);
		}
		return _hwnd;
	}

	INT_PTR BaseDialogWindow::CreateModal(HWND hwndParent, HINSTANCE hInstance)
	{
		_bModal = true;
		return DialogBoxParam(
			hInstance,
			MAKEINTRESOURCE(_nResource),
			hwndParent,
			MessageRoute,
			reinterpret_cast<LONG>(this)
		);
	}


	BOOL BaseDialogWindow::IsModal()
	{
		return _bModal;
	}

	inline BaseDialogWindow * BaseDialogWindow::GetWindowObjectFromHandle(HWND hWnd)
	{
		return reinterpret_cast<BaseDialogWindow *>(GetWindowLong(hWnd, GWL_USERDATA));
	}

	BaseDialogWindow::BaseDialogWindow(const BaseDialogWindow & window)
	{
	}

	INT_PTR CALLBACK BaseDialogWindow::MessageRoute(
		HWND hwnd,
		UINT uMsg,
		WPARAM wParam,
		LPARAM lParam)
	{
		BaseDialogWindow *wnd = nullptr;

		switch (uMsg)
		{
		case WM_INITDIALOG:
		{
			SetWindowLong(hwnd, GWL_USERDATA, lParam); // setting window user data as window pointer
			reinterpret_cast<BaseDialogWindow *>(lParam)->_hwnd = hwnd; // setting dialog box handle

			HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
			SendMessage(hwnd, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(hIcon));
			SendMessage(hwnd, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(hIcon));
			break;
		}
		default:
			break;
		}

		wnd = GetWindowObjectFromHandle(hwnd);


		if (wnd)
		{
			return wnd->DlgProc(hwnd, uMsg, wParam, lParam);
		}
		return false;
	}

	HWND BaseDialogWindow::GetWindowHandle()
	{
		return _hwnd;
	}

	INT BaseDialogWindow::GetResourceID()
	{
		return _nResource;
	}

	HWND BaseDialogWindow::hWindow()
	{
		if (_hwnd == nullptr)
		{
			throw std::exception("window is not created");
		}
		return _hwnd;
	}

	SIZE BaseDialogWindow::GetClientSize()
	{
		return GetClientSize(_hwnd);
	}

	SIZE BaseDialogWindow::GetSize()
	{
		return GetSize(_hwnd);
	}

	void BaseDialogWindow::SetSize(int x, int y)
	{
		SetSize(_hwnd, x, y);
	}

	RECT BaseDialogWindow::GetRect()
	{
		RECT rect;
		GetWindowRect(_hwnd, &rect);
		return rect;
	}

	void BaseDialogWindow::SetPos(int x, int y)
	{
		return SetPos(_hwnd, x, y);
	}

	POINT BaseDialogWindow::GetLocalPosition()
	{
		return GetLocalPosition(_hwnd);
	}

	tString BaseDialogWindow::GetText(HWND hWindow)
	{
		size_t length = GetWindowTextLength(hWindow) + 1;
		LPTSTR str = new TCHAR[length];
		GetWindowText(hWindow, str, length);
		tString result(str);
		delete str;
		return result;
	}

	POINT BaseDialogWindow::GetLocalPosition(HWND hwnd)
	{
		RECT rect;
		GetWindowRect(hwnd, &rect);
		POINT point{ rect.left, rect.top };
		HWND parentHwnd = reinterpret_cast<HWND>(GetWindowLong(hwnd, GWL_HWNDPARENT));
		ScreenToClient(parentHwnd, &point);
		return point;
	}

	SIZE BaseDialogWindow::GetClientSize(HWND hwnd)
	{
		RECT rect;
		GetClientRect(hwnd, &rect);
		return SIZE{ rect.right - rect.left, rect.bottom - rect.top };
	}
	
	SIZE BaseDialogWindow::GetSize(HWND hwnd)
	{
		RECT rect;
		GetWindowRect(hwnd, &rect);
		return SIZE{ rect.right - rect.left, rect.bottom - rect.top };
	}

	void BaseDialogWindow::SetSize(HWND hWnd, int x, int y)
	{
		SetWindowPos(hWnd, NULL, 0, 0, x, y, SWP_NOMOVE);
	}

	void BaseDialogWindow::SetPos(HWND hWnd, int x, int y)
	{
		SetWindowPos(hWnd, NULL, x, y, 0, 0, SWP_NOSIZE);
	}

	INT BaseDialogWindow::GetMenuItemPosById(HMENU hMenu, INT nId)
	{
		for (int i = GetMenuItemCount(hMenu); i >= 0; i--)
		{
			if (GetMenuItemID(hMenu, i) == nId)
				return i;
		}
		return -1;
	}

	void BaseDialogWindow::Close()
	{
		if (IsCreated())
		{
			if (IsModal())
				EndDialog(_hwnd, _nResult);
			else
				DestroyWindow(_hwnd);
		}
	}
}

