#include "yaGroundTile.h"
#include "yaResources.h"
#include "yaImage.h"

namespace ya
{
	GroundTile::GroundTile()
		:mSpeed(-300.0f)
		,mCount(1)
	{
		SetName(L"Tile1");

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Tile1", L"..\\Resources\\Image\\Tile1.bmp");
		}

	}
	GroundTile::~GroundTile()
	{
	}
	void GroundTile::Tick()
	{
		Translate(mSpeed);
		GameObject::Tick();
	}
	void GroundTile::Render(HDC hdc)
	{
		mCount = GetCount();

		Vector2 pos = GetPos();
		Vector2 scale = GetScale();
		Vector2 finalPos = pos;

		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;

		for (int i = 1; i <= mCount; ++i)
		{
			TransparentBlt(hdc, (finalPos.x) * i , finalPos.y, rect.x, rect.y
				, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
				, RGB(255, 0, 255));
		}



		GameObject::Render(hdc);
	}
}