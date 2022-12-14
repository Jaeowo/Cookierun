#pragma once
#include "yaUiBase.h"

namespace ya
{
	class Button : public UiBase
	{
	public:
		Button(eUIType type);
		~Button();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();

		int GetAlphaValue() { return mAlphaValue; }
		void SetAlphaValue(int AlphaValue) { AlphaValue = mAlphaValue; }

	private:
		Event mOnClick;
		bool mbMouseOn;
		int mAlphaValue;
	};

}

