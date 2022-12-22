#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class SkillJelly1 :
		public GameObject
	{
	public:
		SkillJelly1();
		~SkillJelly1();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;

	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;
	};
}

