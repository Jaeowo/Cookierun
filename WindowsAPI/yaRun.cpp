#include "yaRun.h"
#include "yaAnimator.h"
#include "yaPlayer.h"
#include "yaCollider.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"
#include "yaSound.h"
#include "yaObject.h"
namespace ya
{
	Run::Run(Vector2 pos)
		:mSpeed(-300.0f)
		, mTime(0.0f)
	{
		SetPos({ 1500.0f, 405.0f });
		SetPos(pos);
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Item\\Run"
			, L"Run", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"Run", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetPos(pos);
		col->SetScale(Vector2(70.0f, 70.0f));
		AddComponent(col);

	}

	Run::Run()
		:mSpeed(-300.0f)
		, mTime(0.0f)
	{
		SetPos({ 1500.0f, 405.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Item\\Run"
			, L"Run", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"Run", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetScale(Vector2(70.0f, 70.0f));
		AddComponent(col);

	}
	Run::~Run()
	{
	}
	void Run::Tick()
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
	void Run::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Run::OnCollisionEnter(Collider* other)
	{
		Sound* sound = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
		sound->Load(L"..\\Resources\\Sound\\g_ijelly.wav");
		sound->Play(false);
		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());

		playerObj->SetState(Player::eState::Run);
		//장애물에서 Run일시에 속도 조정해주기

		playerObj->SetItemTime(0.0f);

		playerObj->GetComponent<Animator>()->Play(L"RunC", true);

		this->Death();


	}
}
