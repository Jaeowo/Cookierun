#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Image;
	class Fire02
		: public GameObject
	{
	public:
		Fire02(Vector2 pos);
		Fire02();
		~Fire02();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		enum class eState
		{
			None,
			Away,
		};


	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;
		eState mState;
	};
}


