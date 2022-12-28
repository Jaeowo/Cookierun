#include "yaSquirrel.h"
#include "yaPlayer.h"
#include "yaAnimator.h"
#include "yaGameObject.h"
#include "yaComponent.h"
#include "yaObject.h"
#include "yaCollider.h"
#include "yaGameObjectManager.h"
#include "yaTime.h"

namespace ya
{
	Squirrel::Squirrel()
		:mState(eState::Trace)
	{
		//플레이어 옆에 쫓아가도록 바꾸기

		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Squirrel\\WalkP"
			, L"WalkS", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"WalkS", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		AddComponent(col);

	
	}
	Squirrel::~Squirrel()
	{
	}
	void Squirrel::Tick()
	{
		GameObject::Tick();
		
		switch (mState)
		{
		case ya::Squirrel::eState::Trace:
		{
			Vector2 PlayerPos = GameObjectManager::GetPlayer()->GetPos();
			Vector2 Pos = GetPos();
			

			Pos.x = (PlayerPos.x - 100.0f);
			Pos.y = PlayerPos.y;
			//Vector2 Dir = PlayerPos - Pos;
			//Dir.Normalize();

			//Pos += (Pos * Dir) * Time::DeltaTime();

			SetPos(Pos);
			
		}
		break;
		case ya::Squirrel::eState::Magnet:
		{
			
		}
		break;
		case ya::Squirrel::eState::BonusTime:
		{

		}
		break;
		default:
			break;
		}
		
	}
	void Squirrel::Render(HDC hdc)
	{
		GameObject::Render(hdc);

	}
	void Squirrel::OnCollisionEnter(Collider* other)
	{
	}
	void Squirrel::OnCollisionStay(Collider* other)
	{
	}
	void Squirrel::OnCollisionExit(Collider* other)
	{
	}
}