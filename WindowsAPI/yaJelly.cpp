#include "yaJelly.h"
#include "yaResources.h"
#include "yaCollider.h"
#include "yaImage.h"
#include "yaPlayer.h"

namespace ya
{
	Jelly::Jelly()
		:mSpeed(-300.0f)
	{
		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Jelly", L"..\\Resources\\Image\\Jelly\\NormalJelly.bmp");
		}
		SetPos({ 300, 900 });
		AddComponent(new Collider());
	}
	Jelly::~Jelly()
	{
	}
	void Jelly::Tick()
	{
		GameObject::Tick();
		Translate(mSpeed);
	}
	void Jelly::Render(HDC hdc)
	{
	
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		Vector2 finalPos;
		finalPos.x = (pos.x - mImage->GetWidth() * (scale.x / 2.0f));
		finalPos.y = (pos.y - mImage->GetHeight() * (scale.y / 2.0f));

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
	void Jelly::OnCollisionEnter(Collider* other)
	{
		//점수추가
		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		int Score = playerObj->GetScore();
		Score += 1000;
		playerObj->SetScore(Score);
		
		this->Death();
	}

}