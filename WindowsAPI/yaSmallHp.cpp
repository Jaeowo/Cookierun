#include "yaSmallHp.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"
#include "yaSound.h"
#include "yaObject.h"
namespace ya
{
	SmallHp::SmallHp(Vector2 pos)
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		SetPos(pos);
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Item\\SmallHp"
			, L"SmallHp", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"SmallHp", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetPos(pos);
		col->SetScale(Vector2(70.0f, 70.0f));
		AddComponent(col);

	}

	SmallHp::SmallHp()
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Item\\SmallHp"
			, L"SmallHp", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"SmallHp", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetScale(Vector2(70.0f, 70.0f));
		AddComponent(col);

	}
	SmallHp::~SmallHp()
	{
	}
	void SmallHp::Tick()
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
	void SmallHp::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void SmallHp::OnCollisionEnter(Collider* other)
	{
		Sound* sound = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
		sound->Load(L"..\\Resources\\Sound\\g_ijelly.wav");
		sound->Play(false);

		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());

		int hp = playerObj->GetHp();
		hp += 10;
		playerObj->SetHp(hp);

		this->Death();


	}
}