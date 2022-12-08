#include "yaMagnet.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"

namespace ya
{
	Magnet::Magnet()
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Item\\Magnet"
			, L"Magnet", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"Magnet", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetScale(Vector2(70.0f, 70.0f));
		AddComponent(col);

	}
	Magnet::~Magnet()
	{
	}
	void Magnet::Tick()
	{

		Translate(mSpeed);
		GameObject::Tick();
	}
	void Magnet::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Magnet::OnCollisionEnter(Collider* other)
	{

		this->Death();

	}
}
