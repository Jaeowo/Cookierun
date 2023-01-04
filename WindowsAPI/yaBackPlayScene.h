#pragma once
#include "yaGameObject.h"

namespace ya
{

	class BackPlayScene
		: public GameObject
	{
	public:
		BackPlayScene(Vector2 pos);
		BackPlayScene();
		~BackPlayScene();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		void SetTarget(GameObject* target) { mTarget = target; }


	private:
		float mSpeed;
		GameObject* mTarget;
	};
}

