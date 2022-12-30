#include "yaFinishSkill2.h"
#include "yaCollider.h"
#include "yaPlayer.h"

namespace ya
{
	FinishSkill2::FinishSkill2(Vector2 pos)
		:mSpeed(-300.0f)
	{
		Collider* col = new Collider();
		col->SetPos(pos);
		col->SetScale(Vector2(900.0f, 1000.0f));
		//col->SetOffset(Vector2(50.0f, 55.0f));
		AddComponent(col);
	}
	FinishSkill2::FinishSkill2()
	{
	}
	FinishSkill2::~FinishSkill2()
	{
	}
	void FinishSkill2::Tick()
	{
		Translate(mSpeed);
		GameObject::Tick();
	}
	void FinishSkill2::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void FinishSkill2::OnCollisionEnter(Collider* other)
	{
		//Rope02* rope2obj = dynamic_cast<Rope02*>(mTarget);
		//rope2obj->GetComponent<Animator>()->Play(L"Rope02Active", false);
	}
}
