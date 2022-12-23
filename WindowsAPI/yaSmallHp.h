#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class SmallHp :
		public GameObject
	{
	public:
		SmallHp(Vector2 pos);
		SmallHp();
		~SmallHp();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;

	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;
	};
}
