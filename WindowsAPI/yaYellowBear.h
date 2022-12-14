#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class YellowBear
		:public GameObject
	{
	public:
		YellowBear(Vector2 pos);
		YellowBear();
		~YellowBear();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;

	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;
	};
}


