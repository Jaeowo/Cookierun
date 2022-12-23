#include "yaBigBear.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"

namespace ya
{


	BigBear::BigBear(Vector2 pos)
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();

		//std::filesystem::path clear();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Jelly\\BigBear"
			, L"BigBear", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"BigBear", true);
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

	BigBear::BigBear()
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();

		//std::filesystem::path clear();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Jelly\\BigBear"
			, L"BigBear", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"BigBear", true);

		AddComponent(mAnimator);
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			//col->SetScale(Vector2(60.0f, 60.0f));
			AddComponent(col);
		}

	}
	BigBear::~BigBear()
	{
	}
	void BigBear::Tick()
	{
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
			Translate(mSpeed);

		GameObject::Tick();
	}
	void BigBear::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void BigBear::OnCollisionEnter(Collider* other)
	{
		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		int Score = playerObj->GetScore();
		Score += 7000;
		playerObj->SetScore(Score);

		this->Death();
	}
}