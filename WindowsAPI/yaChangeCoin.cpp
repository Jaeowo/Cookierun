#include "yaChangeCoin.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"

namespace ya
{
	ChangeCoin::ChangeCoin(Vector2 pos)
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		SetPos(pos);
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Item\\ChangeCoin"
			, L"ChangeCoin", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"ChangeCoin", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetPos(pos);
		col->SetScale(Vector2(70.0f, 70.0f));
		AddComponent(col);

	}

	ChangeCoin::ChangeCoin()
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Item\\ChangeCoin"
			, L"ChangeCoin", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"ChangeCoin", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetScale(Vector2(70.0f, 70.0f));
		AddComponent(col);

	}
	ChangeCoin::~ChangeCoin()
	{
	}
	void ChangeCoin::Tick()
	{

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
			Translate(mSpeed);
		GameObject::Tick();
	}
	void ChangeCoin::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void ChangeCoin::OnCollisionEnter(Collider* other)
	{

		this->Death();

	}
}