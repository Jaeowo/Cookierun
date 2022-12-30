#pragma once
#include "yaGameObject.h"

namespace ya
{
	class FinishSkill2
		: public GameObject
	{
	public:
		FinishSkill2(Vector2 pos);
		FinishSkill2();
		~FinishSkill2();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		void SetTarget(GameObject* target) { mTarget = target; }


	private:
		float mSpeed;
		GameObject* mTarget;
	};
}

