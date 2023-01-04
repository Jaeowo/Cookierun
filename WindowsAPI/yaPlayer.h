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

			Back,

			BonusTimeIntro,
			BonusTimeUp,
			BonusTimeDown,

			Mujuk, //무적시간
			MujukJump,
			MujukSlide,

			Swing,

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
		void Swing();

		void Skill1();
		void Skill2();

		void Back();

		void Death();

		void SetHp(int hp) { mHp = hp; }
		float GetHp() { return mHp; }

		void SetJumpCount(int JumpCount) { mJumpCount = JumpCount; }
		int GetJumpCount() { return mJumpCount; }

		void SetState(eState state) { mState = state; }
		eState GetState() { return mState; }

		void LandingComplete();
	

		float GetSpeed() { return mSpeed; }

		float GetmSkill1Time() { return mSkill1Time; }
		float GetmSkill2Time() { return mSkill2Time; }

	private:
		int mJumpCount;
		float mHp;
		float mSpeed;
		float mTime;
		float mSkill1Time;
		float mSkill1Time2;
		float mSkill2Time;
		int mSkillCount1;
		int mSkillCount2;
		int mCheck;

	//=======
	public:
		void SetScore(int Score) { mScore = Score; }
		int GetScore() { return mScore; }
	

		void SetItemTime(float ItemTime) { mItemTime = ItemTime; }
		float GetItemTime() { return mItemTime; }

		void SetDistance(int Distance) { mDistance = Distance; }
		int GetDistance() { return mDistance; }

	private:
		eState mState;
		float mCoff;
		Image* mImage;
		Animator* mAnimator;
		Collider* mCollider;
		Collider* mSlideCollider;

		int mScore;
		std::string mStringScore;

		float mItemTime;
		float mMujukTime;
		int mDistance;
		Vector2 PlayerPos;
	
		
	};

}