#include "yaDown.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaTime.h"

namespace ya
{
	Down::Down()
	{
		SetPos({ 1200.0f, 605.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Down"
			, L"Down", Vector2(0, 0), 0.35f);

		mAnimator->Play(L"Down", false);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetOffset(Vector2(0.0f, 45.0f));
		AddComponent(col);

		//mLength = Time::DeltaTime();
	}
	Down::~Down()
	{
	}
	void Down::Tick()
	{
		GameObject::Tick();
	}
	void Down::Render(HDC hdc)
	{

		GameObject::Render(hdc);
	}
	void Down::OnCollisionEnter(Collider* other)
	{
	}
	void Down::OnCollisionStay(Collider* other)
	{
	}
	void Down::OnCollisionExit(Collider* other)
	{
	}
}