#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class Flower4 :
		public GameObject
	{
	public:
		Flower4();
		~Flower4();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;

	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;

	};
}