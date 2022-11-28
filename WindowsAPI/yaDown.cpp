#include "yaDown.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaTime.h"
#include "yaPlayer.h"

namespace ya
{
	Down::Down()
		:mSpeed(-300.0f)
		,mState(eState::Run)
	{
		SetPos({ 1400.0f, 605.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Down"
			, L"Down", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"Down", true);

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

		//case ya::Player::eState::Walk:

		Translate(mSpeed);
		switch (mState)
		{
		case ya::Down::eState::Run:
		{
		}
		break;
		case ya::Down::eState::Down:
		{
		}
		break;

		default:
			break;
		}

	}
	void Down::Render(HDC hdc)
	{

		GameObject::Render(hdc);
	}
	void Down::OnCollisionEnter(Collider* other)
	{

		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		playerObj->SetState(Player::eState::Attack);
		playerObj->GetComponent<Animator>()->Play(L"AttackC", false);

		int hp = playerObj->GetHp();
		hp -= 10;
		playerObj->SetHp(hp);
	}
	void Down::OnCollisionStay(Collider* other)
	{
	}
	void Down::OnCollisionExit(Collider* other)
	{
	}
}