#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class Flower1 :
		public GameObject
	{
	public:
		Flower1();
		~Flower1();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
	
	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;

	};
}
