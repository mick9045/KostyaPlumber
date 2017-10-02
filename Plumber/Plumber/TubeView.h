#pragma once
#include "BaseDialogWindow.h"
#include "baseTube.h"
#include "Pipes.h"
#include <memory>

namespace Plumber
{
	class TubeView
		:public BaseDialogWindow
	{
	public:
		TubeView();
		~TubeView();
		void SetTube(std::shared_ptr<BaseTube> tube);
		void UpdateImage();
	protected:
		void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
		void Cls_OnSize(HWND hwnd, UINT state, int cx, int cy);
		BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
		HBRUSH Cls_OnCtlColor(HWND hwnd, HDC hdc, HWND hwndChild, int type);

		
	private:
		std::shared_ptr<BaseTube> _tube;
		static HBRUSH _hbrBackground;
		static HBITMAP _hbmpBackground;

		// Inherited via BaseDialogWindow
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	};
}
