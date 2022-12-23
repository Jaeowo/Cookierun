#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class ChangeCoin :
		public GameObject
	{
	public:
		ChangeCoin(Vector2 pos);
		ChangeCoin();
		~ChangeCoin();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;

	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;
	};
}

