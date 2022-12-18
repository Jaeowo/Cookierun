#include "yaDown.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaTime.h"
#include "yaPlayer.h"
#include "yaApplication.h"

namespace ya
{
	Down::Down()
		:mSpeed(-300.0f)
		,mState(eState::Run)
	{
		SetPos({ 2400.0f, 605.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Down"
			, L"Down", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Down", true);

		AddComponent(mAnimator);

		//mLength = Time::DeltaTime();
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			col->SetOffset(Vector2(0.0f, 45.0f));
			AddComponent(col);
		}

	}
	Down::~Down()
	{
	}
	void Down::Tick()
	{
		GameObject::Tick();

		//case ya::Player::eState::Walk:
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
			Translate(mSpeed);


		switch (mState)
		{
		case ya::Down::eState::Run:
		{
		}
		break;
		case ya::Down::eState::Down:
		{
		}
		break;
		case ya::Down::eState::Away:
		{
			Vector2 pos = this->GetPos();
			//위에 매달린경우 -로 값 바꾸기
			pos.x += (400 * Time::DeltaTime());
			pos.y += (400 * Time::DeltaTime());
			this->SetPos(pos);
		}
		break;
		default:
			break;
		}

	}
	void Down::Render(HDC hdc)
	{

		GameObject::Render(hdc);
	}
	void Down::OnCollisionEnter(Collider* other)
	{

		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		

		if (   playerObj->GetState() == Player::eState::BiggestJump 
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
	void Down::OnCollisionStay(Collider* other)
	{
	}
	void Down::OnCollisionExit(Collider* other)
	{
	}
}