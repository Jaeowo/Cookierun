#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Image;
	class Squirrel
		: public GameObject
	{
	public:
		Squirrel();
		~Squirrel();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;



	private:
		Image* mImage;
		Animator* mAnimator;
		
	};
}


