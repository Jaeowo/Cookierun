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
		//Ŭ�����ε� ��������
		enum class eState
		{
			Walk,
			Jump,
			Slide,
			Attack,
			Biggest,
			BiggestJump, 
			BiggestSlide,
			Skill1,
			Skill2,
			Death,
		};
		//�Ŵ�ȭ�� �浹�ڽ� ����� �ٸ�

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
	private:
		eState mState;
		float mCoff;
		float mSpeed;
		Image* mImage;
		Animator* mAnimator;
		Collider* mCollider;

		
	};

}