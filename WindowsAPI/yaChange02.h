#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Stage01;

	class Change02
		:public GameObject
	{
	public:
		Change02(Vector2 pos);
		Change02();
		~Change02();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		void SetTarget(GameObject* target) { mTarget = target; }


	private:
		float mSpeed;
		GameObject* mTarget;
		Stage01* mStage01;

	};
}


