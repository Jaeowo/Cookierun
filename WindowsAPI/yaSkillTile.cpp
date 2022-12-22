#include "yaSkillTile.h"
#include "yaResources.h"
#include "yaImage.h"

namespace ya
{
	SkillTile::SkillTile()
		:mSpeed(-50.0f)
		, mCount(1)
	{
		//SetName(L"Tile1");

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"SkillTile", L"..\\Resources\\Image\\LillyTile.bmp");
		}

	}
	SkillTile::~SkillTile()
	{
	}
	void SkillTile::Tick()
	{
		//Translate(mSpeed);
		GameObject::Tick();
	}
	void SkillTile::Render(HDC hdc)
	{
		mCount = GetCount();

		Vector2 pos = GetPos();
		Vector2 scale = GetScale();
		Vector2 finalPos = pos;

		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;



		for (int i = 0; i <= mCount; ++i)
		{
			TransparentBlt(hdc, (finalPos.x + rect.x) * i, finalPos.y, rect.x, rect.y
				, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
				, RGB(255, 0, 255));
		}



		GameObject::Render(hdc);
	}
}