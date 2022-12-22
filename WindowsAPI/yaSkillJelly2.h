#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class SkillJelly2 :
		public GameObject
	{
	public:
		SkillJelly2();
		~SkillJelly2();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;

	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;
	};
}


