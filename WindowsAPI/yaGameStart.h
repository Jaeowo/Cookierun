#pragma once
#include "yaUiBase.h"

namespace ya
{

	class GameStart : public UiBase
	{
	public:
		GameStart(eUIType type);
		~GameStart();

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

