#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;
	class Player;

	class Run :
		public GameObject
	{
	public:
		Run(Vector2 pos);
		Run();
		~Run();

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


