#include "yaGoBonusTime.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"

namespace ya
{
	GoBonusTime::GoBonusTime(Vector2 pos)
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();
		SetPos(pos);
		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Item\\Bonus"
			, L"Bonus", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"Bonus", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetPos(pos);
		col->SetScale(Vector2(70.0f, 70.0f));
		AddComponent(col);

	}

	GoBonusTime::GoBonusTime()
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Item\\Bonus"
			, L"Bonus", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"Bonus", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetScale(Vector2(70.0f, 70.0f));
		AddComponent(col);

	}
	GoBonusTime::~GoBonusTime()
	{
	}
	void GoBonusTime::Tick()
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
	void GoBonusTime::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void GoBonusTime::OnCollisionEnter(Collider* other)
	{

		this->Death();

	}
}