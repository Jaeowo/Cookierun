#include "yaLeftLeaf.h"
#include "yaResources.h"
#include "yaCollider.h"
#include "yaImage.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaCamera.h"
#include "yaLeafFlower.h"

namespace ya
{
	LeftLeaf::LeftLeaf()
		:mSpeed(-300.0f)
	{
		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"LeftLeaf", L"..\\Resources\\Image\\SkillData\\Leaf\\LeftLeaf.bmp");
		}

		//Collider* col = new Collider();
		////col->SetScale(Vector2(60.0f, 60.0f));
		//AddComponent(col);
		SetScale({ 0.5f, 0.5f });
		//col->SetScale(Vector2(150.0f, 300.0f));

		//Vector2 Pos = GetPos();
		//mLeafFlower = new LeafFlower();
		//mLeafFlower->SetPos(Vector2 ((Pos.x + 200.0f), Pos.y));
		
	}
	LeftLeaf::~LeftLeaf()
	{
	}
	void LeftLeaf::Tick()
	{
		GameObject::Tick();
		Translate(mSpeed);
	}
	void LeftLeaf::Render(HDC hdc)
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
	void LeftLeaf::OnCollisionEnter(Collider* other)
	{
		//Player* playerObj = dynamic_cast<Player*>(other->GetOwner());


		//mCol = true;
		
	}
}