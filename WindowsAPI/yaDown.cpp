#include "yaDown.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaTime.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"
#include "yaSound.h"
#include "yaObject.h"

namespace ya
{
	Down::Down(Vector2 pos)
		:mSpeed(-300.0f)
		, mState(eState::Run)
	{
		SetPos({ 2400.0f, 605.0f });
		SetPos(pos);
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
			col->SetPos(pos);
			col->SetOffset(Vector2(0.0f, 45.0f));
			AddComponent(col);
		}

	}

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
			Sound* sound2 = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
			sound2->Load(L"..\\Resources\\Sound\\g_giantland.wav");
			sound2->Play(false);
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
			Sound* sound3 = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
			sound3->Load(L"..\\Resources\\Sound\\g_giantland.wav");
			sound3->Play(false);
		}
		else
		{
			playerObj->SetState(Player::eState::Attack);
			playerObj->GetComponent<Animator>()->Play(L"AttackC", false);
			Sound* sound = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
			sound->Load(L"..\\Resources\\Sound\\g_obs1.wav");
			sound->Play(false);
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