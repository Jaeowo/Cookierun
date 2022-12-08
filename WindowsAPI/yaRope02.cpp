#include "yaRope02.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"

namespace ya
{
	Rope02::Rope02()
		: mSpeed (-300.0f)
	{
		SetPos({ 3200.0f, 160.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rope02\\Wait"
			, L"Rope02Wait", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Rope02Wait", true);

		AddComponent(mAnimator);


		Collider* col = new Collider();
		col->SetScale(Vector2(100.0f, 800.0f));
		col->SetOffset(Vector2(50.0f, 55.0f));
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
		if (playerObj->GetState() == Player::eState::BiggestJump
			|| playerObj->GetState() == Player::eState::BiggestSlide
			|| playerObj->GetState() == Player::eState::Biggest)
		{

		}
		else if (playerObj->GetState() == Player::eState::Mujuk
			|| playerObj->GetState() == Player::eState::MujukJump
			|| playerObj->GetState() == Player::eState::MujukSlide)
		{
		}
		else
		{
			playerObj->SetState(Player::eState::Attack);
			playerObj->GetComponent<Animator>()->Play(L"AttackC", false);
			int hp = playerObj->GetHp();
			hp -= 10;
			playerObj->SetHp(hp);
		}
	}
	void Rope02::OnCollisionStay(Collider* other)
	{
	}
	void Rope02::OnCollisionExit(Collider* other)
	{
	}
}