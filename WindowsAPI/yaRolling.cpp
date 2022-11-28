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
		SetPos({ 700.0f, 650.0f });
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

		//일정 시간마다 통통 튀어오르도록 만들어보기
		mLength = (mSpeed * Time::DeltaTime());

		if (mLength >= 300.0f)
		{
			
			//mLength = 0;
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
		playerObj->SetState(Player::eState::Attack);
		playerObj->GetComponent<Animator>()->Play(L"AttackC", false);

		int hp = playerObj->GetHp();
		hp -= 10;
		playerObj->SetHp(hp);
	}
	void Rolling::OnCollisionStay(Collider* other)
	{
	}
	void Rolling::OnCollisionExit(Collider* other)
	{
	}
}
