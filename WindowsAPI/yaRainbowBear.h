#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class RainbowBear :
		public GameObject
	{
	public:
		RainbowBear(Vector2 pos);
		RainbowBear();
		~RainbowBear();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;

	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;
	};
}

