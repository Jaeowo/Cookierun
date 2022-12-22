#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class SkillJelly5 :
		public GameObject
	{
	public:
		SkillJelly5();
		~SkillJelly5();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;

	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;
	};
}

