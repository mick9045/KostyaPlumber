#pragma once
#include <windows.h>
#include <CommCtrl.h>
#include <string>
//#include "resource.h"

#ifndef UNICODE  
typedef std::string tString;
#define to_tstring std::to_string
#else
typedef std::wstring tString;
#define to_tstring std::to_wstring
#endif


namespace Plumber
{
	class BaseDialogWindow
	{
	public:
		virtual  ~BaseDialogWindow();
		BaseDialogWindow(INT nResource);
		BOOL IsCreated();
		HWND Create(HWND hwndParent = NULL, HINSTANCE hInstance = GetModuleHandle(NULL));
		INT_PTR CreateModal(HWND hwndParent = NULL, HINSTANCE hInstance = GetModuleHandle(NULL));
		HWND GetWindowHandle();
		INT GetResourceID();
		HWND hWindow();
		SIZE GetClientSize();
		SIZE GetSize();
		RECT GetRect();
		POINT GetLocalPosition();
		static tString GetText(HWND hWnd);
		static POINT GetLocalPosition(HWND hWnd);
		static SIZE GetClientSize(HWND hWnd);
		static SIZE GetSize(HWND hWnd);
		static INT GetMenuItemPosById(HMENU hMenu, INT id);
		/*~~~~~~~~~~~~~~ methods~~~~~~~~~~~~~~~~~~*/
		void Close();
	protected:
		HWND _hwnd;
		INT _nResource;
		INT _nResult;
		/*~~~~~~~~~~~~~~ methods~~~~~~~~~~~~~~~~~~*/
		BOOL isModal();
		inline static BaseDialogWindow * GetWindowObjectFromHandle(HWND hWnd);
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
	private:
		BOOL _bModal;
		//prohobit coping
		BaseDialogWindow(const BaseDialogWindow &);
		static INT_PTR CALLBACK MessageRoute(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); // routes messages from all windows
	};

}