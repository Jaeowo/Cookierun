#include "yaRope02.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaTime.h"
#include "yaGameObjectManager.h"		
#include "yaSound.h"
#include "yaObject.h"
namespace ya
{
	Rope02::Rope02(Vector2 pos)
		: mSpeed(-300.0f)
		, mState(eState::None)
	{
		SetPos({ 3200.0f, 160.0f });
		SetPos(pos);
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rope02\\Wait"
			, L"Rope02Wait", Vector2(0, 0), 0.15f);

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rope02\\Active"
			, L"Rope02Active", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Rope02Wait", true);

		AddComponent(mAnimator);




		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			col->SetPos(pos);
			col->SetScale(Vector2(100.0f, 800.0f));
			col->SetOffset(Vector2(50.0f, 55.0f));
			AddComponent(col);
		}
	}

	Rope02::Rope02()
		: mSpeed (-300.0f)
		, mState(eState::None)
	{
		SetPos({ 3200.0f, 160.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rope02\\Wait"
			, L"Rope02Wait", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Rope02Wait", true);

		AddComponent(mAnimator);


	

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			col->SetScale(Vector2(100.0f, 800.0f));
			col->SetOffset(Vector2(50.0f, 55.0f));
			AddComponent(col);
		}
	}
	Rope02::~Rope02()
	{
	}
	void Rope02::Tick()
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
		case ya::Rope02::eState::None:
		{

		}
		break;
		case ya::Rope02::eState::Away:
		{
			Vector2 pos = this->GetPos();
			//???? ?????????? -?? ?? ??????
			pos.x += (400 * Time::DeltaTime());
			pos.y -= (400 * Time::DeltaTime());
			this->SetPos(pos);
		}
		break;
		default:
			break;
		}
	}
	void Rope02::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Rope02::OnCollisionEnter(Collider* other)
	{
		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		if (playerObj->GetState() == Player::eState::BiggestJump
			|| playerObj->GetState() == Player::eState::BiggestSlide
			|| playerObj->GetState() == Player::eState::Biggest)
		{
			Sound* sound2 = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
			sound2->Load(L"..\\Resources\\Sound\\g_giantland.wav");
			sound2->Play(false);
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
			Sound* sound3 = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
			sound3->Load(L"..\\Resources\\Sound\\g_giantland.wav");
			sound3->Play(false);
		}
		else
		{
			playerObj->SetState(Player::eState::Attack);
			Sound* sound = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
			sound->Load(L"..\\Resources\\Sound\\g_obs1.wav");
			sound->Play(false);
			playerObj->GetComponent<Animator>()->Play(L"AttackC", false);
			int hp = playerObj->GetHp();
			hp -= 10;
			playerObj->SetHp(hp);
		}
	}
	void Rope02::OnCollisionStay(Collider* other)
	{
	}
	void Rope02::OnCollisionExit(Collider* other)
	{
	}
}