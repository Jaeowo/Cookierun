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
		: mSpeed(200.0f)
		, mHp(100)
		, mCollision(false)
		, mState(eState::Walk)
	{
		SetName(L"Player");
		SetPos({ 400.0f, 600.0f });
		SetScale({ 1.0f, 1.0f });

		AddComponent<Rigidbody>();

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

		mAnimator->Play(L"WalkC", true);

		//mAnimator->FindEvents(L"MoveRight")->mCompleteEvent = std::bind(&Player::WalkComplete, this);
		//mAnimator->GetCompleteEvent(L"MoveRight") = std::bind(&Player::WalkComplete, this);

		//mAnimator->Play(L"MoveRight", true);
		//mAnimator->mCompleteEvent = std::bind(&Player::WalkComplete, this);

		mAnimator->GetCompleteEvent(L"LandingC") = std::bind(&Player::LandingComplete, this);
		mAnimator->GetCompleteEvent(L"AttackC") = std::bind(&Player::LandingComplete, this);
		

		AddComponent(mAnimator);
		
		Camera::SetTarget(this);

		mCollider = new Collider();
		AddComponent(mCollider);

		
		mCollider->SetOffset(Vector2(10.0f, 125.0f));
		mCollider->SetScale(Vector2(70.0f, 150.0f));



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
		case ya::Player::eState::Death:
		{

		}
		break;
		default:
			break;
		}


		//if (KEY_PREESE(eKeyCode::D))
		//{
		//	GetComponent<Rigidbody>()->AddForce(Vector2(200.0f, 0.0f));
		//}

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

	void Player::Walk()
	{
		//Translate(mSpeed);

		mCollider->SetOffset(Vector2(10.0f, 125.0f));
		mCollider->SetScale(Vector2(100.0f, 150.0f));
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

	bool Player::CheckCollision()
	{
		
		return false;
	}



}
