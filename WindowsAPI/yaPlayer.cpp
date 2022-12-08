#include "yaPlayer.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaScene.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaCamera.h"
#include "yaRigidbody.h"
#include "yaUIManager.h"
#include "yaSquirrel.h"
#include "yaObject.h"
#include "yaCollisionManager.h"


namespace ya
{
	Player::Player()
		: mSpeed(-300.0f)
		, mHp(100)
		, mState(eState::Walk)
		, mScore (0)
		, mItemTime (0.0f)
		, mMujukTime(0.0f)
	{
	
		AddComponent<Rigidbody>();

		SetName(L"Player");
		SetPos({ 400.0f, 625.0f });
		SetScale({ 1.0f, 1.0f });

		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\Walk"
			, L"WalkC", Vector2(0, 0), 0.12f);

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\DoubleJump"
			, L"DoubleJumpC", Vector2(0, 0), 0.1f);

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\Jump"
			, L"JumpC", Vector2(0, 0), 0.2f);

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\Slide"
			, L"SlideC", Vector2(0, 0), 0.2f);

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\Landing"
			, L"LandingC", Vector2(0, 0), 0.15f);

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\Attack"
			, L"AttackC", Vector2(0, 0), 0.13f);

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\Run"
			, L"RunC", Vector2(0, 0), 0.13f);

		mAnimator->GetCompleteEvent(L"LandingC") = std::bind(&Player::LandingComplete, this);
		mAnimator->GetCompleteEvent(L"AttackC") = std::bind(&Player::LandingComplete, this);
		
		AddComponent(mAnimator);
		
		Camera::SetTarget(this);

		mCollider = new Collider();
		AddComponent(mCollider);

		mCollider->SetOffset(Vector2(10.0f, 125.0f));
		mCollider->SetScale(Vector2(100.0f, 150.0f));


		mCoff = 0.1f;
	}

	Player::~Player()
	{

	}

	void Player::Tick()
	{
		GameObject::Tick();

		switch (mState)
		{
		case ya::Player::eState::Walk:
		{
			Walk();
		}
		break;
		case ya::Player::eState::Jump:
		{
			Jump();
		}
		break;
		case ya::Player::eState::Slide:
		{
			Slide();
		}
		break;
		case ya::Player::eState::Attack:
		{
			Attack();
		}
		break;
		case ya::Player::eState::Biggest:
		{
			Biggest();
		}
		break;
		case ya::Player::eState::BiggestJump:
		{
			BiggestJump();
		}
		break;
		case ya::Player::eState::BiggestSlide:
		{
			BiggestSlide();
		}
		break;
		case ya::Player::eState::Run:
		{
			Run();
		}
		break;
		case ya::Player::eState::RunJump:
		{
			RunJump();
		}
		break;
		case ya::Player::eState::RunSlide:
		{
			RunSlide();
		}
		break;
		case ya::Player::eState::Mujuk:
		{
			Mujuk();
		}
		break;
		case ya::Player::eState::MujukJump:
		{
			MujukJump();
		}
		break;
		case ya::Player::eState::MujukSlide:
		{
			MujukSlide();
		}
		break;
		case ya::Player::eState::Death:
		{

		}
		break;
		default:
			break;
		}

		
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Player::OnCollisionEnter(Collider* other)
	{


	}

	void Player::OnCollisionStay(Collider* other)
	{

	}

	void Player::OnCollisionExit(Collider* other)
	{

	}

	void Player::Jump()
	{
		//Translate(mSpeed);
		int JumpCount = GetJumpCount();
		Rigidbody* rigidbody = GetComponent<Rigidbody>();
		bool IsGround = false;
		IsGround = rigidbody->GetGround();

		if (IsGround == true)
		{
			JumpCount = 0;
			SetJumpCount(JumpCount);
		
		}

		if (JumpCount == 0)
		{
				Rigidbody* rigidbody = GetComponent<Rigidbody>();
				Vector2 velocity = rigidbody->GetVelocity();
				velocity.y = -630.0f;
				rigidbody->SetVelocity(velocity);

				rigidbody->SetGround(false);
				
				JumpCount = 1;
				SetJumpCount(JumpCount);

				bool IsGround = false;
				IsGround = rigidbody->GetGround();
				mAnimator->Play(L"JumpC", true);
				
				
		}
		else if (JumpCount == 1)
		{
			if (KEY_DOWN(eKeyCode::W))
			{
				Rigidbody* rigidbody = GetComponent<Rigidbody>();
				Vector2 velocity = rigidbody->GetVelocity();
				velocity.y = -630.0f;
				rigidbody->SetVelocity(velocity);

				rigidbody->SetGround(false);

				JumpCount = 2;
				SetJumpCount(JumpCount);
				mAnimator->Play(L"DoubleJumpC", false);;
			}

		}

		
	}
	void Player::Slide()
	{
		//Translate(mSpeed);
		
		if (KEY_PREESE(eKeyCode::S))
		{
			mAnimator->Play(L"SlideC", true);
			mCollider->SetOffset(Vector2(10.0f, 164.0f));
			mCollider->SetScale(Vector2(100.0f, 70.0f));
		}
		else if (KEY_UP(eKeyCode::S))
		{
			mState = eState::Walk;
		}

	}

	void Player::Attack()
	{
		//Translate(mSpeed);
		//mAnimator->Play(L"AttackC", true);
	}

	void Player::Biggest()
	{
		mItemTime += Time::DeltaTime();

		if (mItemTime >= 3.0f)
		{
			SetState(Player::eState::Mujuk);
		}
		mCollider->SetOffset(Vector2(200.0f, 375.0f));
		mCollider->SetScale(Vector2(200.0f, 370.0f));
		if (KEY_DOWN(eKeyCode::W))
		{
			mState = eState::BiggestJump;
		}
		else if (KEY_PREESE(eKeyCode::S))
		{
			mState = eState::BiggestSlide;
		}
	}

	void Player::BiggestJump()
	{
		mItemTime += Time::DeltaTime();

		if (mItemTime >= 3.0f)
		{
			SetState(Player::eState::Mujuk);
		}

		mCollider->SetOffset(Vector2(200.0f, 375.0f));
		mCollider->SetScale(Vector2(200.0f, 370.0f));

		int JumpCount = GetJumpCount();
		Rigidbody* rigidbody = GetComponent<Rigidbody>();
		bool IsGround = false;
		IsGround = rigidbody->GetGround();

		if (IsGround == true)
		{
			JumpCount = 0;
			SetJumpCount(JumpCount);

		}

		if (JumpCount == 0)
		{
			Rigidbody* rigidbody = GetComponent<Rigidbody>();
			Vector2 velocity = rigidbody->GetVelocity();
			velocity.y = -630.0f;
			rigidbody->SetVelocity(velocity);

			rigidbody->SetGround(false);

			JumpCount = 1;
			SetJumpCount(JumpCount);

			bool IsGround = false;
			IsGround = rigidbody->GetGround();
			mAnimator->Play(L"JumpC", true);


		}
		else if (JumpCount == 1)
		{
			if (KEY_DOWN(eKeyCode::W))
			{
				Rigidbody* rigidbody = GetComponent<Rigidbody>();
				Vector2 velocity = rigidbody->GetVelocity();
				velocity.y = -630.0f;
				rigidbody->SetVelocity(velocity);

				rigidbody->SetGround(false);

				JumpCount = 2;
				SetJumpCount(JumpCount);
				mAnimator->Play(L"DoubleJumpC", false);;
			}

		}

	}

	void Player::BiggestSlide()
	{
		mItemTime += Time::DeltaTime();

		if (mItemTime >= 3.0f)
		{
			SetState(Player::eState::Mujuk);
		}
		/*
		mCollider->SetOffset(Vector2(200.0f, 375.0f));
		mCollider->SetScale(Vector2(200.0f, 370.0f));
		*/
		if (KEY_PREESE(eKeyCode::S))
		{
			mAnimator->Play(L"SlideC", true);
			mCollider->SetOffset(Vector2(200.0f, 475.0f));
			mCollider->SetScale(Vector2(200.0f, 170.0f));
		}
		else if (KEY_UP(eKeyCode::S))
		{
			mState = eState::Biggest;
		}
	}

	void Player::Mujuk()
	{
		mCollider->SetOffset(Vector2(10.0f, 125.0f));
		mCollider->SetScale(Vector2(100.0f, 150.0f));
		SetPos({ 400.0f, 500.0f });
		mSpeed = -300.0f;
		mMujukTime += Time::DeltaTime();

		if (mMujukTime >= 2.0f)
		{
			SetState(Player::eState::Walk);
		}

		mCollider->SetOffset(Vector2(10.0f, 125.0f));
		mCollider->SetScale(Vector2(100.0f, 150.0f));
		SetScale(Vector2(1.0f, 1.0f));
		if (KEY_DOWN(eKeyCode::W))
		{
			mState = eState::MujukJump;
		}
		else if (KEY_PREESE(eKeyCode::S))
		{
			mState = eState::MujukSlide;
		}
	}

	void Player::MujukJump()
	{
		mMujukTime += Time::DeltaTime();

		if (mMujukTime >= 2.0f)
		{
			SetState(Player::eState::Walk);
		}

		int JumpCount = GetJumpCount();
		Rigidbody* rigidbody = GetComponent<Rigidbody>();
		bool IsGround = false;
		IsGround = rigidbody->GetGround();

		if (IsGround == true)
		{
			JumpCount = 0;
			SetJumpCount(JumpCount);

		}

		if (JumpCount == 0)
		{
			Rigidbody* rigidbody = GetComponent<Rigidbody>();
			Vector2 velocity = rigidbody->GetVelocity();
			velocity.y = -630.0f;
			rigidbody->SetVelocity(velocity);

			rigidbody->SetGround(false);

			JumpCount = 1;
			SetJumpCount(JumpCount);

			bool IsGround = false;
			IsGround = rigidbody->GetGround();
			mAnimator->Play(L"JumpC", true);


		}
		else if (JumpCount == 1)
		{
			if (KEY_DOWN(eKeyCode::W))
			{
				Rigidbody* rigidbody = GetComponent<Rigidbody>();
				Vector2 velocity = rigidbody->GetVelocity();
				velocity.y = -630.0f;
				rigidbody->SetVelocity(velocity);

				rigidbody->SetGround(false);

				JumpCount = 2;
				SetJumpCount(JumpCount);
				mAnimator->Play(L"DoubleJumpC", false);;
			}

		}
	}

	void Player::MujukSlide()
	{
		mMujukTime += Time::DeltaTime();

		if (mMujukTime >= 3.0f)
		{
			SetState(Player::eState::Walk);
		}

		if (KEY_PREESE(eKeyCode::S))
		{
			mAnimator->Play(L"SlideC", true);
			mCollider->SetOffset(Vector2(10.0f, 164.0f));
			mCollider->SetScale(Vector2(100.0f, 70.0f));
		}
		else if (KEY_UP(eKeyCode::S))
		{
			mState = eState::Mujuk;
		}

	}

	void Player::Run()
	{

		mAnimator->Play(L"RunC", true);

		mSpeed = -600.0f;

		mItemTime += Time::DeltaTime();

		if (mItemTime >= 3.0f)
		{
			SetState(Player::eState::Mujuk);
		}

		if (KEY_DOWN(eKeyCode::W))
		{
			mState = eState::RunJump;
		}
		else if (KEY_PREESE(eKeyCode::S))
		{
			mState = eState::RunSlide;
		}
	}

	void Player::RunJump()
	{
		mItemTime += Time::DeltaTime();

		if (mItemTime >= 3.0f)
		{
			SetState(Player::eState::Mujuk);
		}
		int JumpCount = GetJumpCount();
		Rigidbody* rigidbody = GetComponent<Rigidbody>();
		bool IsGround = false;
		IsGround = rigidbody->GetGround();

		if (IsGround == true)
		{
			JumpCount = 0;
			SetJumpCount(JumpCount);

		}

		if (JumpCount == 0)
		{
			Rigidbody* rigidbody = GetComponent<Rigidbody>();
			Vector2 velocity = rigidbody->GetVelocity();
			velocity.y = -630.0f;
			rigidbody->SetVelocity(velocity);

			rigidbody->SetGround(false);

			JumpCount = 1;
			SetJumpCount(JumpCount);

			bool IsGround = false;
			IsGround = rigidbody->GetGround();
			mAnimator->Play(L"JumpC", true);


		}
		else if (JumpCount == 1)
		{
			if (KEY_DOWN(eKeyCode::W))
			{
				Rigidbody* rigidbody = GetComponent<Rigidbody>();
				Vector2 velocity = rigidbody->GetVelocity();
				velocity.y = -630.0f;
				rigidbody->SetVelocity(velocity);

				rigidbody->SetGround(false);

				JumpCount = 2;
				SetJumpCount(JumpCount);
				mAnimator->Play(L"DoubleJumpC", false);;
			}

		}
	}

	void Player::RunSlide()
	{
		mItemTime += Time::DeltaTime();

		if (mItemTime >= 3.0f)
		{
			SetState(Player::eState::Mujuk);
		}
		if (KEY_PREESE(eKeyCode::S))
		{
			mAnimator->Play(L"SlideC", true);
			mCollider->SetOffset(Vector2(200.0f, 475.0f));
			mCollider->SetScale(Vector2(200.0f, 170.0f));
		}
		else if (KEY_UP(eKeyCode::S))
		{
			mState = eState::Run;
		}
	}

	void Player::Walk()
	{

		mCollider->SetOffset(Vector2(10.0f, 125.0f));
		mCollider->SetScale(Vector2(100.0f, 150.0f));
		SetScale(Vector2(1.0f, 1.0f));
		//mSpeed=-300.0f;
		if (KEY_DOWN(eKeyCode::W))
		{
			mState = eState::Jump;
		}
		else if (KEY_PREESE(eKeyCode::S))
		{
			mState = eState::Slide;
		}
	}

	void Player::LandingComplete()
	{
		mAnimator->Play(L"WalkC", true);
		mState = eState::Walk;
	}

}
