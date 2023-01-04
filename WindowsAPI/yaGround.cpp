#include "yaGround.h"
#include "yaPlayer.h"
#include "yaCollider.h"
#include "yaRigidbody.h"
#include "yaAnimator.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"

namespace ya
{
	Ground::Ground(Vector2 pos)
		:mSpeed(-300.0f)
	{
		SetPos(pos);
		//mColPos = (Vector2(8000.0f, 100.0f));

		mCollider = new Collider();
		mCollider->SetPos(pos);
		AddComponent(mCollider);


	}

	Ground::Ground()
		:mSpeed(-300.0f)
	{
		//mColPos = (Vector2(8000.0f, 100.0f));

		mCollider = new Collider();
		AddComponent(mCollider);
		

	}
	Ground::~Ground()
	{
	}
	void Ground::Tick()
	{
		if (GameObjectManager::GetPlayer()->GetState() == Player::eState::Run)
		{
			mSpeed = -500.0f;
		}
		else
		{
			mSpeed = -300.0f;
		}
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
			Translate(mSpeed);
		GameObject::Tick();
		mCollider->SetScale(mColPos);
	}
	void Ground::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Ground::OnCollisionEnter(Collider* other)
	{

		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		playerObj->GetComponent<Rigidbody>()->SetGround(true);
		playerObj->GetComponent<Animator>()->Play(L"WalkC", true);

		if (playerObj->GetState() == Player::eState::Jump)
		{
			playerObj->SetState(Player::eState::Walk);
			playerObj->GetComponent<Animator>()->Play(L"LandingC", false);
		}
	
		if (playerObj->GetState() == Player::eState::BiggestJump)
		{
			playerObj->SetState(Player::eState::Biggest);
			playerObj->GetComponent<Animator>()->Play(L"LandingC", false);
		}

		if (playerObj->GetState() == Player::eState::Biggest)
		{
			//playerObj->SetState(Player::eState::Biggest);
			//playerObj->GetComponent<Animator>()->Play(L"LandingC", false);
			float fLen = fabs(other->GetPos().y - GetComponent<Collider>()->GetPos().y);
			float fScale = other->GetScale().y / 2.0f + GetComponent<Collider>()->GetScale().y / 2.0f;


			if (fLen < fScale)
			{
				Vector2 playerPos = playerObj->GetPos();
				playerPos.y -= (fScale - fLen) - 1.0f;
				playerObj->SetPos(playerPos);
			}
		}

		if (playerObj->GetState() == Player::eState::RunJump)
		{
			playerObj->SetState(Player::eState::Run);
			playerObj->GetComponent<Animator>()->Play(L"RunC", true);
		}

		if (playerObj->GetState() == Player::eState::Swing)
		{
			playerObj->SetState(Player::eState::Swing);
			playerObj->GetComponent<Animator>()->Play(L"SwingC", true);
		}
		if (playerObj->GetState() == Player::eState::Back)
		{
			playerObj->SetState(Player::eState::Back);
			playerObj->GetComponent<Animator>()->Play(L"SwingC", true);
		}
	

		//float fLen = fabs(other->GetPos().y - GetComponent<Collider>()->GetPos().y);
		//float fScale = other->GetScale().y / 2.0f + GetComponent<Collider>()->GetScale().y / 2.0f;

		//if (fLen < fScale)
		//{
		//	Vector2 playerPos = playerObj->GetPos();
		//	playerPos.y -= (fScale - fLen) - 1.0f;
		//	playerObj->SetPos(playerPos);
		//}

	}
	void Ground::OnCollisionStay(Collider* other)
	{
	}
	void Ground::OnCollisionExit(Collider* other)
	{
	}


}
