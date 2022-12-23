#include "yaGoldCoin.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"

namespace ya
{
	GoldCoin::GoldCoin(Vector2 pos)
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();
		SetPos(pos);
		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Jelly\\GoldCoin"
			, L"GoldCoin", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"GoldCoin", true);

		AddComponent(mAnimator);

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			col->SetPos(pos);
			col->SetScale(Vector2(50.0f, 50.0f));
			AddComponent(col);
		}

	}

	GoldCoin::GoldCoin()
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Jelly\\GoldCoin"
			, L"GoldCoin", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"GoldCoin", true);

		AddComponent(mAnimator);

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			col->SetScale(Vector2(50.0f, 50.0f));
			AddComponent(col);
		}

	}
	GoldCoin::~GoldCoin()
	{
	}
	void GoldCoin::Tick()
	{

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
			Translate(mSpeed);
		GameObject::Tick();
	}
	void GoldCoin::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void GoldCoin::OnCollisionEnter(Collider* other)
	{
		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		int Score = playerObj->GetScore();
		Score += 700;
		playerObj->SetScore(Score);

		this->Death();
	}
}