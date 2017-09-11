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

	protected:
		void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
		void Cls_OnSize(HWND hwnd, UINT state, int cx, int cy);
		BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);

		void UpdateImage();
	private:
		std::shared_ptr<BaseTube> _tube;

		// Inherited via BaseDialogWindow
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	};
}
