#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class EatingEffect :
		public GameObject
	{
	public:
		EatingEffect();
		~EatingEffect();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;

	private:
		Image* mImage;
		float mSpeed;
		float mAlphaValue;
	};
}

