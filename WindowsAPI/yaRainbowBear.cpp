#include "yaRainbowBear.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"
#include "yaSound.h"
#include "yaObject.h"
#include "yaEatingEffect.h"
namespace ya
{
	RainbowBear::RainbowBear(Vector2 pos)
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Jelly\\RainbowBear"
			, L"RainbowBear", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"RainbowBear", true);
		SetPos(pos);
		AddComponent(mAnimator);

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			col->SetPos(pos);
			//col->SetScale(Vector2(60.0f, 60.0f));
			AddComponent(col);
		}

	}

	RainbowBear::RainbowBear()
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Jelly\\RainbowBear"
			, L"RainbowBear", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"RainbowBear", true);

		AddComponent(mAnimator);

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			//col->SetScale(Vector2(60.0f, 60.0f));
			AddComponent(col);
		}

	}
	RainbowBear::~RainbowBear()
	{
	}
	void RainbowBear::Tick()
	{
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
		GameObject::Tick();
	}
	void RainbowBear::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void RainbowBear::OnCollisionEnter(Collider* other)
	{
		Vector2 Pos = GetPos();

		EatingEffect* eatingeffect = ya::object::Instantiate<EatingEffect>(eColliderLayer::Effect);
		eatingeffect->SetPos(Pos);
		Sound* sound = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
		sound->Load(L"..\\Resources\\Sound\\g_BigBearJelly.wav");
		sound->Play(false);
		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		int Score = playerObj->GetScore();
		Score += 10000;
		playerObj->SetScore(Score);

		this->Death();
	}
}