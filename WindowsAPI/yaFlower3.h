#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class Flower3 :
		public GameObject
	{
	public:
		Flower3(Vector2 pos);
		Flower3();
		~Flower3();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;

	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;

	};
}