#pragma once
#include "yaUiBase.h"

namespace ya
{

	class Back : public UiBase
	{
	public:
		Back(eUIType type);
		~Back();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();

	private:
		Event mOnClick;
		bool mbMouseOn;
	};

}
