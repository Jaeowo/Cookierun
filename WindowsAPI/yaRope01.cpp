#include "yaRope01.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"

namespace ya
{
	Rope01::Rope01()
		: mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 650.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rope01\\Wait"
			, L"Rope01Wait", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Rope01Wait", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		AddComponent(col);
	}
	Rope01::~Rope01()
	{
	}
	void Rope01::Tick()
	{
		GameObject::Tick();
		Translate(mSpeed);
	}
	void Rope01::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Rope01::OnCollisionEnter(Collider* other)
	{
		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		playerObj->SetState(Player::eState::Attack);
		playerObj->GetComponent<Animator>()->Play(L"AttackC", false);

		int hp = playerObj->GetHp();
		hp -= 10;
		playerObj->SetHp(hp);
	}
	void Rope01::OnCollisionStay(Collider* other)
	{
	}
	void Rope01::OnCollisionExit(Collider* other)
	{
	}
}