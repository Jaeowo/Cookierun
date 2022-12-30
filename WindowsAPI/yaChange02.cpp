#include "yaChange02.h"
#include "yaCollider.h"
#include "yaAnimator.h"
#include "yaStage01.h"

namespace ya
{
	Change02::Change02(Vector2 pos)
		: mSpeed(-300.0f)
	{
		Collider* col = new Collider();
		col->SetPos(pos);
		col->SetScale(Vector2(900.0f, 1000.0f));
		//col->SetOffset(Vector2(50.0f, 55.0f));
		AddComponent(col);
		
		mStage01 = new Stage01();

	}
	Change02::Change02()
	{
	}
	Change02::~Change02()
	{
	}
	void Change02::Tick()
	{
		Translate(mSpeed);
		GameObject::Tick();
	}
	void Change02::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Change02::OnCollisionEnter(Collider* other)
	{
		//for (Stage01* stage01 : mStage01)
		//{
		//	if (stage01 == nullptr)
		//		continue;

		//	delete stage01;
		//	stage01 = nullptr;
		//}
	}
}
