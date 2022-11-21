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

namespace ya
{
	Player::Player()
		: mSpeed(1.0f)
		, mHp(100)
	{
		SetName(L"Player");
		SetPos({ 300.0f, 600.0f });
		SetScale({ 1.0f, 1.0f });

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\Walk"
			, L"WalkC", Vector2(0, 0), 0.15f);

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\DoubleJump"
			, L"DoubleJumpC", Vector2(0, 0), 0.15f);

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\Jump"
			, L"JumpC", Vector2(0, 0), 0.2f);

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\Slide"
			, L"SlideC", Vector2(0, 0), 0.2f);

		mAnimator->Play(L"WalkC", true);

		AddComponent(mAnimator);
		Collider* col = new Collider();
		col->SetScale(Vector2(100.0f, 150.0f));
		col->SetOffset(Vector2(10.0f, 125.0f));
		AddComponent(col);

		//지금 중앙을 중심으로 보고있는데 좌하단 위치로 바꿔주기
		Camera::SetTarget(this);

		AddComponent<Rigidbody>();


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


		
		//Vector2 pos = GetPos();

		//Vector2 scale = GetScale();
		//scale += Time::DeltaTime();
		//SetScale(scale);
		//
		//if (KEY_PREESE(eKeyCode::W))
		//{
		//	pos.y -= 120.0f * Time::DeltaTime();
		//	//missile->mDir.y = -1.0f;
		//}
		//if (KEY_PREESE(eKeyCode::S))
		//{
		//	pos.y += 120.0f * Time::DeltaTime();
		//}
		//if (KEY_PREESE(eKeyCode::A))
		//{
		//	pos.x -= 120.0f * Time::DeltaTime();
		//	//missile->mDir.x = 1.0f;
		//}
		//if (KEY_PREESE(eKeyCode::D))
		//{
		//	pos.x += 120.0f * Time::DeltaTime();
		//}
		if (KEY_DOWN(eKeyCode::SPACE))
		{
			Rigidbody* rigidbody = GetComponent<Rigidbody>();
			Vector2 velocity = rigidbody->GetVelocity();
			velocity.y = -500.0f;
			rigidbody->SetVelocity(velocity);

			rigidbody->SetGround(false);

		}

	


		//SetPos(pos);
	}

	void Player::Render(HDC hdc)
	{
		//HBRUSH blueBrush = CreateSolidBrush(RGB(153, 204, 255));
		//Brush brush(hdc, blueBrush);

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//Pen pen(hdc, redPen);





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
}
