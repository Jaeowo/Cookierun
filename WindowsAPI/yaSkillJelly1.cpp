#include "yaSkillJelly1.h"
#include "yaResources.h"
#include "yaCollider.h"
#include "yaImage.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaCamera.h"
#include "yaGameObjectManager.h"
#include "yaTime.h"
namespace ya
{
	SkillJelly1::SkillJelly1()
		:mSpeed(-300.0f)
	{
		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"SkillJ1", L"..\\Resources\\Image\\Jelly\\Lilly\\SkillJ1.bmp");
		}

		Collider* col = new Collider();
		//col->SetScale(Vector2(60.0f, 60.0f));
		AddComponent(col);


	}
	SkillJelly1::~SkillJelly1()
	{
	}
	void SkillJelly1::Tick()
	{
		GameObject::Tick();
		Vector2 PlayerPos = GameObjectManager::GetPlayer()->GetPos();
		Vector2 Pos = GetPos();

		Vector2 Dir = PlayerPos - Pos;
		Dir.Normalize();

		Pos +=  (Pos * Dir) * Time::DeltaTime() ;

		SetPos(Pos);

		//Translate(mSpeed);
	}
	void SkillJelly1::Render(HDC hdc)
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
	void SkillJelly1::OnCollisionEnter(Collider* other)
	{
		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		int Score = playerObj->GetScore();
		Score += 2500;
		playerObj->SetScore(Score);

		this->Death();
	}
}