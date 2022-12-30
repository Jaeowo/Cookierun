#include "yaEatingEffect.h"
#include "yaResources.h"
#include "yaCollider.h"
#include "yaImage.h"
#include "yaPlayer.h"
#include "yaTime.h"
#include "yaCamera.h"

namespace ya
{
	EatingEffect::EatingEffect()
		:mSpeed(-300.0f)
		,mAlphaValue(225.0f)
	{
		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Eating", L"..\\Resources\\Image\\Jelly\\Eating.bmp");
		}
		
	}
	EatingEffect::~EatingEffect()
	{
	}
	void EatingEffect::Tick()
	{
		mCount += Time::DeltaTime();

		if (mCount >= 1.0f)
		{
			Death();
		}

		GameObject::Tick();
		Translate(mSpeed);
	}
	void EatingEffect::Render(HDC hdc)
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

		/*
			if (mBlink)
		{
			const float blinkSpeed = 100.0f;
			

			if (mAlphaValue <= 0.0f)
				mAlphaValue += (blinkSpeed * Time::DeltaTime());
			else
				mAlphaValue -= (blinkSpeed * Time::DeltaTime());
		}
		*/
	}
	void EatingEffect::OnCollisionEnter(Collider* other)
	{

	}
}