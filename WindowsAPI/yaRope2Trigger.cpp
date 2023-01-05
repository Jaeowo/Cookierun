#include "yaRope2Trigger.h"
#include "yaCollider.h"
#include "yaRope02.h"
#include "yaAnimator.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"
#include "yaPlayer.h"
namespace ya
{
	Rope2Trigger::Rope2Trigger(Vector2 pos)
		: mSpeed(-300.0f)
	{
		Collider* col = new Collider();
		col->SetPos(pos);
		col->SetScale(Vector2(900.0f, 1000.0f));
		//col->SetOffset(Vector2(50.0f, 55.0f));
		AddComponent(col);
	}
	Rope2Trigger::Rope2Trigger()
	{
	}
	Rope2Trigger::~Rope2Trigger()
	{
	}
	void Rope2Trigger::Tick()
	{
		if (GameObjectManager::GetPlayer()->GetState() == Player::eState::Death)
		{
			mSpeed = 0;
		}

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
	}
	void Rope2Trigger::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Rope2Trigger::OnCollisionEnter(Collider* other)
	{
		Rope02* rope2obj = dynamic_cast<Rope02*>(mTarget);
		rope2obj->GetComponent<Animator>()->Play(L"Rope02Active", false);
	}
}