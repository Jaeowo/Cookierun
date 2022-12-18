#include "yaRolling.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaApplication.h"

namespace ya
{
	Rolling::Rolling()
		:mSpeed(-300.0f)
		,mLength(0)
		, mState(eState::None)
	{

		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rolling"
			, L"Rolling", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Rolling", true);

		AddComponent(mAnimator);

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			AddComponent(col);
		}

	}
	Rolling::~Rolling()
	{
	}
	void Rolling::Tick()
	{
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
			Translate(mSpeed);

		bool IsGround = false;

		mLength = (mSpeed * Time::DeltaTime());

		if (mLength >= 1000.0f)
		{
			RollingPos.y += 200;
			mLength = 0;
		}

		switch (mState)
		{
		case ya::Rolling::eState::None:
		{

		}
		break;
		case ya::Rolling::eState::Away:
		{
			Vector2 pos = this->GetPos();
			//위에 매달린경우 -로 값 바꾸기
			pos.x += (400 * Time::DeltaTime());
			pos.y += (400 * Time::DeltaTime());
			this->SetPos(pos);
		}
		break;
		default:
			break;
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
			mState = eState::Away;

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
