#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class Rope02 :
		public GameObject
	{
	public:
		Rope02();
		~Rope02();

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

