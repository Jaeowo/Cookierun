#include "yaBiggest.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "resource.h"
#include "yaTime.h"
#include "yaApplication.h"

namespace ya
{
	Biggest::Biggest(Vector2 pos)
		:mSpeed(-300.0f)
		, mTime(0.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();
		SetPos(pos);
		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Item\\Biggest"
			, L"Biggest", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"Biggest", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetPos(pos);
		col->SetScale(Vector2(70.0f, 70.0f));
		AddComponent(col);

	}

	Biggest::Biggest()
		:mSpeed(-300.0f)
		,mTime(0.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Item\\Biggest"
			, L"Biggest", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"Biggest", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetScale(Vector2(70.0f, 70.0f));
		AddComponent(col);

	}
	Biggest::~Biggest()
	{
	}
	void Biggest::Tick()
	{
		GameObject::Tick();
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
			Translate(mSpeed);
	}
	void Biggest::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Biggest::OnCollisionEnter(Collider* other)
	{
		

		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());

		playerObj->SetState(Player::eState::Biggest);

		for (float i = 1.0f; i < 2.0f; i += 0.1f)
		{
			playerObj->SetScale(Vector2{ i,i });
		}

		playerObj->SetItemTime(0.0f);		
		
		this->Death();


	}

}