#include "yaYellowBear.h"
#include "yaResources.h"
#include "yaCollider.h"
#include "yaImage.h"
#include "yaPlayer.h"
#include "yaEatingEffect.h"
#include "yaApplication.h"
#include "yaCamera.h"
#include "yaGameObjectManager.h"
#include "yaSound.h"
#include "yaObject.h"
namespace ya
{
	YellowBear::YellowBear(Vector2 pos)
		:mSpeed(-300.0f)
	{
		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"YellowBear", L"..\\Resources\\Image\\Jelly\\YellowBear.bmp");
		}
		SetPos(pos);
		SetPos({ 1200, 500 });
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			col->SetPos(pos);
			col->SetScale(Vector2(60.0f, 60.0f));
			AddComponent(col);
		}
	}

	YellowBear::YellowBear()
		:mSpeed(-300.0f)
	{
		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"YellowBear", L"..\\Resources\\Image\\Jelly\\YellowBear.bmp");
		}
		SetPos({ 1200, 500 });
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
		{
			Collider* col = new Collider();
			col->SetScale(Vector2(60.0f, 60.0f));
			AddComponent(col);
		}
	}
	YellowBear::~YellowBear()
	{
	}
	void YellowBear::Tick()
	{
		GameObject::Tick();
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
	}
	void YellowBear::Render(HDC hdc)
	{

		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		Vector2 finalPos;
		finalPos.x = (pos.x - mImage->GetWidth() * (scale.x / 2.0f));
		finalPos.y = (pos.y - mImage->GetHeight() * (scale.y / 2.0f));

		finalPos = Camera::CalculatePos(finalPos);

		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;
		GameObject::Render(hdc);

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 225; // 0 - 225

		AlphaBlend(hdc, finalPos.x, finalPos.y, rect.x, rect.y,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, func);

		GameObject::Render(hdc);
	}
	void YellowBear::OnCollisionEnter(Collider* other)
	{
		Vector2 Pos = GetPos();

		EatingEffect* eatingeffect = ya::object::Instantiate<EatingEffect>(eColliderLayer::Effect);
		eatingeffect->SetPos(Pos);
		Sound* sound = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
		sound->Load(L"..\\Resources\\Sound\\g_jelly.wav");
		sound->Play(false);
		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		int Score = playerObj->GetScore();
		Score += 2000;
		playerObj->SetScore(Score);

		this->Death();
	}
}