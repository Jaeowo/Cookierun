#pragma once
#include "yaGameObject.h"


namespace ya
{
	class Animator;
	class Image;
	class Squirrel;
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		void WalkComplete();

		

	//======= state

	public:
		void Jump();
		void Slide();
		void Walk();

		void SetHp(int hp) { mHp = hp; }
		int GetHp() { return mHp; }

		void SetJumpCount(int JumpCount) { mJumpCount = JumpCount; }
		int GetJumpCount() { return mJumpCount; }


	private:
		int mJumpCount;
		int mHp;



	//=======
	private:
		float mCoff;
		float mSpeed;
		Image* mImage;
		Animator* mAnimator;
		Squirrel* msquirrel;

		
	};

}