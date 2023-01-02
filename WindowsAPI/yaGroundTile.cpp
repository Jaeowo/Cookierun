#include "yaGroundTile.h"
#include "yaResources.h"
#include "yaImage.h"
#include "yaApplication.h"

namespace ya
{
	GroundTile::GroundTile()
		:mSpeed(-300.0f)
		,mCount(1)
	{
		SetName(L"Tile1");

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Tile1", L"..\\Resources\\Image\\Tile2.bmp");
		}
	
		//SetPos(Vector2{ 0.0f ,700.0f });
	
	

	}
	GroundTile::~GroundTile()
	{
	}
	void GroundTile::Tick()
	{

		GameObject::Tick();

		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
			Translate(mSpeed);
	}
	void GroundTile::Render(HDC hdc)
	{
		//mCount = GetCount();

		//Vector2 pos = GetPos();
		//Vector2 scale = GetScale();
		////Vector2 finalPos = pos;

		//Vector2 rect;
		//rect.x = mImage->GetWidth() * scale.x;
		//rect.y = mImage->GetHeight() * scale.y;

		//for (int i = 0; i <= mCount; ++i)
		//{
		//	TransparentBlt(hdc, (pos.x + rect.x) * i , pos.y, rect.x, rect.y
		//		, mImage->GetDC(), 0 , 0, mImage->GetWidth(), mImage->GetHeight()
		//		, RGB(255, 0, 255));
		//}
	

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