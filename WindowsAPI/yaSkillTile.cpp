#include "yaSkillTile.h"
#include "yaResources.h"
#include "yaImage.h"

namespace ya
{
	SkillTile::SkillTile()
		:mSpeed(-300.0f)
		, mCount(1)
	{
		//SetName(L"Tile1");

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"SkillTile", L"..\\Resources\\Image\\LillyTile2.bmp");
		}

	}
	SkillTile::~SkillTile()
	{
	}
	void SkillTile::Tick()
	{
		Translate(mSpeed);
		GameObject::Tick();
	}
	void SkillTile::Render(HDC hdc)
	{

		Vector2 pos = GetPos();
		Vector2 finalPos = pos;
		Vector2 rect;
		rect.x = mImage->GetWidth();
		rect.y = mImage->GetHeight();

		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));


		GameObject::Render(hdc);
	}
}