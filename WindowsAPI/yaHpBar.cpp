#include "yaHpBar.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaPlayer.h"
#include "yaApplication.h"

namespace ya
{
	HpBar::HpBar(eUIType type)
		: UiBase(type)
	{
		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"HpBar", L"..\\Resources\\Image\\UI\\HpBar.bmp");
		}

	/*	eSceneType stype = ya::Application::GetInstance().GetPlaySceneType();
		if (stype != eSceneType::Play)
		{
			return;
		}*/
	}
	HpBar::~HpBar()
	{
	}
	void HpBar::OnInit()
	{
	}
	void HpBar::OnActive()
	{
	}
	void HpBar::OnInActive()
	{
	}
	void HpBar::OnTick()
	{
	}
	void HpBar::OnRender(HDC hdc)
	{
		if (mImage == nullptr)
			return;

		if (mTarget == nullptr)
			return;

		Player* playerObj = dynamic_cast<Player*>(mTarget);
		int hp = playerObj->GetHp();
		float xRatio = (hp / 100.0f);
		
		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255;

		AlphaBlend(hdc, (int)mScreenPos.x, (int)mScreenPos.y
			, mImage->GetWidth() * xRatio, mImage->GetHeight()
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), func);
	

	}
	void HpBar::OnClear()
	{
	}
}