#include "yaFire02.h"
#include "yaAnimator.h"
#include "yaCollider.h"

namespace ya
{
	Fire02::Fire02()
	{
		SetPos({ 800.0f, 650.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Fire02"
			, L"Fire02", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Fire02", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		AddComponent(col);
	}
	Fire02::~Fire02()
	{
	}
	void Fire02::Tick()
	{
		GameObject::Tick();
	}
	void Fire02::Render(HDC hdc)
	{

		GameObject::Render(hdc);
	}
	void Fire02::OnCollisionEnter(Collider* other)
	{
	}
	void Fire02::OnCollisionStay(Collider* other)
	{
	}
	void Fire02::OnCollisionExit(Collider* other)
	{
	}
}
