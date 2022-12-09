#pragma once
#include "yaUiBase.h"
namespace ya
{
	class GameObject;
	class HpBar : public UiBase
	{
	public:
		HpBar(eUIType type);
		~HpBar();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		void SetTarget(GameObject* target) { mTarget = target; }

	private:
		GameObject* mTarget;
	};

}

