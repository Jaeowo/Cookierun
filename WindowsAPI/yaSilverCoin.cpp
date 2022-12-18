#include "yaSilverCoin.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"

namespace ya
{
	SilverCoin::SilverCoin()
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Jelly\\SilverCoin"
			, L"SilverCoin", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"SilverCoin", true);

		AddComponent(mAnimator);

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			col->SetScale(Vector2(60.0f, 60.0f));
			AddComponent(col);
		}

	}
	SilverCoin::~SilverCoin()
	{
	}
	void SilverCoin::Tick()
	{

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
			Translate(mSpeed);
		GameObject::Tick();
	}
	void SilverCoin::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void SilverCoin::OnCollisionEnter(Collider* other)
	{
		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		int Score = playerObj->GetScore();
		Score += 500;
		playerObj->SetScore(Score);

		this->Death();
	}
}