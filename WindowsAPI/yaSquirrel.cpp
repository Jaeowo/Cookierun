#include "yaSquirrel.h"
#include "yaPlayer.h"
#include "yaAnimator.h"

namespace ya
{
	Squirrel::Squirrel()
	{
		SetPos({ 200.0f, 600.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Squirrel\\WalkP"
			, L"WalkS", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"WalkS", true);
		AddComponent(mAnimator);

	}
	Squirrel::~Squirrel()
	{
	}
	void Squirrel::Tick()
	{
		GameObject::Tick();
	}
	void Squirrel::Render(HDC hdc)
	{


		GameObject::Render(hdc);
	}
	void Squirrel::OnCollisionEnter(Collider* other)
	{
	}
	void Squirrel::OnCollisionStay(Collider* other)
	{
	}
	void Squirrel::OnCollisionExit(Collider* other)
	{
	}
}