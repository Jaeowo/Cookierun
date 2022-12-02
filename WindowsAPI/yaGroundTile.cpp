#include "yaGroundTile.h"
#include "yaResources.h"
#include "yaImage.h"

namespace ya
{
	GroundTile::GroundTile()
		:mSpeed(-300.0f)
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
		GameObject::Render(hdc);
	}
}