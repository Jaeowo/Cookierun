#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Image;
	class Player;
	class Biggest :
		public GameObject
	{
	public:
		Biggest(Vector2 pos);
		Biggest();
		~Biggest();


		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;


	private:
		Image* mImage;
		Animator* mAnimator;
		Player* mPlayer;
		float mSpeed;
		float mTime;
	};
}


