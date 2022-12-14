#include "yaRolling.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"	
#include "yaSound.h"
#include "yaObject.h"

namespace ya
{
	Rolling::Rolling(Vector2 pos)
		:mSpeed(-300.0f)
		, mLength(0)
		, mState(eState::None)
	{

		mAnimator = new Animator();
		SetPos(pos);
		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rolling"
			, L"Rolling", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Rolling", true);

		AddComponent(mAnimator);

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			col->SetPos(pos);
			AddComponent(col);
		}

	}

	Rolling::Rolling()
		:mSpeed(-300.0f)
		,mLength(0)
		, mState(eState::None)
	{

		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rolling"
			, L"Rolling", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Rolling", true);

		AddComponent(mAnimator);

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			AddComponent(col);
		}

	}
	Rolling::~Rolling()
	{
	}
	void Rolling::Tick()
	{
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
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
		if (type != eSceneType::JellyTool)
			Translate(mSpeed);

		bool IsGround = false;

		mLength = (mSpeed * Time::DeltaTime());

		if (mLength >= 1000.0f)
		{
			RollingPos.y += 200;
			mLength = 0;
		}

		switch (mState)
		{
		case ya::Rolling::eState::None:
		{

		}
		break;
		case ya::Rolling::eState::Away:
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

		GameObject::Tick();
		
	}
	void Rolling::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Rolling::OnCollisionEnter(Collider* other)
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
	void Rolling::OnCollisionStay(Collider* other)
	{
	}
	void Rolling::OnCollisionExit(Collider* other)
	{
	}
}
