#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;
	class Player;

	class Magnet :
		public GameObject
	{
	public:
		Magnet(Vector2 pos);
		Magnet();
		~Magnet();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;


	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;
		float mTime;
	};
}
