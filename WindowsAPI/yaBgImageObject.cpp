#include "yaBgImageObject.h"
#include "yaResources.h"
#include "yaImage.h"
#include "yaCamera.h"
#include "yaTime.h"

namespace ya
{
	BgImageObject::BgImageObject()
		: mImage(nullptr)
		,mSpeed(0.0f)
	{
		SetPos(Vector2::Zero);
		SetScale(Vector2::One);
	}

	BgImageObject::~BgImageObject()
	{

	}

	void BgImageObject::Initialize()
	{

	}

	void BgImageObject::Tick()
	{
		GameObject::Tick();
	}

	void BgImageObject::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();
		Vector2 finalPos = pos;
		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;

		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));

		Translate(mSpeed);

		/*
		TransparentBlt
		복사할 DC
		윈도우 창 출력 시작 위치 XY
		출력할 크기 XY
		복사할 DC
		복사할 대상의 시작위치 XY - *이부분 수정해주면 움직인듯
		복사할 XY 범위 
		무효처리할 색상값
		*/

		GameObject::Render(hdc);

	}

	void BgImageObject::SetImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\Image\\";
		path += fileName;
		
		mImage = Resources::Load<Image>(key, path);
	}


}