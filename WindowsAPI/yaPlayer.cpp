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
		: mSpeed(1.0f)
		, mHp(100)
	{
		SetName(L"Player");
		SetPos({ 400.0f, 600.0f });
		SetScale({ 1.0f, 1.0f });

		AddComponent<Rigidbody>();

		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\Walk"
			, L"WalkC", Vector2(0, 0), 0.15f);

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\DoubleJump"
			, L"DoubleJumpC", Vector2(0, 0), 0.1f);

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\Jump"
			, L"JumpC", Vector2(0, 0), 0.2f);

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\Slide"
			, L"SlideC", Vector2(0, 0), 0.2f);

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\Landing"
			, L"LandingC", Vector2(0, 0), 0.2f);

			mAnimator->Play(L"WalkC", true);
	

		AddComponent(mAnimator);
		
		Camera::SetTarget(this);

		Collider* col = new Collider();
		AddComponent(col);

		col->SetOffset(Vector2(10.0f, 125.0f));
		
		col->SetScale(Vector2(100.0f, 150.0f));
		


		mCoff = 0.1f;
	}

	Player::~Player()
	{

	}

	void Player::Tick()
	{
		GameObject::Tick();

		if (KEY_PREESE(eKeyCode::D))
		{
			GetComponent<Rigidbody>()->AddForce(Vector2(200.0f, 0.0f));
		}

		Jump();
		Slide();
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
	void Player::WalkComplete()
	{
	
		Scene* playScene = SceneManager::GetPlayScene();;

		Vector2 playerPos = GetPos();
		Vector2 playerScale = GetScale() / 2.0f;

	}
	void Player::Jump()
	{
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
			if (KEY_DOWN(eKeyCode::W))
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

				
				
			}
			if (KEY_DOWN(eKeyCode::W))
			{
				mAnimator->Play(L"JumpC", true);

			}
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
			}

			if (KEY_DOWN(eKeyCode::W))
			{
				mAnimator->Play(L"DoubleJumpC", false);

			}
		}
	
		//점프 끝나면 Landing 애니메이션 띄우고 다시 Walk
		//mAnimator->Play(L"LandingC", true);
		//mAnimator->Play(L"WalkC", true);
		
	}
	void Player::Slide()
	{
		//땅에 붙어있을 때만 사용가능
		Vector2 ColOffset;
		Vector2 ColScale;
;

		Rigidbody* rigidbody = GetComponent<Rigidbody>();
		bool IsGround = false;
		IsGround = rigidbody->GetGround();

		if (IsGround == true)
		{
			if (KEY_DOWN(eKeyCode::S))
			{
				mAnimator->Play(L"SlideC", true);

			}

			if (KEY_PREESE(eKeyCode::S))
			{
				//기존 충돌박스 삭제하고 새로 충돌박스 만들어 주고 싶은데 모르겠다
			}

			if (KEY_UP(eKeyCode::S))
			{
				//원래 충돌박스 설정으로

				mAnimator->Play(L"WalkC", true);
			}
		}
		}

	void Player::Walk()
	{
	}


}
