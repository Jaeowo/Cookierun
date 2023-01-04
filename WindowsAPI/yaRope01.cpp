#include "yaRope01.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaTime.h"
#include "yaGameObjectManager.h"	
namespace ya
{
	Rope01::Rope01(Vector2 pos)
		: mSpeed(-300.0f)
		, mState(eState::None)
	{
		SetPos({ 3400.0f, 270.0f });
		SetPos(pos);
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rope01\\Wait"
			, L"Rope01Wait", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Rope01Wait", true);

		AddComponent(mAnimator);


		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			col->SetPos(pos);
			col->SetScale(Vector2(100.0f, 700.0f));
			AddComponent(col);
		}
	}

	Rope01::Rope01()
		: mSpeed(-300.0f)
		, mState(eState::None)
	{
		SetPos({ 3400.0f, 270.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rope01\\Wait"
			, L"Rope01Wait", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Rope01Wait", true);

		AddComponent(mAnimator);


		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			col->SetScale(Vector2(100.0f, 700.0f));
			AddComponent(col);
		}
	}
	Rope01::~Rope01()
	{
	}
	void Rope01::Tick()
	{
		GameObject::Tick();
		if (GameObjectManager::GetPlayer()->GetState() == Player::eState::Death)
		{
			mSpeed = 0;
		}

		if (GameObjectManager::GetPlayer()->GetState() == Player::eState::Run)
		{
			mSpeed = -500.0f;
		}
		else
		{
			mSpeed = -300.0f;
		}
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
			Translate(mSpeed);

		switch (mState)
		{
		case ya::Rope01::eState::None:
		{

		}
		break;
		case ya::Rope01::eState::Away:
		{
			Vector2 pos = this->GetPos();
			//위에 매달린경우 -로 값 바꾸기
			pos.x += (400 * Time::DeltaTime());
			pos.y -= (400 * Time::DeltaTime());
			this->SetPos(pos);
		}
		break;
		default:
			break;
		}

	}
	void Rope01::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Rope01::OnCollisionEnter(Collider* other)
	{
		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		if (playerObj->GetState() == Player::eState::BiggestJump
			|| playerObj->GetState() == Player::eState::BiggestSlide
			|| playerObj->GetState() == Player::eState::Biggest)
		{
			mState = eState::Away;
		}
		else if (playerObj->GetState() == Player::eState::Mujuk
			|| playerObj->GetState() == Player::eState::MujukJump
			|| playerObj->GetState() == Player::eState::MujukSlide)
		{
		}
		else if (playerObj->GetState() == Player::eState::Death)
		{
		}
		else if (playerObj->GetState() == Player::eState::Run
			|| playerObj->GetState() == Player::eState::RunJump
			|| playerObj->GetState() == Player::eState::RunSlide)
		{
			mState = eState::Away;
		}
		else
		{
			playerObj->SetState(Player::eState::Attack);
			playerObj->GetComponent<Animator>()->Play(L"AttackC", false);
			int hp = playerObj->GetHp();
			hp -= 10;
			playerObj->SetHp(hp);
		}
	}
	void Rope01::OnCollisionStay(Collider* other)
	{
	}
	void Rope01::OnCollisionExit(Collider* other)
	{
	}
}