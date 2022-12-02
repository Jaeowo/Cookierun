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
		//클래스로도 관리가능
		enum class eState
		{
			Walk,
			Jump,
			Slide,
			Attack,
			Biggest,
			BiggestJump, 
			BiggestSlide,
			Run,
			Skill1,
			Skill2,
			BonusTimeIntro,
			BonusTimeUp,
			BonusTimeDown,
			Death,
		};
		//거대화시 충돌박스 사이즈가 다름

		Player();
		~Player();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;



	//======= state

	public:
		void Walk();
		void Jump();
		void Slide();
		void Attack();
		void Biggest();
		void BiggestJump();
		void BiggestSlide();

		void SetHp(int hp) { mHp = hp; }
		int GetHp() { return mHp; }

		void SetJumpCount(int JumpCount) { mJumpCount = JumpCount; }
		int GetJumpCount() { return mJumpCount; }

		void SetState(eState state) { mState = state; }
		eState GetState() { return mState; }

		void LandingComplete();

	private:
		int mJumpCount;
		int mHp;


	//=======
	public:
		void SetScore(int Score) { mScore = Score; }
		int GetScore() { return mScore; }

	private:
		eState mState;
		float mCoff;
		float mSpeed;
		Image* mImage;
		Animator* mAnimator;
		Collider* mCollider;
		int mScore;
		
	};

}