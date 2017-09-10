#pragma once
#include "BaseDialogWindow.h"
#include "baseTube.h"
#include <memory>

namespace Plumber
{
	class TubeView
		:public BaseDialogWindow
	{
	public:
		TubeView();
		~TubeView();
	protected:
		void Cls_OnClose(HWND hwnd);
	private:
		std::shared_ptr<BaseTube> tube;

		// Inherited via BaseDialogWindow
		virtual INT_PTR DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	};
}
