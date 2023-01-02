#include "yaChangeBear.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"

namespace ya
{
	ChangeBear::ChangeBear(Vector2 pos)
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });

		SetPos(pos);
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Item\\ChangeBear"
			, L"ChangeBear", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"ChangeBear", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetPos(pos);
		col->SetScale(Vector2(70.0f, 70.0f));
		AddComponent(col);

	}

	ChangeBear::ChangeBear()
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Item\\ChangeBear"
			, L"ChangeBear", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"ChangeBear", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetScale(Vector2(70.0f, 70.0f));
		AddComponent(col);

	}
	ChangeBear::~ChangeBear()
	{
	}
	void ChangeBear::Tick()
	{

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
			Translate(mSpeed);
		GameObject::Tick();
	}
	void ChangeBear::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void ChangeBear::OnCollisionEnter(Collider* other)
	{

		this->Death();

	}
}