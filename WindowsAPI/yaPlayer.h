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
			RunJump,
			RunSlide,

			Skill1,
			Skill2,

			BonusTimeIntro,
			BonusTimeUp,
			BonusTimeDown,

			Mujuk, //�����ð�
			MujukJump,
			MujukSlide,

			Death,
	
		};

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

		void Mujuk();
		void MujukJump();
		void MujukSlide();

		void Run();
		void RunJump();
		void RunSlide();

		void SetHp(int hp) { mHp = hp; }
		float GetHp() { return mHp; }

		void SetJumpCount(int JumpCount) { mJumpCount = JumpCount; }
		int GetJumpCount() { return mJumpCount; }

		void SetState(eState state) { mState = state; }
		eState GetState() { return mState; }

		void LandingComplete();

		float GetSpeed() { return mSpeed; }

	private:
		int mJumpCount;
		float mHp;
		float mSpeed;

	//=======
	public:
		void SetScore(int Score) { mScore = Score; }
		int GetScore() { return mScore; }

		void SetItemTime(float ItemTime) { mItemTime = ItemTime; }
		float GetItemTime() { return mItemTime; }

	private:
		eState mState;
		float mCoff;
		Image* mImage;
		Animator* mAnimator;
		Collider* mCollider;
		int mScore;
		float mItemTime;
		float mMujukTime;
		
	};

}