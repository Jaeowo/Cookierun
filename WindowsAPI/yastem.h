#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class Stem :
		public GameObject
	{
	public:
		Stem();
		~Stem();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;



	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;
	};
}

