#include "yaSquirrel.h"
#include "yaPlayer.h"
#include "yaAnimator.h"
#include "yaGameObject.h"
#include "yaComponent.h"
#include "yaObject.h"
#include "yaCollider.h"

namespace ya
{
	Squirrel::Squirrel()
	{
		//SetPos({300.0f, 600.0f }); //플레이어 옆에 쫓아가도록 바꾸기
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Squirrel\\WalkP"
			, L"WalkS", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"WalkS", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		//col->SetOffset(Vector2(0.0f, 45.0f));
		AddComponent(col);
		
		mPlayer = new Player();

	}
	Squirrel::~Squirrel()
	{
	}
	void Squirrel::Tick()
	{
		GameObject::Tick();

		Vector2 Playerpos = mPlayer->GetPos();
		SetPos({ Playerpos.x - 100.0f, Playerpos.y });
		
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