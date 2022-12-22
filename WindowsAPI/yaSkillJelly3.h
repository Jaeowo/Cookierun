#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class SkillJelly3 :
		public GameObject
	{
	public:
		SkillJelly3();
		~SkillJelly3();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;

	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;
	};
}


