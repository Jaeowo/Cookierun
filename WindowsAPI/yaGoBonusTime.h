#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class GoBonusTime :
		public GameObject
	{
	public:
		GoBonusTime(Vector2 pos);
		GoBonusTime();
		~GoBonusTime();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;

	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;
	};
}

