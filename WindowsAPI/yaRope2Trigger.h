#pragma once
#include "yaGameObject.h"

namespace ya
{

	class Rope2Trigger
		: public GameObject
	{
	public:
		Rope2Trigger(Vector2 pos);
		Rope2Trigger();
		~Rope2Trigger();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		void SetTarget(GameObject* target) { mTarget = target; }


	private:
		float mSpeed;
		GameObject* mTarget;
	};
}
