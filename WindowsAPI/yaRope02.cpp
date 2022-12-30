#include "yaRope02.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaTime.h"

namespace ya
{
	Rope02::Rope02(Vector2 pos)
		: mSpeed(-300.0f)
		, mState(eState::None)
	{
		SetPos({ 3200.0f, 160.0f });
		SetPos(pos);
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rope02\\Wait"
			, L"Rope02Wait", Vector2(0, 0), 0.15f);

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rope02\\Active"
			, L"Rope02Active", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Rope02Wait", true);

		AddComponent(mAnimator);




		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			col->SetPos(pos);
			col->SetScale(Vector2(100.0f, 800.0f));
			col->SetOffset(Vector2(50.0f, 55.0f));
			AddComponent(col);
		}
	}

	Rope02::Rope02()
		: mSpeed (-300.0f)
		, mState(eState::None)
	{
		SetPos({ 3200.0f, 160.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Rope02\\Wait"
			, L"Rope02Wait", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Rope02Wait", true);

		AddComponent(mAnimator);


	

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			col->SetScale(Vector2(100.0f, 800.0f));
			col->SetOffset(Vector2(50.0f, 55.0f));
			AddComponent(col);
		}
	}
	Rope02::~Rope02()
	{
	}
	void Rope02::Tick()
	{
		GameObject::Tick();
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
			Translate(mSpeed);

		switch (mState)
		{
		case ya::Rope02::eState::None:
		{

		}
		break;
		case ya::Rope02::eState::Away:
		{
			Vector2 pos = this->GetPos();
			//위에 매달린경우 -로 값 바꾸기
			pos.x += (400 * Time::DeltaTime());
			pos.y -= (400 * Time::DeltaTime());
			this->SetPos(pos);
		}
		break;
		default:
			break;
		}
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
			mState = eState::Away;
		}
		else if (playerObj->GetState() == Player::eState::Mujuk
			|| playerObj->GetState() == Player::eState::MujukJump
			|| playerObj->GetState() == Player::eState::MujukSlide)
		{
		}
		else if (playerObj->GetState() == Player::eState::Run
			|| playerObj->GetState() == Player::eState::RunJump
			|| playerObj->GetState() == Player::eState::RunSlide)
		{
			mState = eState::Away;
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