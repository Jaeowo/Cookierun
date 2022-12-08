#include "yaFire02.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"

namespace ya
{
	Fire02::Fire02()
		:mSpeed(-300.0f)
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
		Translate(mSpeed);
	}
	void Fire02::Render(HDC hdc)
	{

		GameObject::Render(hdc);
	}
	void Fire02::OnCollisionEnter(Collider* other)
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
	void Fire02::OnCollisionStay(Collider* other)
	{
	}
	void Fire02::OnCollisionExit(Collider* other)
	{
	}
}
