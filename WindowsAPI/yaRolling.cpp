#include "yaRolling.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaRigidbody.h"
#include "yaTime.h"

namespace ya
{
	Rolling::Rolling()
		:mSpeed(-300.0f)
		,mLength(0)
	{
		Vector2 RollingPos = { 2600.0f, 650.0f };
		SetPos(RollingPos);

		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rolling"
			, L"Rolling", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Rolling", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		AddComponent(col);
		

	}
	Rolling::~Rolling()
	{
	}
	void Rolling::Tick()
	{
		Translate(mSpeed);

		bool IsGround = false;

		mLength = (mSpeed * Time::DeltaTime());

		if (mLength >= 1000.0f)
		{
			RollingPos.y += 200;
			mLength = 0;
		}

		

		GameObject::Tick();
		
	}
	void Rolling::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Rolling::OnCollisionEnter(Collider* other)
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
	void Rolling::OnCollisionStay(Collider* other)
	{
	}
	void Rolling::OnCollisionExit(Collider* other)
	{
	}
}
