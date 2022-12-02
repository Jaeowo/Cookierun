#include "yaRope02.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"

namespace ya
{
	Rope02::Rope02()
		: mSpeed (-300.0f)
	{
		SetPos({ 1900.0f, 650.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rope02\\Wait"
			, L"Rope02Wait", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Rope02Wait", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		AddComponent(col);
	}
	Rope02::~Rope02()
	{
	}
	void Rope02::Tick()
	{
		GameObject::Tick();
		Translate(mSpeed);
	}
	void Rope02::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Rope02::OnCollisionEnter(Collider* other)
	{
		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		playerObj->SetState(Player::eState::Attack);
		playerObj->GetComponent<Animator>()->Play(L"AttackC", false);

		int hp = playerObj->GetHp();
		hp -= 10;
		playerObj->SetHp(hp);
	}
	void Rope02::OnCollisionStay(Collider* other)
	{
	}
	void Rope02::OnCollisionExit(Collider* other)
	{
	}
}